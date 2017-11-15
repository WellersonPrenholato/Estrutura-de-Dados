/*
Grupo:2
Aluno(s): Wellerson Prenholato de Jesus
		  Carlos Henrique F. L. da Fonseca
		  Hádamo da silva egito
		  Geraldo Nogueira
Curso: Ciência da Computação
*/

//Funçoes básicas de gerenciamento de Fila
#include "fila.h"

//Funçao para desalocar fila
void free_fila(fila* F){
	bolaF *aux, *temp;
	if (F) {
		aux = F->ini;
		while (aux){
			temp = aux;
			aux = aux->prox;
			free(temp);
		}
		free(F);
	}
}

//Função que imprime a cor de cada fila 
void cor_fila(fila* F){
    printf("%s",F->cor);
}

//Funçao para alocar uma nova bolaF
bolaF* nova_bolaF(char c){
	bolaF* nova = (bolaF*)calloc(1,sizeof(bolaF));
	if (nova)
		nova->elem = c;
	return nova;
}

//Função para criar uma nova fila
fila* nova_fila(char* cor){
	fila* nova = (fila*)calloc(1,sizeof(fila));
	if (nova){
        nova->cor = (char*)malloc(strlen(cor));
		strcpy(nova->cor,cor);
	}
	return nova;
}

//Funçao para inserir na fila uma nova bolaF
void insere_fila(fila* F,char c){
	if (F){
		bolaF* nova = nova_bolaF(c);
		if (nova){
			if (F->ini && F->fim){
				nova->ant = F->fim;
				F->fim->prox = nova;
				F->fim = nova;
			} else {
				F->ini = nova;
				F->fim = nova;
			}
			F->quantidade++;
		}
	}
}

//Funçao para remover uma bolaF na fila
char remove_fila(fila* F){
	bolaF* aux;
	char c = '\0';
	if (F){
		aux = F->ini;
		c = aux->elem;
		if (F->ini && F->fim){
			if (F->ini == F->fim){
				F->ini = NULL;
				F->fim = NULL;
			}
			else{
				F->ini->prox->ant = NULL;
				F->ini = F->ini->prox;
			}
			free(aux);
			F->quantidade--;
		}
	}
	return c;
}

//Função para imprimir uma fila
void imprimir_fila(fila* F){
    if (F){
        bolaF* aux = F->ini;
        while (aux){
            printf("%c ",aux->elem);
            aux = aux->prox;
        }
    }
}

//Funçao que acessa a quantidade de bolas na fila
int quantidade_fila(fila* F){
	int x=-1;
	if (F)
		x = F->quantidade;
	return x;
}