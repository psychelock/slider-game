CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -ggdb

SRC = $(wildcard src/*.cc)
OBJ = $(SRC: *.cc = *.o)
EXEC = game

.PHONY: all clean

all: $(SRC) $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

