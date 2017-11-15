/*
Grupo:2
Aluno(s): Wellerson Prenholato de Jesus
		  Carlos Henrique F. L. da Fonseca
		  Hádamo da silva egito
		  Geraldo Nogueira
Curso: Ciência da Computação
*/
#include "permutar.h"

void permutar(fila** vet_cx, int k) {
 	int i;
	if (k > 0){
		permutacao* novo = (permutacao*)malloc(sizeof(permutacao)); // aloca novo do tipo permutacao
		if (novo){ // verifica se novo foi alocado
			novo->qnt_caixa = k; // insere a qnt de caixas na estrutura
			pilha** vet_pilha = (pilha**)calloc(k, sizeof(pilha*)); // aloca vetor de pilhas necessarias na permutacao
			if (vet_pilha){ // verifica vet_pilha foi alocado
				for(i = 0; i < k; i++) // aloca cada posicao do vetor
					vet_pilha[i] = nova_pilha("\0");
				
				novo->caixa = vet_cx;
				novo->perm = vet_pilha;

				//Chama a funçao permutacao recursiva
				permutar_rec(novo, 0);

				// Libera o espaco de memoria (Free)
				for(i = 0; i < k ; i++)
					free_pilha(vet_pilha[i]);
				free(vet_pilha);
			}
		}
	}
}

void permutar_rec(permutacao* permS, int count){
	char c;
	int i,j;
	fila** fila = permS->caixa; // melhor visibilidade
	pilha** pilha = permS->perm; // melhor visibilidade
	if (quantidade_fila(fila[count]) == 0){ // caso base: quantidade igual a 0 --> tem uma permutacao
		if (count == permS->qnt_caixa-1){ // verifica se e a ultima caixa
			for(j = 0; j < permS->qnt_caixa; j++){ // imprime a sequencia de permSutacao de todas as caixas
				cor_fila(fila[j]);
				printf(" | ");
				imprimir_pilha(pilha[j]);
				printf("|    ");
			}
			printf("\n");
		}
		else{ // caso nao for a ultima caixa
			count++; // atualiza o valor para que a prox caixa seja permutada
			permutar_rec(permS,count); // chama recursao para a prox caixa
		}
	} else {
		for(i = 0; i < quantidade_fila(fila[count]); i++){ // for para a quantidade de bolas na caixa
			c = remove_fila(fila[count]); // retira da fila
			insere_pilha(pilha[count],c); // coloca na pilha
			permutar_rec(permS,count); // chamada recursiva
			c = remove_pilha(pilha[count]); // backtrack
			insere_fila(fila[count],c);
		}
	}
}