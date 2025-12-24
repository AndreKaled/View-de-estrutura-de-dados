#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "visual.h"
#include "visual_json.h"

int main(int argc, char** argv){
    Visual v = visual_json();
    Pilha* p = criar_pilha();

    for(int i = 1; i < argc; i++){
        int valor = atoi(argv[i]);
        empilhar(p, valor);
    }

    pilha_visualizar(p, &v);
    destruir_pilha(p);

    return 0;
}