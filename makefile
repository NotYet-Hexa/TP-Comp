CC=g++
CFLAGS=-std=c++11 -g -O0 -D DEBUG
LDFLAGS=-std=c++11 -g -O0 -D DEBUG
EXEC=exe


SRCCPP = Automate.cpp Etat.cpp Expression.cpp Lexer.cpp main.cpp Symbole.cpp 
SRCCPP_ETAT = $(wildcard Etats/*.cpp)
SRCH = Automate.h Etat.h Expression.h Lexer.h Constante.h Symbole.h
SRCH_ETAT = $(wildcard Etats/*.h)
SRC = $(SRCH) $(SRCH_ETAT) $(SRCCPP) $(SRCCPP_ETAT)
OBJ = $(SRCCPP:.cpp=.o) $(SRCCPP_ETAT:Etats/%.cpp=%.o) 
# OBJ= $(SRCCPP:.cpp=.o)


all: $(EXEC)

$(EXEC): $(OBJ) $(SRC)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# file in current folder
%.o: %.cpp %.h
	$(CC) -c $(CFLAGS) $< 


# file in Etats folder
%.o: Etats/%.cpp Etats/%.h
	$(CC) -c $(CFLAGS) $< 

# main
%.o: %.cpp
	$(CC) -c $(CFLAGS) $< 	

clean:
	rm -rf *.o $(EXEC) Etats/*.o

