#ifndef PERF_METRIC_H
#define PERF_METRIC_H

#include <string.h>

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

#define DFT_PERF_METRIC		MEAN

perf_metric_t parseMetric(char* metric);

#endif
