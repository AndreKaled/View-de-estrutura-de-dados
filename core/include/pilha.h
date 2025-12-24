#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "visual.h"

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
 * Percorre a pilha do topo até a base e envia seus elementos
 * para um visualizador genérico.
 *
 * Esta função não sabe como os dados serão exibidos.
 * Ela apenas percorre a pilha e chama os callbacks definidos em `Visual`.
 *
 * Ordem de chamadas:
 *  1. v->begin(v)      (se existir)
 *  2. v->elemento(v, valor) para cada elemento da pilha
 *  3. v->end(v)        (se existir)
 *
 * A pilha é percorrida do topo para o fundo.
 *
 * @param pilha Ponteiro para a pilha a ser visualizada.
 * @param v     Ponteiro para um visualizador que implementa o contrato Visual.
 *
 * @note
 * - Se `pilha` ou `v` for NULL, a função não faz nada.
 * - Nenhuma alocação ou liberação de memória é realizada aqui.
 * - O formato da saída é responsabilidade exclusiva do visualizador.
 */
void pilha_visualizar(Pilha* pilha, Visual* v);
#endif