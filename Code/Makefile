
# Executable names:
EXE = main
TEST = test

# objects
# Add all object files needed for compiling:
EXE_OBJ = main.o 
OBJS = main.o data_correction.o road_network.o cs225/HSLAPixel.o cs225/PNG.o cs225/lodepng/lodepng.o


CXXFlAGS = $(cs225) -std=c+=14-stdlibc++ -c -g -O0 -Wall -Wextra -pedantic

#include make/customClangEnforcement.mk


all : $(EXE)
$(EXE) : $(OBJS) 
	clang++ $(OBJS) -std=c++14 -stdlib=libc++ -lc++abi -lm -o $(EXE)

# Use the cs225 makefile template:
include cs225.mk
# MP-specific targets

# MP-specific targets
DSETS_OBJS = tests/dataTest.o
#DSETS_OBJS += dsets.o

TEST: $(DSETS_OBJS)
	$(LD) $^ $(LDFLAGS) -o $@
$(EXE) : $(TEST) 
	clang++ $(OBJS) -std=c++14 -stdlib=libc++ -lc++abi -lm -o $(EXE)





