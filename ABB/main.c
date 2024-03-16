#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
   Arvore *a = criaArvoreVazia();

   a = inserir(a,20);
   a = inserir(a,0);
   a = inserir(a,-3);
   a = inserir(a,14);

   printf("\n");
   printArvore(a);	
   printf("\n");


   libera(a);

   return 0;
}