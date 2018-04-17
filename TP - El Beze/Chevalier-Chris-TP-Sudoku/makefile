# Variables
CC = g++
CFLAG = -Wall -pedantic
DEBUG = -g

# optimisation
# utiliser make OPTIM='oui' pour optimisation
# ou make OPTIM='oui' -f makefile

ifeq ($(OPTIM),oui)
	MODEOPTIM = -O
else
	MODEOPTIM =
endif

# Programme :
main : main.cpp sudoku.h sudoku.o
	$(CC) -o $@ sudoku.o main.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

sudoku.o : sudoku.cpp sudoku.h
	$(CC) -c sudoku.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

# Nettoyage
clean :
	rm -f *.o

mrproper : clean
	rm -f main
