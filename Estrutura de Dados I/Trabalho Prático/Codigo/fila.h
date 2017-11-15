/*
Grupo:2
Aluno(s): Wellerson Prenholato de Jesus
		  Carlos Henrique F. L. da Fonseca
		  Hádamo da silva egito
		  Geraldo Nogueira
Curso: Ciência da Computação
*/
#ifndef _FILA_H_
#define _FILA_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Def das estruturas
typedef struct bolaF {
	char elem; ////Armazena o char que representa a letra
	struct bolaF* prox;
	struct bolaF* ant;
} bolaF;//Estrutura bolaF é armazenada na Fila

typedef struct fila{
	char* cor; //Cor da caixa
	int quantidade; //Quantidade de elementos
	bolaF* ini; //Ponteiro para inicio da fila
	bolaF* fim; //Ponteiro para inicio da fila
} fila;//TAD Fila

// Cria nova bolaF, retornando ponteiro para a bolaF
// Entrada: 1 char
bolaF* nova_bolaF(char);

// Cria nova fila vazia, retornando ponteiro para a fila
// Entrada: cor da caixa em string
fila* nova_fila(char*);

// Funcao de inserir no fim da fila
void insere_fila(fila*,char);

// Funcao de remover no inicio da fila, retorna o char removido
char remove_fila(fila*);

// Imprimi a fila
void imprimir_fila(fila*);

// Quantidade de elementos na fila, retorna int
int quantidade_fila(fila*);

// free na memoria alocada pela fila
void free_fila(fila*);

// imprime a cor da fila
void cor_fila(fila*);

#endif