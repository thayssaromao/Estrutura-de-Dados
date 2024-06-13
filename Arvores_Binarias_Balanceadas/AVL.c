#include <stdio.h>
#include <stdlib.h>

/* STRUCT */

typedef struct node {
    char chave;
    int altura;
    struct node* esq;
    struct node* dir;
} node, Arvore;

int maior(int esq, int dir);
int Altura(Arvore* a);
void atualiza(Arvore *a);
int balanceamento(Arvore *a);
Arvore* rotacao_simples_esq(Arvore* a);
Arvore* rotacao_simples_dir(Arvore* a);
Arvore* rotacao_dupla_esq(Arvore* a);
Arvore* rotacao_dupla_dir(Arvore* a);
Arvore* inserir(Arvore *a, char chave);
Arvore* remover(Arvore *a, char chave);
void imprimir_in_order(Arvore* a, int nivel);

/* MAIN */

int main() {
    Arvore *AVL = NULL;

    AVL = inserir(AVL, 'Q');
    AVL = inserir(AVL, 'C');
    AVL = inserir(AVL, 'Z');
    AVL = inserir(AVL, 'B');
    AVL = inserir(AVL, 'Y');
    AVL = inserir(AVL, 'T');
    AVL = inserir(AVL, 'M');
    AVL = inserir(AVL, 'E');
    AVL = inserir(AVL, 'W');
    AVL = inserir(AVL, 'X');
    AVL = inserir(AVL, 'S');
    AVL = inserir(AVL, 'F');
    AVL = inserir(AVL, 'G');
    AVL = inserir(AVL, 'A');
    AVL = inserir(AVL, 'H');
    AVL = inserir(AVL, 'N');
    AVL = inserir(AVL, 'O');
    AVL = inserir(AVL, 'P');
    AVL = inserir(AVL, 'R');

    imprimir_in_order(AVL, 0);

    return 0;
}

/* FUNÇÕES IMPLEMENTADAS */

/* Função que devolve o maior entre dois números inteiros! */
int maior(int esq, int dir) {
    return (esq > dir ? esq : dir);
}

/* ---------------------- */
int Altura(Arvore* a) {
    return (a == NULL ? -1 : a->altura);
}

void atualiza(Arvore *a) {
    a->altura = maior(Altura(a->esq), Altura(a->dir)) + 1;
}

/* ---------------------- */
int balanceamento(Arvore *a) {
    return (Altura(a->dir) - Altura(a->esq));
}

Arvore* atualizar_fb_dir(Arvore *a) {
    atualiza(a);
    if (balanceamento(a) == +2) {
        if (balanceamento(a->dir) < 0)
            a->dir = rotacao_simples_dir(a->dir);
        a = rotacao_simples_esq(a);
    }
    return a;
}

/* ---------------------- */
Arvore* atualizar_fb_esq(Arvore *a) {
    atualiza(a);
    if (balanceamento(a) == -2) {
        if (balanceamento(a->esq) > 0)
            a->esq = rotacao_simples_esq(a->esq);
        a = rotacao_simples_dir(a);
    }
    return a;
}

/* ---------------------- */
Arvore* rotacao_simples_esq(Arvore* a) {
    node* temp = a->dir;

    a->dir = temp->esq;
    temp->esq = a;

    atualiza(a);
    atualiza(temp);

    return temp;
}

/* ---------------------- */
Arvore* rotacao_simples_dir(Arvore* a) {
    node* temp = a->esq;

    a->esq = temp->dir;
    temp->dir = a;

    atualiza(a);
    atualiza(temp);

    return temp;
}

/* ---------------------- */
Arvore* rotacao_dupla_esq(Arvore* a) {
    a->dir = rotacao_simples_dir(a->dir);
    return rotacao_simples_esq(a);
}

/* ---------------------- */
Arvore* rotacao_dupla_dir(Arvore* a) {
    a->esq = rotacao_simples_esq(a->esq);
    return rotacao_simples_dir(a);
}

/* ---------------------- */
Arvore* inserir(Arvore *a, char chave) {
    if (a == NULL) {
        a = (node*)malloc(sizeof(node));
        a->chave = chave;
        a->altura = 0;
        a->esq = NULL;
        a->dir = NULL;
    } else if (chave < a->chave) {
        a->esq = inserir(a->esq, chave);
        a = atualizar_fb_esq(a);
    } else if (chave > a->chave) {
        a->dir = inserir(a->dir, chave);
        a = atualizar_fb_dir(a);
    }
    atualiza(a);
    return a;
}

/* Função para remover um nó de uma árvore binária de busca balanceada! */
Arvore* remover(Arvore *a, char chave) {
    if (a == NULL) {
        return NULL;
    } else {
        if (chave < a->chave) {
            a->esq = remover(a->esq, chave);
            a = atualizar_fb_dir(a);
        } else if (chave > a->chave) {
            a->dir = remover(a->dir, chave);
            a = atualizar_fb_esq(a);
        } else {
            if ((a->esq == NULL) && (a->dir == NULL)) {
                free(a);
                a = NULL;
            } else if (a->esq == NULL) {
                node *tmp = a;
                a = a->dir;
                free(tmp);
            } else if (a->dir == NULL) {
                node *tmp = a;
                a = a->esq;
                free(tmp);
            } else {
                node *tmp = a->esq;
                while (tmp->dir != NULL) {
                    tmp = tmp->dir;
                }
                a->chave = tmp->chave;
                tmp->chave = chave;
                a->esq = remover(a->esq, chave);
                a = atualizar_fb_dir(a);
            }
        }
        if (a != NULL) atualiza(a);
        return a;
    }
}

/* Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem! */
void imprimir_in_order(Arvore* a, int nivel) {
    if (a != NULL) {
        imprimir_in_order(a->esq, nivel + 1);
        for (int i = 0; i < nivel; i++) {
            printf("      ");
        }
        printf("Chave: %c (altura: %d, fb: %+d) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel);
        imprimir_in_order(a->dir, nivel + 1);
    }
}
