/*
Grupo:2
Aluno(s): Wellerson Prenholato de Jesus
		  Carlos Henrique F. L. da Fonseca
		  Hádamo da silva egito
		  Geraldo Nogueira
Curso: Ciência da Computação
*/

//Funçoes básicas de gereciamento de pilha
#include "pilha.h"

//Função para desalocar uma pilha
void free_pilha(pilha* P){
	bolaP *aux, *temp;
	if (P) {
		aux = P->ini;
		while (aux){
			temp = aux;
			aux = aux->prox;
			free(temp);
		}
		free(P);
	}
}

//Função para imprimir a cor da pilha
void cor_pilha(pilha* P){
    printf("%s",P->cor);
}

//Funçao para alocar uma nova bolaP
bolaP* nova_bolaP(char c){
	bolaP* nova = (bolaP*)calloc(1,sizeof(bolaP));
	if (nova)
		nova->elem = c;
	return nova;
}

//Funçao para alocar uma nova pilha
pilha* nova_pilha(char* cor){
	pilha* nova = (pilha*)calloc(1,sizeof(pilha));
	if (nova){
        nova->cor = (char*)malloc(strlen(cor));
		strcpy(nova->cor,cor);
	}
	return nova;
}

//Função para inserir uma nova bolaP na pilha
void insere_pilha(pilha* P,char c){
	if (P){
		bolaP* nova = nova_bolaP(c);
		if (nova){
			if (P->ini && P->fim){
				nova->ant = P->fim;
				P->fim->prox = nova;
				P->fim = nova;
			} else {
				P->ini = nova;
				P->fim = nova;
			}
			P->quantidade++;
		}
	}
}

//Função para remover uma bola da pilha
char remove_pilha(pilha* P){
	bolaP* aux;
	char c = '\0';
	if (P){
		aux = P->fim;
		c = aux->elem;
		if (P->ini && P->fim){
			if (P->ini == P->fim){
				P->ini = NULL;
				P->fim = NULL;
			}
			else{
				P->fim->ant->prox = NULL;
				P->fim = P->fim->ant;
			}
			free(aux);
			P->quantidade--;
		}
	}
	return c;
}

//Funçao para imprimir uma pilha
void imprimir_pilha(pilha* P){
    if (P){
        bolaP* aux = P->ini;
        while (aux){
            printf("%c ",aux->elem);
            aux = aux->prox;
        }
    }
}

//Funçao para imprimir a quantidade de elementos na pilha
int quantidade_pilha(pilha* P){
	int x=-1;
	if (P)
		x = P->quantidade;
	return x;
}