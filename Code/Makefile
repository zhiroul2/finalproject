
# Executable names:
EXE = main
TEST = test

# objects
OBJS = main.o data_correction.o

CXX = clang++

CXXFlAGS = $(cs225) -std=c+=14-stdlibc++ -c -g -O0 -Wall -Wextra -pedantic

#include make/customClangEnforcement.mk


all : $(EXE)

$(EXE) : $(OBJS) 
	clang++ $(OBJS) -std=c++14 -stdlib=libc++ -lc++abi -lm -o $(EXE)

# Use the cs225 makefile template:
include cs225.mk

data_correction.o : data_correction.cpp
	$(CXX) $(CXXFLAGS) data_correction.cpp

test : data_correction.cpp cs225/catch/catchmain.cpp tests/dataTest.cpp
	clang++ data_correction.cpp cs225/catch/catchmain.cpp tests/dataTest.cpp -std=c++14 -stdlib=libc++ -lc++abi -lm -o test

