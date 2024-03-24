#include "arvore.h"

//CRIA UM ÁRVORE VAZIA
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

//LIBERA A MEMORIA ALOCADA DA ÁRVORE
void libera(Arvore* a){
    if (a != NULL) {
      libera (a->esquerda);
      libera (a->direita);
      free(a);
   }
}

//FUNÇÃO PARA IMPRIMIR OS ELEMENTOS DA ÁRVORE
void printArvore(Arvore* a){
    if (a != NULL) {
      printf("%d ", a->dado);
      printArvore (a->esquerda);
      printArvore (a->direita);
    }
}

//PROCURA SE O ELEMENTO 'valor' ESTA NA LISTA
int busca(Arvore* a, int valor){
    if(a == NULL){return 0;}
    else{
        
        if(valor > a->dado){
            return busca(a->direita, valor);
        }
        else if(valor < a->dado){
            return busca(a->esquerda, valor);
        }
        
    }
    return 1;
}

//RETORNA O MENOR VALOR DA LISTA (vai até o extremo do ramo da esquerda - menores numeros)
int minimo(Arvore* a){
 int m = -INT_MAX;
 while(a!=NULL){
    m= a->dado;
    a= a->esquerda;
 }
 return m;
}

//RETORNA O MAIOR VALOR DA LISTA (vai até o extremo do ramo da direita - maiores numeros)
int max(Arvore* a){
 int m = -INT_MAX;
 while(a!=NULL){
    m= a->dado;
    a= a->direita;
 }
 return m;
}

//IMPRIME A ARVORE EM ORDEM CRESCENTE
void imprime_decrescente (Arvore *a){
    if(a != NULL){
        imprime_decrescente(a->direita);
        printf("%d ", a->dado);
        imprime_decrescente(a->esquerda);
    }

}
//IMPRIME A ARVORE EM ORDEM DECRESCENTE
void imprime_crescente(Arvore* a){
    if(a != NULL){
        imprime_crescente(a->esquerda);
        printf("%d ", a->dado);
        imprime_crescente(a->direita);
    }
}

/// /////   ///////////// ////
int maxRamo(int a, int b) {
    return (a > b) ? a : b;
}

int maior_ramo(Arvore *a) {
    if (a == NULL) {return 0;} 
    else {
        return maxRamo(maior_ramo(a->esquerda), maior_ramo(a->direita)) + a->dado;
    }
}
