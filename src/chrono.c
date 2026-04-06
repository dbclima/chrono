#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <getopt.h>

#include "../include/status.h"

// #define Y(enum, string)
#define PERF_METRIC_TABLE   	\
	Y(MIN , "min") 		\
	Y(MAX , "max") 		\
	Y(MEAN, "mean")		\
	Y(SUM , "sum")		\

// #define X(alias, default, description)
#define OPT_TABLE \
	X("h", NULL  , "Displays this menu\n") \
	X("v", NULL  , "Display Logging information to the user about excecution") \
	X("n", "1"   , "Sets number of iterations to execute the target command") \
	X("m", "mean", "Sets the metric for performance measurements among iterations") \


typedef enum
{
	#define Y(enum, string) enum,
	PERF_METRIC_TABLE
	#undef Y
}
perf_metric_t;

void print_metric(perf_metric_t metric)
{
	switch (metric)
	{
		#define Y(name, string) case name: printf("[LOG] Current Metric =  %s\n", string); break;
		PERF_METRIC_TABLE
		#undef Y
	}
}



static int flag_verbose = 0;

int main(int argc, char** argv)
{
	int opt;


	while ((opt = getopt(argc, argv, "n:h")) != -1)
	{
		printf("%c %d \n", opt, opt);
		switch(opt)
		{
			case 'n':
				printf("%s\n", optarg);
				break;

			case 'h':
				printf("Help command");
				break;

			default:
				printf("Opcao desconhecida %c", opt);
		}

	}

	return OK;
}
