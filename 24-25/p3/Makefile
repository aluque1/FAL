# Makefile for compiling sol.cpp

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = sol

# Source file
SRC = sol.cpp

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up
clean:
	rm -f $(TARGET)