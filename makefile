CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=exe

SRCCPP = Automate.cpp Etat.cpp Expression.cpp Lexer.cpp main.cpp Symbole.cpp Etats/*.cpp
SRCH = Automate.h Etat.h Expression.h Lexer.h Constante.h Symbole.h Etats/*.h
SRC = $(SRCH) $(SRCCPP)
OBJ= $(SRCCPP:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) -D DEBUG

%.o: SRC
	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)