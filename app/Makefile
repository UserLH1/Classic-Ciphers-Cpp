CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2

# Define output directory
OUTDIR = dist

SRC = src/main.cpp src/substitution.cpp src/transposition.cpp
# Put object files in output directory
OBJ = $(patsubst %.cpp,$(OUTDIR)/%.o,$(SRC))
BIN = $(OUTDIR)/app

all: $(BIN)

# Rule for object files - ensures directories are created
$(OUTDIR)/%.o: %.cpp
    @mkdir -p $(@D)
    $(CXX) $(CXXFLAGS) -I include -c $< -o $@

# Link rule
$(BIN): $(OBJ)
    @mkdir -p $(@D)
    $(CXX) $(CXXFLAGS) -o $(BIN) $(OBJ)

clean:
    rm -rf $(OUTDIR)