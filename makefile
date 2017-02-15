SRCroot = $(wildcard *.cpp) $(wildcard *.h) 
SRC = $(SRCroot) $(wildcard Etats/*.cpp) $(wildcard Etats/*.h)


exe: $(SRC)
	g++ $(SRC) -o exe

clean:
	rm exe

test: 
	@echo $(SRC)