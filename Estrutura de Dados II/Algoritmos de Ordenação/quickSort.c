//Algoritmo de Ordenação

//************ FUNCIONANDO ***************
//*** FUNCIONANDO COM ELEMENTOS REPETIDOS ***

#include<stdio.h>

#define MAXN 1010

int particiona(int *v, int ini, int fim){
	int esq, dir, pivo, aux;
	esq = ini;
	dir = fim;
	pivo = v[ini];

	while(esq < dir){
		while( v[esq] <= pivo ) //para quando encontrar elemento
			esq++; //maior que o pivo
		while( v[dir] > pivo) //para quando encontrar elemento 
			dir--; //menor ou igual ao pivo
		if(esq < dir){ //se temos posicoes validas, entao faz a troca 
			aux = v[esq];
			v[esq] = v[dir];
			v[dir] = aux;
		}
	}
	v[ini] = v[dir];
	v[dir] = pivo;

	return dir;
}

void quickSort(int *v, int inicio, int fim){
	int pivo;
	if (inicio < fim){ //So faz ordenacao se tive pelo menos 2 elementos
		pivo = particiona (v, inicio, fim);
		quickSort (v, inicio, pivo-1);
		quickSort (v, pivo+1, fim);
	}
}

void printfVetor(int vet[], int tam){ // Procedimento para imprimir o vetor
	int i;

	printf("Vetor Organizado: ");
	for (i=0; i< tam; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}

int main (){
	int n, vetor[MAXN]; // declaro as variáveis que usarei
	int i; //Variaveis do for's

	printf("Insira o tamanho do vetor: ");
	scanf("%d", &n); // leio o valor de n
	
	printf("Insira os valores do vetor: ");
	for(i=0; i<n; i++){ //Preencher o vetor
		scanf("%d", &vetor[i]); // leio os n números do vetor
	}

	quickSort(vetor, 0, (n-1)); // Parametros: Vetor -> indice inicial -> indice final
	printfVetor(vetor, n); // Parametros: Vetor -> tamanho do vetor
	return 0;
}
