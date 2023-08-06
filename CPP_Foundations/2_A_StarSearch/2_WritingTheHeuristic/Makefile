CXX=g++
CXXFLAGS=-std=c++2a -g -Wall
SRC=src
OBJ=obj
BIN=bin
INC=inc
TARGET=$(BIN)/main.elf

SOURCES:=$(wildcard $(SRC)/*.cpp)
OBJECTS:=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

$(OBJ)/%.o:$(SRC)/%.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -I $(INC) -c $< -o $@

$(OBJ):
	mkdir $(OBJ)

clean:
	$(RM) -rf $(TARGET) $(OBJ)