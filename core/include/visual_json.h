#ifndef VISUAL_JSON_H
#define VISUAL_JSON_H

#include "visual.h"

/**
 * Cria um visualizador JSON.
 *
 * A saída gerada segue o formato:
 *
 * [
 *   {"valor": X},
 *   {"valor": Y},
 *   ...
 * ]
 *
 * @return Estrutura Visual pronta para uso.
 *
 * Observação:
 *  - A saída atual é escrita em stdout.
 *  - Futuramente, pode usar `ctx` para redirecionar para arquivos,
 *    sockets ou buffers de memória.
 */
Visual visual_json();

#endif 