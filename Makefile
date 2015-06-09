make: main.c
	gcc -g main.c -o course

clean: course
	rm course
