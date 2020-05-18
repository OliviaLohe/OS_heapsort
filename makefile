all : heap.o  main.c
		gcc -Wall -o employees main.c heap.o 

heap.o: heap.h heap.c
		gcc -Wall -c heap.c

clean:
		rm -f *.o employees	