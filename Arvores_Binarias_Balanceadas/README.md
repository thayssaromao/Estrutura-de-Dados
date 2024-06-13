# 🌳 AVL (Árvore Balanceada de Altura Mínima)

[Site](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html) > Criação de uma AVL

[Site]( https://visualgo.net/en/bst) > Visualização interativa de algoritmos


| **A altura (h) dita a complexidade da árvore !!**|
|---------------------------------------------|

## ⚖️ **Regras de balanceamento:**

- Árvore balanceada O(log n);
- Rotações simples ou duplas;
- Fator de balanceamento (fb);
- Hd -> altura da **SUBÁRVORE** da direita;
- He -> altura da **SUBÁRVORE** da esquerda;
- Hd = He = 0 (árvore balanceada);
- Hd > He = 1 (árvore em equilíbrio);
- He > Hd = -1 (árvore em equilíbrio);
- NO rebalanceamento, Fb pai e Fb filho, primeiro rotacionar o filho, depois rotacionar sobre o nó pai; 
- Sinais iguais (fb) - rotação simples;
- Sinais diferentes (fb) - rotação dupla;
- Ponteiro NULL (árvore nula) -> h=-1, logo,  a altura de um nó sem filhos é = (-1 - (-1) = 0);
- Remoção - PADRÃO - maior elemento da subárvore da esquerda OU o menor elemento da subárvore da direita;

## 👾 **Características**
- Balanceamento;
- Rotação;
- O(n);
- Para cada no X, as alturas (h) das subarvores
 esquerda e direita de X diferem de no maximo
 uma unidade;
- fb(x) = hd(x)- he(x);
(fb = fator de balanceamento; he = h nó esquerda; hd = h nó direita)
- Cada nó DEVE **(-1 <= fb <=1)** se fb = 0 Arvore balanceada;
-  fb (nó-filho e nó-pai) de mesmo sinal -> Solucao: rotacao simples;
-  fb(nó-filho e nó-pai) de diferente sinal -> Solucao: rotacao dupla;

# 📚 Exercício 1
## passo a passo + solução

![1](https://github.com/thayssaromao/Estrutura-de-Dados/blob/main/Arvores_Binarias_Balanceadas/Ex_1pt1.jpeg)
![1](https://github.com/thayssaromao/Estrutura-de-Dados/blob/main/Arvores_Binarias_Balanceadas/Ex_1pt2.jpeg)
![1](https://github.com/thayssaromao/Estrutura-de-Dados/blob/main/Arvores_Binarias_Balanceadas/Ex_1solucao.png)


# 📚 Exercício 2
## passo a passo + solução

![1](https://github.com/thayssaromao/Estrutura-de-Dados/blob/main/Arvores_Binarias_Balanceadas/frente_page-0001%20(1).jpg)
![1](https://github.com/thayssaromao/Estrutura-de-Dados/blob/main/Arvores_Binarias_Balanceadas/verso.jpeg.jpg)
