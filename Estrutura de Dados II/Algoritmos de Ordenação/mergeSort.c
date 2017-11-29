//Algoritmo de Ordenação

//************ FUNCIONANDO ***************

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 1010

void merge (int *v, int p, int q, int r){ // Parametros: Ponteiro para vetor -> inicio -> meio -> fim
	int tam = r-p; // Tamanho do Vetor
	int *aux = (int*)calloc (tam, sizeof (int));

	int i, j, k;
	k=0;
	i=p;
	j=q;

	while (i< q && j< r){
		if (v[i] <= v[j]){
			aux[k++]= v[i++];
		}else{
			aux[k++]=v[j++];
		}
	}
	while (i<q){
		aux[k++]=v[i++];
	}
	while (j< r){
		aux[k++] = v[j++];
	}
	
	/*for (i=p; i< r; i++){
		v[i]=aux[i-p];
	}*/
	memcpy(&(v[p]), aux, tam *sizeof(int));
	free(aux);

}

void mergeSort (int *vet, int p, int r){ //Parametros: Ponteiro para Vetor -> inicio -> fim 
	if (p < r-1){ 
		int q;
		q = (p+r)/2; //Meio do vetor
		mergeSort(vet, p, q); // Vetor -> Inicio -> Meio
		mergeSort(vet, q, r); // Vetor -> Meio -> Fim
		merge(vet, p, q, r);  // Vetor -> inicio -> meio -> fim
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

	mergeSort(vetor, 0, n); // Parametros: Vetor -> indice inicial -> indice final
	printfVetor(vetor, n); // Parametros: Vetor -> tamanho do vetor
	return 0;
}
