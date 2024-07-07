#input dirs
SRC = src
GLOBAL = src/global


#input files
INPUTS = $(SRC)/main.cpp $(SRC)/draw.cpp  $(SRC)/threed.cpp
GLOBALS = $(GLOBAL)/globals.cpp $(GLOBAL)/colors.cpp $(GLOBAL)/SDLinit.cpp

#tools
CXX = clang++

#flags
SDLCFLAGS := $(shell sdl2-config --cflags)
SDLLIBS := $(shell sdl2-config --libs)

CXXFLAGS = -std=c++23 
#output file
TARGET = foo.elf


all:
	$(CXX) $(CXXFLAGS) $(SDLCFLAGS) $(INPUTS) $(GLOBALS) $(SDLLIBS) -o $(TARGET)

run: 
	./$(TARGET)

clean:
	rm -f ./$(TARGET) 


