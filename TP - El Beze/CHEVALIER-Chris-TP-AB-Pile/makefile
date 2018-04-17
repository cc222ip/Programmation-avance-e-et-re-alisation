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
main : main.cpp ABPile.h ABPile.o
	$(CC) -o $@ ABPile.o main.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

ABPile.o : ABPile.cpp ABPile.h
	$(CC) -c ABPile.cpp $(CFLAG) $(DEBUG) $(MODEOPTIM)

# Nettoyage
clean :
	rm -f *.o

mrproper : clean
	rm -f main
