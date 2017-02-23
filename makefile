.PHONY : all debug
REMOVE = rm -f
CC = g++
DEBUG_FLAG = -g -O0 -D DEBUG
CFLAGS = -std=c++11
LDFLAGS = -std=c++11
EXEC = exe

SRCCPP = Automate.cpp Etat.cpp Expression.cpp Lexer.cpp main.cpp Symbole.cpp 
SRCCPP_ETAT = $(wildcard Etats/*.cpp)
SRCH = Automate.h Etat.h Expression.h Lexer.h Constante.h Symbole.h
SRCH_ETAT = $(wildcard Etats/*.h)
SRC = $(SRCH) $(SRCH_ETAT) $(SRCCPP) $(SRCCPP_ETAT)
OBJ = $(SRCCPP:.cpp=.o) $(SRCCPP_ETAT:Etats/%.cpp=%.o)

DEBUGFILE = .debug
CLEANFILES = $(EXEC) $(DEBUGFILE) *.o

# if last was debug recompile
all: testall $(EXEC)
testall:
	@test -f $(DEBUGFILE) && $(REMOVE) $(CLEANFILES) || echo "Last compilation was release mode"


debug: testdebug $(EXEC)
testdebug:
	$(eval CFLAGS += $(DEBUG_FLAG))
	$(eval LDFLAGS += $(DEBUG_FLAG))
	@test -f $(DEBUGFILE) && echo "Last compilation was debug mode" || $(REMOVE) $(CLEANFILES)
	@echo "Last compilation was debug mode" > $(DEBUGFILE)

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
	$(REMOVE) $(CLEANFILES)

FORCE: