# Jonathan Buch CS 270 Assignment #5 November 10th, 2015

files = main.o bubblesort.o insertionsort.o quicksort.o
CC = gcc


program: ${files}
	${CC} -o prog5 ${files}

main.o: main.c
	${CC} -c main.c

bubblesort.o: bubblesort.c
	${CC} -c bubblesort.c

insertionsort.o: insertionsort.c
	${CC} -c insertionsort.c

quicksort.o: quicksort.c
	${CC} -c quicksort.c

clean:
	rm -f ${files} core prog5
