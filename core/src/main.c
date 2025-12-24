#include <stdio.h>
#include "lista.h"
#include "pilha.h"
#include "visual.h"
#include "visual_json.h"

int main(){
    Pilha* p = criar_pilha();
    empilhar(p,1);
    empilhar(p,2);
    empilhar(p,3);
    empilhar(p,4);

    Visual v = visual_json();
    pilha_visualizar(p, &v);

    destruir_pilha(p);

    // lista
    Lista* l = criar_lista();
    inserir_fim(l, 2);
    inserir_inicio(l, 1);
    inserir_fim(l, 3);
    inserir_fim(l, 4);
    lista_visualizar(l, &v);

    destruir_lista(l);

    return 0;
}