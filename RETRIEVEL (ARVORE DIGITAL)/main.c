#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define size 26


//ESTRUTURA

typedef struct trie {
   char data; 
   int end;
   int nchild;
   struct trie *keys[size];
} Trie;

Trie *create_node (char data);

void free_node (Trie *node);

Trie *insert (Trie *root, char *word);

int search (Trie *root, char *word);

int search_auxiliary (Trie *root, char *word);

void print (Trie *root, int level);

void delete (Trie *root, char *word);


// MAIN 

int main () {

  Trie *root = create_node ('\0');

  root = insert (root, "maria");
  root = insert (root, "mel");
  root = insert (root, "malvadeza");
  root = insert (root, "mar");
  root = insert (root, "marisia");
  // search (root, "mar");
  // print (root, 0);

  printf("\nArvore TRIE\n");

  delete (root, "maru");
  // search (root, "mar");
  printf("\n\n");
  
  print (root, 0);

  return 0;
}




/* CÓDIGO*/

Trie *create_node (char data) {
  Trie *node = (Trie *)malloc(sizeof(Trie));
  node->data = data;
  node->end = FALSE;
  node->nchild = 0;
  int i;
  //size is the alphabet size 
  for (i = 0; i < size; i++) {
    node->keys[i] = NULL;	   
  }
  return node;   
}

/* */
void free_node (Trie *node) {
  int i;
  for (i = 0; i < size; i++) {
    if (node->keys[i] != NULL) {
      free_node (node->keys[i]);	    
    }
  }	  
  free (node);
}

/* */
Trie *insert (Trie *root, char *word) {
  int index, i;

  if(search(root, word)){
    printf("\n>>%s Já está na lista<<\n", word);
    return root;
  }

  Trie* tmp = root;
  for(i = 0; word[i]!='\0'; i++ ){
    index = word[i] - 'a';

    if(tmp->keys[index] == NULL){
      tmp->keys[index] = create_node(word[i]);
    }
    tmp->nchild += 1;
    tmp = tmp->keys[index]; 
  }
  tmp->end = TRUE; 
  
  return root;  	
}

/* */
int search_auxiliary (Trie *root, char *word) {
  Trie* tmp = root;
  int index, i;

  for(i = 0; word[i]!='\0'; i++ ){
    index = word[i] - 'a';

    if(tmp->keys[index] == NULL){
      return FALSE;
    }
    tmp = tmp->keys[index];
  }

  return tmp->end ? TRUE : FALSE;
}

int search (Trie *root, char *word) {
  if (search_auxiliary (root, word)){
    printf("Word %s encontrada!\n", word);
    return TRUE;
  } 
  else { 
    printf("Error: word %s não encontrada!\n", word);
    return FALSE;
  }
}

/* */
void print (Trie *root, int level) {
  if (root != NULL) {
    int i;
    if (root->data == '\0')
      printf ("(null)");	    
    for (i = 0; i < level; i++) {
      printf ("| ");
    }	    
    printf ("%c (%d - %d)\n", root->data, root->end, root->nchild);
    for (i = 0; i < size; i++) {
      print (root->keys[i], level+1);      
    }
  }	  
}

void delete (Trie *root, char *word) {

  int index, i;
  Trie* tmp = root;

  if(search(root, word)){
    
    for(i = 0; word[i]!='\0'; i++ ){
      index = word[i] - 'a';
      tmp->nchild -= 1;
      tmp = tmp->keys[index];
    }
    
    tmp->end = FALSE;
    printf("eliminando : %s\n", word);
  }
  else{(printf("%s não está na árvore\n", word));}
}  
 
