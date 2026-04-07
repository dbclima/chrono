.PHONY: all clean

all:
	gcc -Wall -Werror ./src/chrono.c ./src/perf_metric.c -g -o ./bin/chrono.out

clean:
	rm ./bin/chrono.out
