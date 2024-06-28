#include <stdio.h>
#include <stdlib.h>

int pai (int i) {
   return (i - 1)/2;
}

int esquerda (int i) {
   return (i * 2) + 1;
}

int direita (int i) {
   return (i * 2) + 2;
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
   int e = esquerda (i);
   int d = direita (i);
   int maior;
   if ( (e < size) && (V[e] > V[i]) ) {
      maior = e;
   }
   else {
      maior = i;
   }
   if ( (d < size) && (V[d] > V[maior]) ) {
      maior = d;
   }
   if (maior != i) {
      trocar (V, i, maior);
      max_heapify (V, size, maior);
   }
}

int Heap_maximun(int V[]){return V[0];}

void heap_decrease_key (int v[], int i, int chave, int size){
    if(chave > v[i]){printf("Chave maior que o valor atual\n");}
    else{
        v[i] = chave;
        max_heapify(v, size, i);
    }
}

void heap_increase_key (int v[], int i, int chave, int size) {
   if (chave < v[i]) {
      printf ("Nova chave menor que a chave atual\n");
   }
   else {
      v[i] = chave;
    //  printf ("\npai %d \n", v[pai(i)]);
    //  printf ("\ni %d \n", v[i]);
     while ((i > 0) && (v[pai(i)] < v[i])) {
         trocar (v, i, pai(i));
       
         i = pai(i);
      }
   }
  
}

int main () {

   int size = 12;

   int v[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};

   printf ("Inicial V[]: ");
   imprimir (v, size);

   /*Modificando a chave da posição 0 para o valor 1!*/   
   heap_decrease_key (v, 0, 1, size);
   printf ("After decrease-key: \n");
   imprimir (v, size);

//    heap_increase_key (v, 3, 14, size);
//    printf ("\nAfter increase-key: \n");   
    
//    imprimir (v, size);

   return 0;
}

