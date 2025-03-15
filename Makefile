CXX = g++
CXXFLAGS = -Wall -std=c++20
CXXDEBUGFLAGS = -ggdb -fsanitize=address

SRC     := src
INCLUDE := include
LIB     := lib
OBJECTS := obj
BIN     := bin
EXECUTABLE := $(BIN)/main

.PHONY: all run debug clean fresh test startGame

all: directories $(EXECUTABLE)

# Create necessary directories
directories:
	@mkdir -p $(BIN) $(OBJECTS)

$(EXECUTABLE): $(SRC)/*.cpp
	@echo "🔧 Building..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $@

run: clean all
	@clear
	@echo "🚀 Executing..."
	@./$(EXECUTABLE)

startGame: all
	@clear
	@echo "🎮 Starting game..."
	@./$(EXECUTABLE)

test:

debug: CXXFLAGS += $(CXXDEBUGFLAGS)
debug: fresh all
	@echo "🔍 Debug build complete!"

clean:
	@echo "🧹 Clearing..."
	-rm -f $(EXECUTABLE)

fresh: clean
	@echo "🧼 Deep cleaning..."
	-rm -rf $(BIN) $(OBJECTS)