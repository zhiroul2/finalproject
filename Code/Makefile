
# Executable names:
EXE = main
TEST = test

# objects
# Add all object files needed for compiling:
EXE_OBJ = main.o 
OBJS = main.o 


CXXFlAGS = $(cs225) -std=c+=14-stdlibc++ -c -g -O0 -Wall -Wextra -pedantic

#include make/customClangEnforcement.mk


all : $(EXE)

$(EXE) : $(OBJS) 
	clang++ $(OBJS) -std=c++14 -stdlib=libc++ -lc++abi -lm -o $(EXE)

# Use the cs225 makefile template:
include cs225.mk

$(EXE) : $(TEST) 
	clang++ $(OBJS) -std=c++14 -stdlib=libc++ -lc++abi -lm -o $(EXE)




