#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ListaNo{
    int valor;
    struct ListaNo* prox;
} ListaNo;

typedef struct Lista{
    ListaNo* inicio;
    int tam;
} Lista;

/**
 * Cria uma lista encadeada vazia.
 *
 * @return Ponteiro para Lista alocada dinamicamente,
 *         ou NULL em caso de falha de alocação.
 *
 * Responsabilidade do chamador liberar a memória
 * usando destruir_lista().
 */

Lista* criar_lista();

/**
 * Libera toda a memória associada a uma lista encadeada.
 *
 * Percorre a lista, liberando cada nó individualmente,
 * e ao final libera a própria estrutura da lista.
 *
 * @param lista Ponteiro para a lista a ser destruída.
 *              Se NULL, a função não realiza nenhuma ação.
 *
 * Após a chamada, o ponteiro passado torna-se inválido
 * e não deve mais ser utilizado.
 */
void destruir_lista(Lista* lista);

/**
 * Insere um valor no início da lista encadeada
 *
 * @param lista Ponteiro para a lista.
 * @param valor Valor a ser inserido.
 * @return Status da inserção, 0 para erro e 1 para ok
 *
 * A lista deve ter sido criado previamente.
 */
int inserir_inicio(Lista* lista, int valor);

/**
 * Insere um valor no final da lista encadeada
 *
 * @param lista Ponteiro para a lista.
 * @param valor Valor a ser inserido.
 * @return Status da inserção, 0 para erro e 1 para ok
 *
 * Percorre a lista até o último nó para realizar a inserção.
 */
int inserir_fim(Lista* lista, int valor);

/**
 * Remove e retorna o valor do primeiro elemento da lista.
 *
 * @param lista Ponteiro para a lista.
 *
 * @return Valor removido, se ok == 1, se a lista estiver vazia ou
 * NULL == 0.
 */
int remover_inicio(Lista* lista);

/**
 * Remove e retorna o valor do último elemento da lista.
 *
 * @param lista Ponteiro para a lista.
 *
 * @return Valor removido, se ok == 1, se a lista estiver vazia ou
 * NULL == 0.
 */
int remover_fim(Lista* lista);

/**
 * Busca um valor na lista encadeada.
 *
 * @param lista Ponteiro para a lista.
 * @param valor Valor a ser buscado.
 *
 * @return Ponteiro para o nó que contém o valor,
 *         ou NULL caso não seja encontrado.
 */
ListaNo* buscar_valor(Lista* lista, int valor);

/**
 * Retorna a quantidade de elementos da lista.
 *
 * @param lista Ponteiro para a lista.
 *
 * @return Número de elementos armazenados na lista,
 *         ou 0 se a lista for NULL.
 */
int tamanho_lista(Lista* lista);

/**
 * Verifica se a lista encadeada está vazia.
 *
 * @param lista Ponteiro para a lista.
 *
 * @return 1 se a lista estiver vazia,
 *         0 caso contrário.
 */
int lista_vazia(Lista* lista);

/**
 * Gera uma representação da lista encadeada em formato JSON.
 *
 * O JSON contém os nós e suas ligações
 *
 * @param lista Ponteiro para a lista.
 *
 * @return String JSON alocada dinamicamente,
 *         cuja liberação é responsabilidade do chamador.
 */
char* lista_para_json(Lista* lista);

#endif