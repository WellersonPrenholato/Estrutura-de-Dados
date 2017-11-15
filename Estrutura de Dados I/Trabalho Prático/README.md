# Trabalho Prático - [Estrutura de Dados I]
---
> Trabalho realizado na disciplina de Estrutura de Dados I - CEUNES (Centro Universitário Norte do Espírito Santo).

> Foram utilizadas algumas técnicas de armazenamento e organização de dados, de modo que fossem usados  eficientemente, facilitando sua busca e modificação. 
> Algumas estruturas utilizadas: Fila, Pilha entre outras.
---
> #### Aluno(s) que realizaram o trabalho:

  > Carlos Henrique F. L. da Fonseca
  
  > Hádamo da Silva Egito
  
  > Wellerson Prenholato de Jesus
  
  > Geraldo Nogueira
  
---

## Tarefa 
  Um professor de matemática resolveu criar um jogo que utiliza n bolas coloridas. Cada bola
possui uma cor e uma letra. O professor separa as bolas em caixas de acordo com suas cores.
São um total de k cores. O professor começa a retirar as bolas de uma caixa, uma de cada
vez, enfileirando-as sobre a mesa, na ordem em que elas foram sorteadas. Ele retira as bolas
de uma caixa até que esta fique vazia. Só então ele começa a retirar as bolas de outra caixa
e assim sucessivamente, até que todas as bolas sejam retiradas e enfileiradas sobre a mesa.

  Considere que o conjunto de cores é C = {c1, c2, . . . . , ck} e o número de bolas de uma cor
ci é dado por |ci|. A ordem de escolha da caixa a ser esvaziada é de acordo com o número de
bolas contidas nela. Ou seja, as caixas serão ordenadas de forma não-decrescente do número
de bolas contidas nelas.

  Uma vez definida a ordem das caixas, cada aluno deve escrever a sequência de bolas que
serão enfileiradas. Cada elemento da sequência deve ter a cor e a letra de cada bola. Ganha
o aluno que acertar a sequência.

  Implemente um algoritmo de busca em profundidade de forma recursiva para gerar
todas as possibilidades de resultado para o jogo. As possibilidades de resultado do jogo
devem ser impressas na tela, uma por linha. Na impressão de um resultado, para cada bola
deve ser impressas sua cor e sua letra.

Seu programa deve receber como entrada:

* O número de bolas (valor de n);
* O número de cores (valor de k);
* Para cada cor: a quantidade de bolas daquela cor e as letras de cada bola.

---
[Estrutura de Dados I]: https://pt.wikipedia.org/wiki/Estrutura_de_dados
