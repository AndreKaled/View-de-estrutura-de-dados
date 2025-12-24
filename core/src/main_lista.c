#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "visual.h"
#include "visual_json.h"

int main(int argc, char** argv){
    Visual v = visual_json();

    Lista* l = criar_lista();
    for(int i = 1; i < argc; i++){
        int valor = atoi(argv[i]);
        inserir_inicio(l, valor);
    }

    lista_visualizar(l, &v);
    destruir_lista(l);
    
    return 0;
}