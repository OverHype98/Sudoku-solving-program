all : Sudoku
Sudoku: main.o functions.o
	gcc main.o functions.o -o Sudoku


main.o: main.c
	gcc -c main.c
functions.o : functions.c
	gcc -c functions.c
clean :
	rm *o Sudoku

