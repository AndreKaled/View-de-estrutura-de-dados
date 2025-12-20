#include <stdio.h>
#include "lista.h"
#include "pilha.h"

int main(){
    /**
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
    */

    Pilha* p = criar_pilha();
    empilhar(p,1);
    empilhar(p,2);
    empilhar(p,3);
    char* json = pilha_para_json(p);
    if(json){
        printf("%s\n", json);
        free(json);
    }
    int val;
    desempilhar(p, &val);
    printf("Desempilhando: %d\n", val);

    json = pilha_para_json(p);
    if(json){
        printf("%s\n", json);
        free(json);
    }

    destruir_pilha(p);

    return 0;
}