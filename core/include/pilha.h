#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PilhaNo{
    int valor;
    struct PilhaNo* prox;
} PilhaNo;

typedef struct Pilha{
    int tam;
    PilhaNo* topo;
} Pilha;

/**
 * Cria uma pilha vazia.
 * 
 * @return Ponteiro para a pilha alocada dinâmicamente,
 * ou NULL em caso de falha de alocação.
 * 
 * Responsabilidade do chamador liberar a memória usando
 * destruir_pilha().
 */
Pilha* criar_pilha();

/**
 * Libera todos os nós da pilha e a própria pilha.
 *
 * @param pilha Ponteiro para a pilha a ser destruida.
 */
void destruir_pilha(Pilha* pilha);

/**
 * Adiciona um elemento no topo da pilha.
 * @param pilha Ponteiro para a pilha.
 * @param valor Valor a ser empilhado.
 *
 * @return 1 em caso de sucesso, 0 em caso de erro.
 */
int empilhar(Pilha* pilha, int valor);

/**
 * Remove o elemento do topo da pilha.
 *
 * @param pilha Ponteiro para a pilha.
 * @param valor Ponteiro para armazenar o valor removido (opcional, pode ser NULL).
 *
 * @return 1 em caso de sucesso, 0 em caso de erro (pilha vazia ou NULL).
 */
int desempilhar(Pilha* pilha, int* valor);

/**
 * Retorna o valor do topo da pilha sem remover.
 *
 * @param pilha Ponteiro para a pilha.
 * @param valor Endereço para onde vai o valor do topo na pilha
 *
 * @return 1 caso sucesso, 0 caso pilha vazia ou nula.
 */
int topo(Pilha* pilha, int* valor);

/**
 * Verifica se a pilha está vazia.
 *
 * @param pilha Ponteiro para a pilha.
 *
 * @return 1 se estiver vazia, 0 caso contrário.
 */
int pilha_vazia(Pilha* pilha);

/**
 * Retorna o tamanho da pilha.
 *
 * @param pilha Ponteiro para a pilha.
 *
 * @return Número de elementos na pilha.
 */
int tamanho_pilha(Pilha* pilha);

/**
 * Gera uma representação da pilha em formato JSON.
 *
 * @param pilha Ponteiro para a pilha.
 *
 * @return String JSON alocada dinamicamente.
 *         Responsabilidade do chamador liberar a memória.
 */
char* pilha_para_json(Pilha* pilha);
#endif