#include <stdio.h>
#include <stdlib.h>



int Pai(int i){
    return (i-1)/2;
}

int Esquerda(int i){
    return 2*i+1;
}

int Direita(int i){
    return 2*i+2;
}

void trocar (int V[], int a, int b) {
   int aux = V[a];
   V[a] = V[b];
   V[b] = aux;
}

void imprimir (int V[], int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", V[i]);
   }
   printf("\n");
}

void max_heapify (int V[], int size, int i) {
   int e, d, maior;
   e = Esquerda(i);
   d = Direita(i);

    if(e < size && V[e] > V[i]){
        maior = e;
    }
    else maior = i ;

    if(d < size && V[d] > V[maior]){
        maior = d;
    }

    if(maior != i){
        trocar(V, i, maior);
        max_heapify(V, size, maior);
    }

}

void build_max_heap (int V[], int size) {
   int i = (size/2)-1;
   for(i; i>=0; i--){max_heapify(V, size, i);
   //  imprimir (V, size);
    }
}

void heap_sort (int V[], int size) {
   build_max_heap(V, size);
   int i;
   for(i = size-1; i>=0; i--){
      trocar(V, i, 0);
      max_heapify(V, i, 0);

   }

}

int main () {

   int i;

   int size = 9;

   int V[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
   // int questao2[] = {5,3,17,10,84,19,6,22,9};
   printf("Vetor inicial : ");
   imprimir (V, size);
   // imprimir (questao2, size);
   // printf("Vetor apos BUILD : ");
   // build_max_heap(questao2, size);
  

   // printf("pai do elemento V[%d] elem > %d = posicao %d > %d\n",2, V[2], Pai(2), V[Pai(2)]);
   // printf("esquerda do elemento V[%d] %d = posicao %d > %d\n",0, V[0], Esquerda(0), V[Esquerda(0)]);
   // printf("direita do elemento V[%d] %d = posicao %d > %d\n",0, V[0], Direita(0), V[Direita(0)]);

   heap_sort (V, size);
   printf("Vetor ordenado: ");
   imprimir (V, size);
  
   return 0;
}