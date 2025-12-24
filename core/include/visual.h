/**
 * Interface genérica de visualização de estruturas de dados.
 *
 * Este arquivo define um *contrato mínimo* para percorrer uma estrutura
 * (lista, pilha, árvore, grafo, etc.) e produzir uma saída visual,
 * sem que a estrutura conheça o formato dessa saída.
 *
 * A estrutura de dados:
 *  - NÃO sabe se o destino é JSON, texto, HTML, terminal ou rede.
 *  - APENAS chama callbacks padronizados.
 *
 * A visualização:
 *  - Decide como representar cada elemento.
 *  - Pode manter estado interno via `ctx`.
 *
 * Esse modelo desacopla completamente:
 *   lógica da estrutura  <->  forma de visualização.
 */

#ifndef VISUAL_H
#define VISUAL_H

typedef struct Visual Visual;

/**
 * Estrutura que define o contrato de visualização.
 *
 * Cada função é opcional (pode ser NULL).
 * A estrutura de dados deve apenas chamá-las, sem assumir comportamento.
 */
struct Visual{
    /**
     * Chamada antes do primeiro elemento.
     * Usada para inicializar a saída (ex: abrir colchetes, tags, cabeçalhos).
     */
    void (*begin)(Visual*);

    /**
     * Chamada para cada elemento da estrutura.
     *
     * @param v     visualizador ativo
     * @param valor valor lógico do elemento
     *
     * Observação:
     *  - Hoje recebe apenas `int`.
     *  - Pode evoluir para ponteiros genéricos no futuro.
     */
    void (*elemento)(Visual*, int valor);

    /**
     * Chamada após o último elemento.
     * Usada para finalizar a saída (ex: fechar colchetes, tags, flush).
     */
    void (*end)(Visual*);

    /**
     * Contexto opcional para estado interno da visualização.
     * Pode armazenar:
     *  - FILE*
     *  - buffers
     *  - flags
     *  - contadores
     *  - qualquer dado necessário
     */
    void* ctx;
};

#endif