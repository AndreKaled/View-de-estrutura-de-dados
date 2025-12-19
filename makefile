# Makefile básico para projeto de estruturas de dados

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
LDFLAGS = 

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/lista.c $(SRC_DIR)/pilha.c
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

TARGET = app

# Cria a pasta build se não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Regra principal
all: $(BUILD_DIR) $(TARGET)

# Compila objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Linka objetos
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

# Limpar arquivos compilados
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Executar programa
run: $(TARGET)
	./$(TARGET)
