#include "arvore.h"


Arvore* criaArvoreVazia(void){
    return NULL;
}

//INSERE UM ELEMENTO NA ARVORE
Arvore* inserir(Arvore* a, int valor){
    if (a == NULL){
        a =(Arvore *)malloc(sizeof(Arvore));
        a->dado = valor;
        a->esquerda = NULL;
        a->direita = NULL;
    }
    else if(valor < a->dado){
        a->esquerda = inserir(a->esquerda, valor);
    }
    else{a->direita = inserir(a->direita, valor);}

    return a;
}
//REMOVE UM ELEMENTO NA ÁRVORE
Arvore* remover(Arvore* a, int valor){
    if(a == NULL){return NULL;}
    else{
        if (a->dado > valor){
            a->esquerda = remover(a->esquerda, valor);
        }
        else if(a->dado < valor){
            a->direita = remover(a->direita, valor);
        }
        else{
            if((a->esquerda == NULL) &&(a->direita == NULL)){
                free(a);
                a = NULL;
            }
            else if(a->esquerda == NULL){
                Arvore* tmp = a;
                a = a->direita;
                free(tmp);
            }
            else if(a->direita == NULL){
                Arvore* tmp = a;
                a = a->esquerda;
                free(tmp);
            }
            else{
               Arvore* tmp = a->esquerda;
               while(tmp->direita != NULL){
                tmp = tmp->direita;
               }
               a->dado = tmp->dado;
               tmp->dado = valor;
               a->esquerda = remover(a->esquerda, valor); 
            }
        }
    }
    return a;
}
//LIBERA A MEMORIA DA ÁRVORE
void libera(Arvore* a){
    if (a != NULL) {
      libera (a->esquerda);
      libera (a->direita);
      free(a);
   }
}
void printArvore(Arvore* a){
    if (a != NULL) {
      printf("%d ", a->dado);
      printArvore (a->esquerda);
      printArvore (a->direita);
    }
}