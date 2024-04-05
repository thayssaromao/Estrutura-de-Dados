# ED2

[AQUI](https://lumbar-munchkin-40b.notion.site/Estrutura-de-Dados-I-545e16d807f74798b328ee5f55126a96?pvs=4) > Meu site Notion com resumos e provas antigas de ED1

## Árvores Binárias
## Árvores Binárias de busca
## Árvores Binárias de busca Balanceada (AVL)

A altura (h) dita a complexidade da árvore!

🐱‍🏍 **Regras de balanceamento:**

- Árvore balanceada O(log n);
- Rotações simples ou duplas;
- Fator de balanceamento (fb);
- Hd -> altura da SUBÁRVORE da direita;
- He -> altura da SUBÁRVORE da esquerda;
- Hd = He = 0 (árvore em equilíbrio);
- Hd > He = 1 (árvore em equilíbrio);
- He > Hd = -1 (árvore em equilíbrio);
- Fb pai e Fb filho, primeiro rotacionar o filho, depois rotação sobre o nó pai; 
- Sinais iguais (fb) - rotação simples;
- Sinais diferentes (fb) - rotação dupla;
- Ponteiro NULL (árvore nula) -> h=-1, logo, um nó sem filhos a altura é (-1 - (-1) = 0);
