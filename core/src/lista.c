#include "lista.h"
#define LISTA_OK 1
#define LISTA_ERRO 0

Lista* criar_lista(){
    // aloca espaço em memoria
	Lista* lista = malloc(sizeof *lista);

	// verifica se houve falha na alocação de memoria
	if(lista == NULL)
		return NULL;

    // inicia a lista vazia
	lista->inicio = NULL;
    lista->tam    =    0;
	// retorna o ponteiro alocado
	return lista;
}

void destruir_lista(Lista* lista){
    if(lista == NULL) return;

    ListaNo* atual = lista->inicio;
    ListaNo* prox;

    //percorre até que a lista esteja vazia, e vai apagando os nós anteriores
    while(atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    //apaga a lista
    free(lista);
}

int inserir_inicio(Lista* lista, int valor){
    if(lista == NULL) return LISTA_ERRO;

    ListaNo* no = malloc(sizeof *no);
    if(no == NULL) return LISTA_ERRO;
    
    no->valor = valor;
    no->prox = lista->inicio;
    lista->inicio = no;
    lista->tam++;

    return LISTA_OK;
}

int inserir_fim(Lista* lista, int valor){
    if(lista == NULL) return LISTA_ERRO;
    
    ListaNo* no = malloc(sizeof *no);
    if(no == NULL) return LISTA_ERRO;

    no->valor = valor;
    no->prox = NULL;

    if (lista->inicio == NULL) {
        // lista vazia
        lista->inicio = no;
    } else {
        ListaNo* atual = lista->inicio;
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = no;
    }

    lista->tam++;
    return LISTA_OK;
}

int remover_inicio(Lista* lista){
    if(lista == NULL) return LISTA_ERRO; // lista nao foi criada
    if(lista->inicio == NULL) return LISTA_ERRO; // lista vazia, sem nada pra remover

    ListaNo* atual = lista->inicio;
    ListaNo* no = atual->prox;

    lista->inicio = no;
    free(atual);
    lista->tam--;
    return LISTA_OK;
}

int remover_fim(Lista* lista){
    if(lista == NULL) return LISTA_ERRO; // lista nao foi criada
    if(lista->inicio == NULL) return LISTA_ERRO; // lista vazia, sem nada pra remover

    ListaNo* atual = lista->inicio;
    ListaNo* anterior;

    // caso com apenas 1 elemento
    if(atual->prox == NULL){
        free(atual);
        lista->tam--;
        lista->inicio = NULL;
        return LISTA_OK;
    }

    // caso com mais de 1 elemento
    while(atual->prox != NULL){
        anterior = atual;
        atual = anterior->prox;
    }

    anterior->prox = NULL;
    free(atual);
    lista->tam--;
    return LISTA_OK;
}

ListaNo* buscar_valor(Lista* lista, int valor){
    if(lista == NULL || lista->inicio == NULL) return NULL;

    ListaNo* atual = lista->inicio;
    while(atual != NULL){
        if(atual->valor == valor) return atual;
        atual = atual->prox;
    }

    return NULL;
}

int tamanho_lista(Lista* lista){
    if(lista == NULL) return 0;
    return lista->tam;
}

int lista_vazia(Lista* lista){
    if(lista == NULL) return 1; // a lista nula é o mesmo que vazia
    return lista->tam == 0 ? 1 : 0;
}

char* lista_para_json(Lista* lista){
    if(lista == NULL) return NULL;

    //tamanho da string
    size_t tamanho = lista->tam ? lista->tam * 32 : 32;
    char* json = malloc(tamanho);
    if(json == NULL) return NULL;

    //abre vetor
    strcpy(json, "[");
    ListaNo* atual = lista->inicio;
    int primeiro = 1;
    while(atual){
        //espaço necessário
        char buffer[64];
        snprintf(buffer, sizeof(buffer), "%s{\"valor\":%d}", primeiro ? "" : ",", atual->valor);

        //realoca se precisar
        if(strlen(json) + strlen(buffer) + 2 > tamanho){
            tamanho *= 2;
            char* tmp = realloc(json, tamanho);
            if(tmp == NULL){
                free(json);
                return NULL;
            }
            json = tmp;
        }

        //concatena com os dados do buffer
        strcat(json, buffer);
        primeiro = 0;
        atual = atual->prox;
    }

    //concatena fechando
    strcat(json, "]");
    return json;
}