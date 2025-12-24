#include "visual.h"
#include <stdio.h>

/** inicia o array JSON */
static void json_begin(Visual* v){
    (void)v;  // evita warning de parâmetro não usado
    printf("[");
}

/** imprime um elemento JSON */
static void json_elemento(Visual* v, int valor){
    static int primeiro = 1;
    if(!primeiro) printf(",");
    printf("{\"valor\": %d}", valor);
    primeiro = 0;
}

/** finaliza o array JSON */
static void json_end(Visual* v){
    printf("]\n");
}

/**
 * Função de fábrica do visualizador JSON.
 *
 * Retorna uma instância configurada
 * com callbacks específicos para JSON.
 */
Visual visual_json(){
    Visual v;
    v.begin = json_begin;
    v.elemento = json_elemento;
    v.end = json_end;
    v.ctx = NULL;
    return v;
}