/*
Grupo:2
Aluno(s): Wellerson Prenholato de Jesus
		  Carlos Henrique F. L. da Fonseca
		  Hádamo da silva egito
		  Geraldo Nogueira
Curso: Ciência da Computação
*/
#ifndef _PILHA_H_
#define _PILHA_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Definição das estruturas
typedef struct bolaP {
	char elem;//Armazena o char que representa a letra
	struct bolaP* prox;
	struct bolaP* ant;
} bolaP; //Estrutura bolaP é armazenada na pilha

typedef struct pilha{
	char* cor;//Cor da caixa
	int quantidade; // Quantidade de bola(s) na pilha (caixa)
	bolaP* ini; //Ponteiro para a ultima bola da pilha
	bolaP* fim; //Ponteiro para a ultima bola da pilha
} pilha; //TAD Pilha

// Cria nova bolaP, retornando ponteiro para a bolaP
// Entrada: 1 char
bolaP* nova_bolaPP(char);

// Cria nova pilha vazia, retornando ponteiro para a bolaP
// Entrada: cor da pilha em string
pilha* nova_pilha(char*);

// Funcao de inserir no topo da pilha, retorna o char removido
void insere_pilha(pilha*,char);

// Funcao de remover no topo da pilha, retorna o char removido
char remove_pilha(pilha*);

// Imprimi a pilha
void imprimir_pilha(pilha*);

// Quantidade de elementos na pilha, retorna int
int quantidade_pilha(pilha*);

// free na memoria alocada pela pilha
void free_pilha(pilha*);

// imprime a cor da pilha
void cor_pilha(pilha*);

#endif