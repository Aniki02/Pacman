CC = g++
CFLAGS = -Wall -Wno-unknown-pragmas -std=c++11
CFLAGS += $(shell pkg-config --cflags sfml-all)
LDFLAGS = $(shell pkg-config --libs sfml-all)
SRC = src
OBJ = obj
BIN = bin
EXEC = play
POINT_C = $(wildcard $(SRC)/*.cpp)
POINT_O = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(POINT_C))


# recette: ingredient(s)
# $< prend le premier ingrédient de la recette
# $@ prend le nom de la recette
# $^ prent tout les ingredients
# @commande ... masque la commande

all: $(EXEC)

$(EXEC): $(OBJ)/main.o $(POINT_O)	
	$(CC) $^ -o $(BIN)/$(EXEC) $(LDFLAGS)

$(OBJ)/main.o: $(SRC)/main.cpp 
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ)/*.o

mrproper: clean
	rm -rf $(BIN)/$(EXEC)

run: all 
	@./$(BIN)/$(EXEC)
