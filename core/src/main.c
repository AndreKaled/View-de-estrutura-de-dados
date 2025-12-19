#include <stdio.h>
#include "lista.h"

int main(){
    Lista* l = criar_lista();
    inserir_inicio(l, 1);
    inserir_fim(l, 2);
    inserir_inicio(l, 3);

    char* json = lista_para_json(l);
    if(json){
        printf("%s\n", json);
        free(json);
    }

    destruir_lista(l);
    return 0;
}