# --- Stage 1: Build ---
FROM ubuntu:22.04 AS builder

# Diretório de trabalho
WORKDIR /app

# Instala GCC e dependências de build
RUN apt-get update && \
    apt-get install -y gcc build-essential && \
    rm -rf /var/lib/apt/lists/*

# Copia código fonte
COPY . .

# Compila o executável
RUN make all

# --- Stage 2: Runtime minimal ---
FROM ubuntu:22.04

WORKDIR /app

# Copia apenas o executável do stage anterior
COPY --from=builder /app/app .

# Instala Python apenas se precisar do backend para JSON ou testes
RUN apt-get update && \
    apt-get install -y python3 python3-pip && \
    rm -rf /var/lib/apt/lists/*

# Define executável como entrypoint
ENTRYPOINT ["./app"]

# Para rodar interativamente
# CMD ["/bin/bash"]
