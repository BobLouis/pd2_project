solver: main.o sudoku.o
	g++ -o solver main.o sudoku.o

main.o: main.cpp sudoku.h
	g++ -c main.cpp

sudoku.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

clean: 
	rm *.o


