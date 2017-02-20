SRCroot = $(wildcard *.cpp) $(wildcard *.h) 
SRC = $(SRCroot) $(wildcard Etats/*.cpp) $(wildcard Etats/*.h)


exe: $(SRC)
	g++ $(SRC) -o exe

	rm *.o
clean:
	rm exe

test: 
	@echo $(SRC)