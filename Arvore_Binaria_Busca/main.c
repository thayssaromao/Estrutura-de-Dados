#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#define NUMB 10

int main(){
   Arvore *a = criaArvoreVazia();
   int i;

   printf("Arvore Binaria de Busca\n\n");
   printf("Numeros Sorteados > ");

   for (i=0; i<NUMB; i++){
      a = inserir(a, rand()%100);
   }
   printf("\n");
   printArvore(a);	
   
   
   printf("\nBusca > \n");
   printf("%d = %d\n%d = %d", 4, busca(a,4), 54, busca(a,54));
   printf("\n");
   printf("maior = %d\nmenor = %d",max(a), minimo(a) );
   printf("\n");
   printf("Decrescente > \n");
   imprime_decrescente(a);
   printf("\nCrescente > \n");
   imprime_crescente(a);
   printf("\n");
   printf("Maior ramo(soma) > %d", maior_ramo(a));
   libera(a);

   return 0;
}