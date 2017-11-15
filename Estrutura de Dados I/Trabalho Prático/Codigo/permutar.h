/*
Grupo:2
Aluno(s): Wellerson Prenholato de Jesus
		  Carlos Henrique F. L. da Fonseca
		  Hádamo da silva egito
		  Geraldo Nogueira
Curso: Ciência da Computação
*/
#ifndef _PERMUTAR_H_
#define _PERMUTAR_H_

#include "fila.h"
#include "pilha.h"

typedef struct permutacao{
	fila** caixa; // vetor de fila (representam as caixas)
	pilha** perm; // vetor de pilha que contem a permutacao
	int qnt_caixa; // quantidade de caixas
} permutacao; //Estrutura que armazena vetores de pilha e fila

// funcao que recebe as caixas e aloca a estrutura permutacao necessaria para utilizar a funçao permutacao recursiva
// entrada: ponteiro para o vetor de caixas, quantidade de caixa
void permutar(fila**, int);

// funcao recursiva das permutacoes
// entrada: estrutura de permutacao, int que conta em qual caixa esta permutando
void permutar_rec(permutacao*, int);

#endif