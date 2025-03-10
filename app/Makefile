CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2

OUTDIR = dist

SRC = src/main.cpp src/substitution.cpp src/transposition.cpp
OBJ = $(patsubst %.cpp,$(OUTDIR)/%.o,$(SRC))
BIN = $(OUTDIR)/app

.SILENT:

all: 
	echo "Building app..."
	$(MAKE) $(BIN)

$(OUTDIR)/%.o: %.cpp
	echo "Compiling $<..."
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I include -c $< -o $@

$(BIN): $(OBJ)
	echo "Linking exe $(BIN)..."
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(BIN) $(OBJ)
	echo "Build finished succesfully!"

clean:
	echo "Deleting dir $(OUTDIR)..."
	rm -rf $(OUTDIR)
	echo "Succesfully cleaned !"

.PHONY: all clean