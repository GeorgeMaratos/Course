make: main.c
	gcc -g main.c -o course -lm

clean: course
	rm course
