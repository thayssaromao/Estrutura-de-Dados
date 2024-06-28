#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
 int id; /*Identificador armazenado no nó. */
 struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
 int E; /* Quantidade de arestas. */
 int V; /* Quantidade de vértices. */
 NoA **Adj; /* Lista de adjacências. */
} GrafoA;


/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
 int E; /* Quantidade de arestas. */
 int V; /* Quantidade de vértices. */
 int **Mat; /* Matrix de adjacências. */
} GrafoM;


/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho) {
    int v;
    GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));

    G->E = 0;
    G->V = tamanho;
    G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
    
    for (v = 0; v < G->V; v++) {
     G->Adj[v] = NULL;
    }
    return G;
}
/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
    int v;
    GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
    G->E = 0;
    G->V = tamanho;
    G->Mat = (int **)malloc(tamanho * sizeof(int *));
    
    for (v = 0; v < G->V; v++) {
     G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
    }
    return G;
}
/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G) {
 int v;
 for (v = 0; v < G->V; v++) { if (G->Adj[v] != NULL) {
 free(G->Adj[v]);
 }
 }
 free(G->Adj);
 free(G);
}
/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat (GrafoM *G) {
 int v; for (v = 0; v < G->V; v++) { if (G->Mat[v] != NULL) {
 free(G->Mat[v]);
 }
 }
 free(G->Mat);
 free(G);
}

/*−−−−−−−−−−−Init Matriz−−−−−−−−−−−−−−−−−−−−*/
void inicializar_grafo_mat (GrafoM *G) {
    int u, v; 
    for (u = 0; u < G->V; u++) {
        for (v = 0; v < G->V; v++) {
            G -> Mat[u][v] = 0;
        }
    } 
}
/*−−−−−−−−−−−−−Print Matriz−−−−−−−−−−−−−−−−−−*/
void imprimir_grafo_mat (GrafoM *G) {
 int u, v; 
 printf ("Grafo (matriz adjacência):\n");
 printf (" ");
 //print índice das colunas
 for (u = 0; u < G->V; u++) {
 printf ("%2d ", u);
 }
 printf ("\n\n");
 for (u = 0; u < G->V; u++) { //print índice das linhas 
 printf ("%2d ", u);
 for (v = 0; v < G->V; v++) {
 printf ("%2d ", G->Mat[u][v]);
 }
 printf ("\n");
 } 
 printf ("\n");
}
/*−−−−−−−−−−Print lista−−−−−−−−−−−−−−−−−−−−−*/
void imprimir_grafo_adj (GrafoA *G) {
 int u; 
 printf ("Grafo (lista adjacência):\n");
 for (u = 0; u < G->V; u++) {
 printf ("%2d -> ", u);
 NoA *v;
 for (v = G->Adj[u]; v != NULL; v = v->next) {
 printf ("%2d ", v->id);
 }
 printf ("\n");
 } 
 printf ("\n");
}
/*−−−−−−−−−−Add aresta Matriz−−−−−−−−−−−−−−−−−−−−−*/
void _adicionar_aresta_grafo_mat (int u, int v, GrafoM *G, int peso) { if (G->Mat[u][v] == 0) {
 G->Mat[u][v]=1;
 G->E++;
 }
 else {
 printf("a aresta (%d,%d) já existe!!!", u, v);
 }
}
void adicionar_aresta_grafo_mat (int u, int v, GrafoM *G) {
 //bidirecional 
 _adicionar_aresta_grafo_mat (u, v, G,1);
 _adicionar_aresta_grafo_mat (v, u, G,1);
}
/*−−−−−−−−−−Add aresta Lista−−−−−−−−−−−−−−−−−−−−−*/
void _adicionar_aresta_grafo_adj (int u, int v, GrafoA *G) {
    NoA *aux, *ultimo = NULL;
    //percorre lista de adj até chegar ao último nó
    for (aux = G->Adj[u]; aux != NULL; aux = aux->next) {
    if (aux->id == v) {
        printf("a aresta (%d,%d) já existe!!!", u, v);
        return;
    } 
    ultimo = aux;
    }
    //adiciona nova adj no final da lista 
    NoA *novo = (NoA *)malloc(sizeof(NoA));
    novo->id = v;
    novo->next = NULL;
    //lista já tinha elementos if (ultimo != NULL) {
    ultimo->next = novo;
    
    //lista estava vazia

    G->Adj[u] = novo;
    
    G->E++;
}
void adicionar_aresta_grafo_adj (int u, int v, GrafoA *G) {
 //bidirecional 
 _adicionar_aresta_grafo_adj (u, v, G);
 _adicionar_aresta_grafo_adj (v, u, G);
}
/* */
int main () {
 int Vm = 6; /*Número de vértices*/
 GrafoM* Gm = criar_grafo_mat (Vm);
 inicializar_grafo_mat (Gm);
 adicionar_aresta_grafo_mat (0, 1, Gm);
 adicionar_aresta_grafo_mat (0, 2, Gm);
 adicionar_aresta_grafo_mat (0, 5, Gm);
 adicionar_aresta_grafo_mat (1, 2, Gm);
 adicionar_aresta_grafo_mat (1, 3, Gm);
 adicionar_aresta_grafo_mat (2, 3, Gm);
 adicionar_aresta_grafo_mat (2, 4, Gm);
 adicionar_aresta_grafo_mat (3, 4, Gm);
 adicionar_aresta_grafo_mat (4, 5, Gm);
 imprimir_grafo_mat (Gm);
 int Va = 6; /*Número de vértices*/
 GrafoA* Ga = criar_grafo_adj (Va);
 adicionar_aresta_grafo_adj (0, 1, Ga);
 adicionar_aresta_grafo_adj (0, 2, Ga);
 adicionar_aresta_grafo_adj (0, 5, Ga);
 adicionar_aresta_grafo_adj (1, 2, Ga);
 adicionar_aresta_grafo_adj (1, 3, Ga);
 adicionar_aresta_grafo_adj (2, 3, Ga);
 adicionar_aresta_grafo_adj (2, 4, Ga);
 adicionar_aresta_grafo_adj (3, 4, Ga);
 adicionar_aresta_grafo_adj (4, 5, Ga);
 imprimir_grafo_adj (Ga);
 liberar_grafo_adj (Ga);
 liberar_grafo_mat (Gm);
 return 0;
}
