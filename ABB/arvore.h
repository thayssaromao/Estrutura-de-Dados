#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore{
  struct Arvore *direita;
  struct Arvore *esquerda;
  int dado;

}Arvore;

Arvore* criaArvoreVazia(void);
void libera(Arvore* a);
Arvore* inserir(Arvore* a, int valor);
Arvore* remover(Arvore* a, int valor);
int busca(Arvore* a, int valor);
void printArvore(Arvore* a);

#endif