#input dirs
SRC = src


#input files
INPUTS = $(SRC)/main.cpp $(SRC)/draw.cpp $(SRC)/globals.cpp $(SRC)/colors.cpp

#tools
CXX = clang++

#flags
SDLCFLAGS := $(shell sdl2-config --cflags)
SDLLIBS := $(shell sdl2-config --libs)

CXXFLAGS = -std=c++23
#output file
TARGET = foo.elf


all:
	$(CXX) $(CXXFLAGS) $(SDLCFLAGS) -o $(TARGET) $(INPUTS) $(SDLLIBS)

run: 
	./$(TARGET)

clean:
	rm -f ./$(TARGET) 


