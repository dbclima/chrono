#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <getopt.h>

#include "../include/status.h"

#define PERF_METRICS	\
	X(MEAN, "mean") \
	X(MIN , "min" ) \
	X(MAX , "max" ) \
	X(SUM , "sum" )

typedef enum
{
	#define X(name, string) 	name,
	
	PERF_METRICS
	INVALID_METRIC

	#undef X
}
perf_metric_t;

perf_metric_t parseMetric(char* metric)
{
	#define X(name, string)		if(strcmp(string, metric) == 0) return name;

	PERF_METRICS
	return INVALID_METRIC;

	#undef X
}

// #define X(chr, str, arg_rule, hint)
#define OPT_TABLE \
	X('h', "help"	      , no_argument	  , "Displays this menu\n")	\
	X('n', "n-iterations" , required_argument , "Sets number of iterations")  \
	X('m', "perf-metric"  , required_argument , "Sets the performance metric")

#define DFT_N_ITERATIONS	1
#define DFT_PERF_METRIC		MEAN

void print_help()
{
	puts("cli options:");

	#define X(chr, str, arg_rule, hint)				       \
		printf("  -%c | --%10s : %s\n", chr, str, hint);		       \
		puts("");

	OPT_TABLE

	#undef X
}


int main(int argc, char** argv)
{
	int n_iterations = DFT_N_ITERATIONS;
	perf_metric_t metric = DFT_PERF_METRIC;

	#define X(chr, str, arg_rule, hint)			       \
		{str, arg_rule, NULL, chr},

	struct option long_opts[] = {
		OPT_TABLE
	};

	#undef X

	#define X(chr, str, arg_rule, hint)				       \
		chr,

	char short_opts[] = {
		OPT_TABLE '\0'
	};

	#undef X

	int opt;
	while ((opt = getopt_long(argc, argv, short_opts, long_opts, NULL)) != -1)
	{
		switch(opt)
		{
			case 'h':
				print_help();
				break;

			case 'n':
				n_iterations = atoi(optarg);

				if (n_iterations <= 0)
				{
					puts("Invalid [n | n-iterations] parameter");
					exit(OK);
				}

				break;

			case 'm':
				metric = parseMetric(optarg);
				
				if (metric == INVALID_METRIC)
				{
					puts("Invalid [m | perf-metric] parameter"
	  				     "should be [ mean | max | min | sum ]");
				}
				
				break;
			
			case '?':
				puts("Invalid parameter");
				print_help();

			
				
				
				
				
		}
	}

	return OK;
}
