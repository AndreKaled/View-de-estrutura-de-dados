TARGET = app
IMAGE  = visualizador-estruturas
DEV_IMAGE = visualizador-dev

# Fonte C e objetos
SRC = core/src/main.c core/src/lista.c core/src/pilha.c core/src/visual_json.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Icore/include -g

.PHONY: all clean docker run run_docker dev_image dev_docker shell_docker

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

# --- Build da imagem FINAL (prod) ---
docker:
	docker build -t $(IMAGE) .

# --- Executar app local ---
run:
	./$(TARGET)

# --- Executar app da imagem FINAL ---
run_docker:
	docker run --rm -it $(IMAGE)

# --- Build da imagem de DEV ---
dev_image:
	docker build -f dockerfile.dev -t $(DEV_IMAGE) .

# --- Rodar container de DEV com bind mount ---
dev_docker: dev_image
	docker run --rm -it \
		-v $(PWD):/app \
		-w /app \
		$(DEV_IMAGE) \
		bash -c "make all && ./$(TARGET)"

# --- Abrir shell no container de DEV ---
shell_docker: dev_image
	docker run --rm -it \
		-v $(PWD):/app \
		-w /app \
		$(DEV_IMAGE) \
		/bin/bash
