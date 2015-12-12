hw4: main.o lex.yy.o
	cc -o hw4 main.o lex.yy.o

main.o: main.c hw4.h
	cc -c -g -DLEX main.c

lex.yy.o: lex.yy.c hw4.h
	cc -c -g lex.yy.c

lex.yy.c: hw4.l
	flex hw4.l
