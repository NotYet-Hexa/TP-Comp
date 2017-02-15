SRCroot = $(wildcard *.cpp)
SRC = $(SRCroot) $(wildcard Etats/*.cpp)

exe: $(SRC)
	g++ $(SRC) -o exe