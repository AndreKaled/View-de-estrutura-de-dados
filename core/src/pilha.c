#include "pilha.h"
#define PILHA_ERRO 0
#define PILHA_OK   1

Pilha* criar_pilha(){
    //aloca espaço para a pilha
    Pilha* p = malloc(sizeof(Pilha));

    //se falhou retorna nulo
    if(p == NULL) return NULL;

    //pilha inicia vazia
    p->tam = 0;
    p->topo = NULL;
    return p;
}

void destruir_pilha(Pilha* pilha){
    if(pilha == NULL) return;

    PilhaNo* atual = pilha->topo;
    PilhaNo* prox;

    //anda pela pilha do topo ao fundo liberando espaço
    while(atual){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    //libera a pilha
    free(pilha);
}

int empilhar(Pilha* pilha, int valor){
    if(pilha == NULL) return PILHA_ERRO;
    
    PilhaNo* novo = malloc(sizeof(PilhaNo));
    if(novo == NULL) return PILHA_ERRO;

    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tam++;

    return PILHA_OK;
}

int desempilhar(Pilha* pilha, int* valor){
    if(pilha == NULL) return PILHA_ERRO;
    if(pilha->topo == NULL) return PILHA_ERRO;

    PilhaNo* tmp = pilha->topo;
    *valor = tmp->valor;
    pilha->topo = tmp->prox;
    pilha->tam--;
    free(tmp);
    return PILHA_OK;
}

int topo(Pilha* pilha, int* valor){
    if(pilha == NULL) return PILHA_ERRO;
    if(pilha->topo == NULL) return PILHA_ERRO;

    *valor = pilha->topo->valor;
    return PILHA_OK;
}

int pilha_vazia(Pilha* pilha){
    if(pilha == NULL || pilha->topo == NULL) return 1; //vazia
    return 0; //vazia
}

int tamanho_pilha(Pilha* pilha){
    if(pilha == NULL) return 0; // pilha vazia
    return pilha->tam;
}

void pilha_visualizar(Pilha* pilha, Visual* v){
    if(pilha == NULL || v == NULL) return;

    if(v->begin) v->begin(v);

    for(PilhaNo* n = pilha->topo; n; n = n->prox){
        if(v->elemento)
            v->elemento(v, n->valor);
    }

    if(v->end) v->end(v);
}