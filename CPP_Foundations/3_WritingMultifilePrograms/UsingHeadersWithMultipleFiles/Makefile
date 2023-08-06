CXX=g++
CXXFLAGS=-std=c++2a -g -Wall
SRC=src
INC=inc
OBJ=obj
BIN=bin
TARGET=$(BIN)/main.elf

SOURCES:=$(wildcard $(SRC)/*.cpp)
OBJECTS:=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))

all:$(TARGET)

$(TARGET):$(OBJECTS) $(BIN)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

$(OBJ)/%.o:$(SRC)/%.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -I $(INC) -c $< -o $@

$(BIN):
	mkdir $(BIN)

$(OBJ):
	mkdir $(OBJ)

clean:
	$(RM) -rf $(OBJ) $(TARGET)