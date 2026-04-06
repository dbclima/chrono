.PHONY: all clean

all:
	gcc -Wall -Werror ./src/chrono.c -o ./bin/chrono.out

clean:
	rm ./bin/chrono.out
