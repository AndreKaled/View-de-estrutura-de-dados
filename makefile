TARGET = app
IMAGE  = visualizador-estruturas

# Fonte C e objetos
SRC = core/src/main.c core/src/lista.c core/src/pilha.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Icore/include -g

.PHONY: all clean docker run run_docker

# --- Alvo padrão ---
all: $(TARGET)

# --- Compila executável ---
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# --- Compila arquivos .o ---
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# --- Limpar build ---
clean:
	rm -f $(OBJ) $(TARGET)

# --- Criar imagem Docker ---
docker:
	docker build -t $(IMAGE) .

# --- Executar app local ---
run:
	./$(TARGET)

# --- Executar app dentro do container ---
run_docker:
	docker run --rm -it $(IMAGE)