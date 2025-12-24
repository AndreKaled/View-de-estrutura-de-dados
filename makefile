# --- Configurações ---
CC       = gcc
CFLAGS   = -Wall -Wextra -Icore/include -g
SRC_CORE = core/src/lista.c core/src/pilha.c core/src/visual_json.c

IMAGE      = visualizador-estruturas
DEV_IMAGE  = visualizador-dev

# --- Detecta automaticamente todos os mains ---
MAINS     := $(wildcard core/src/main_*.c)
TARGETS   := $(patsubst core/src/main_%.c,app_%,$(MAINS))

.PHONY: all clean docker run run_docker dev_image dev_docker shell_docker

# --- Alvo padrão: compila todos os mains ---
all: $(TARGETS)

# --- Regra genérica para compilar cada main ---
# main_lista.c -> app_lista
$(TARGETS): app_%: core/src/main_%.c $(SRC_CORE)
	$(CC) $(CFLAGS) $^ -o $@

# --- Limpar build ---
clean:
	rm -f $(TARGETS) *.o

# --- Build da imagem FINAL (prod) ---
docker:
	docker build -t $(IMAGE) .

# --- Executar app local (por padrão pega o primeiro main detectado) ---
run: all
	./$(firstword $(TARGETS))

# --- Executar app da imagem FINAL ---
run_docker:
	docker run --rm -it $(IMAGE)

# --- Build da imagem de DEV ---
dev_image:
	docker build -f dockerfile.dev -t $(DEV_IMAGE) .

# --- Rodar container de DEV com bind mount e executar um main específico ---
dev_docker: dev_image
	docker run --rm -it \
		-v $(PWD):/app \
		-w /app \
		$(DEV_IMAGE) \
		bash -c "make all && ./$(firstword $(TARGETS))"

# --- Abrir shell no container de DEV ---
shell_docker: dev_image
	docker run --rm -it \
		-v $(PWD):/app \
		-w /app \
		$(DEV_IMAGE) \
		/bin/bash

run_api_docker:
	docker run --rm -it \
		-v $(PWD):/app \
		-w /app \
		$(DEV_IMAGE) \
		python3 api/app.py