SRCroot = $(wildcard *.cpp) $(wildcard *.h) 
SRC = $(SRCroot) $(wildcard Etats/*.cpp) $(wildcard Etats/*.h)


exe: $(SRC)
	g++ $(SRC) -o exe

clean:
	rm exe
	rm *.o

test: 
	@echo $(SRC)