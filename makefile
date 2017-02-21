CC=g++
CFLAGS=-std=c++11 -D DEBUG
LDFLAGS=-std=c++11 -D DEBUG
EXEC=exe

SRCCPP = Automate.cpp Etat.cpp Expression.cpp Lexer.cpp main.cpp Symbole.cpp 
SRCCPP_ETAT = $(wildcard Etats/*.cpp)
SRCH = Automate.h Etat.h Expression.h Lexer.h Constante.h Symbole.h
SRCH_ETAT = $(wildcard Etats/*.h)
SRC = $(SRCH) $(SRCH_ETAT) $(SRCCPP) $(SRCCPP_ETAT)
OBJ = $(SRCCPP_ETAT:Etats/%.cpp=%.o) $(SRCCPP:.cpp=.o)
# OBJ= $(SRCCPP:.cpp=.o)


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.cpp %.h
	$(CC) -c $(CFLAGS) $< 

%.o: Etats/%.cpp Etats/%.h
	$(CC) -c $(CFLAGS) $< 

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< 	

clean:
	rm -rf *.o exe

mrproper: clean
	rm -rf $(EXEC)
