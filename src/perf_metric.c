#include "../include/perf_metric.h"

perf_metric_t parseMetric(char* metric)
{
	#define X(name, string)		if(strcmp(string, metric) == 0) return name;

	PERF_METRICS
	return INVALID_METRIC;

	#undef X
}
