/*
Grupo:2
Aluno(s): Wellerson Prenholato de Jesus
		  Carlos Henrique F. L. da Fonseca
		  Hádamo da silva egito
		  Geraldo Nogueira
Curso: Ciência da Computação
*/

#include "permutar.h" //Biblioteca permutar definida em permutar.c
#include <ctype.h> //Utilizamos essa bilbioteca pois incluimos a função isalpha(). "isalpha()" verifica se o caracter é alfabético

#define MAX 256

// Funcao que verifica as entradas
void stringEntrada(char*);//Assinatura da função para verificar caracteres
char charEntrada(); //Assinatura da funçao para verificar entrada (para char)
int inteiroEntrada(); //Assinatura da funçao para verificar entrada(para inteiro)

void Ordena(fila**, int);//Organizar as caixas por quantidade de bolas : Ordem nao descrescente (Valores podem ser iguais na ordenação)

//Funçao utilizada para ordenação das caixas
void Ordena(fila **vet_caixa, int qnt_caixa){
	// Bubble Sort: Simples
	int i, j; 
	fila *aux;
	for(i = 0; i < qnt_caixa ; i++){
		for(j = i+1; j < qnt_caixa ; j++){
			if (quantidade_fila(vet_caixa[i]) > quantidade_fila(vet_caixa[j])){
				aux = vet_caixa[i];
				vet_caixa[i] = vet_caixa[j];
				vet_caixa[j] = aux;
			}
		}
	}
}

void stringEntrada(char* str){//Usado ao pedir (Cor de bolas)
	do{
		fgets(str, MAX, stdin); //Para receber a string
		str[strlen(str) - 1] = '\0'; // Remocao do \n do final da string
		if (!isalpha(str[0]))//Verifica se a entrada é um '\n' ou espaço, caso seja o usuário recebe uma mensagem para inserir um novo valor
			printf("Entrada Invalida!\nInforme novamente: ");
		else 
			break;
	}while(1);
}

char charEntrada(){//Função que verifica se a entrada é um char. Caso nao, pede para inserir um novo valor (Até que seja do tipo char)
	char str[MAX];
	do {
		fgets(str,MAX,stdin); //Para receber a string
		//Isalpha verifica se o caracter inserido é alguma letra do alfabeto
		if (strlen(str) == 2 && isalpha(str[0])) // isalpha(str[0]) = (str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')
			return str[0];
		else //Casao nao seja letra do alfabeto, pedimos ao usuario para inserir um novo valor
			printf("Entrada Invalida!\nInforme novamente: "); 
	} while (1);
}

int inteiroEntrada(){ //Faz verificação da entrada, se é realmente um número inteiro. Caso nao, pede para inserir um novo valor (Até que seja um inteiro)

	char *p, s[MAX];
	int n;

	while (fgets(s, sizeof(s), stdin)) { //Leitura da entrada como string
		n = strtol(s, &p, 10);//Conversao para inteiro, strtol converte a string ate o primeiro char diferente de um numero, retorna o numero convertido e aponta o char* ate a posicao que parou
		if (p == s || *p != '\n') { // Se o char que parou for igual o inicio ou diferente do ENTER, é considerado uma entrada invalida
			printf("Entrada Invalida!\nInforme novamente: ");
		} else if (n<=0){//Verifica se a quantidade de bolas e caixas inseridas é maior que zero
			printf("Entrada Invalida!\nInforme um valor maior que zero: ");
		} 
		else 
			break;
	}
	return n;
}

int main(int argc, char** arg){
	int i,j,k;
    int qnt_caixa; // Quantidade de caixas
	char str[MAX]; // Cor da caixa, que tem MAX como tamanho 256
	char c; // Caracter da Bola
	fila* aux;	// Auxiliar usado para ordenação das caixas em forma nao decrescente
	fila** vet_caixa; // Vetor de caixa que armazena as bolas

//Caso seja feita a entrada na linha de comando do terminal
	//Depois de ter digitado inserido o ./exec
		//Iremos inserir a cor da caixa e as respectivas bolas que estao contidas nesta caixa
			//Por exemplo: "./exec preta abc rosa hj", sendo preta a cor da caixa e abc suas respectivas bolas, e assim sucessivamente (Explicaçao mais detalhada no relatório na parte de compilação)
	if ((argc % 2 == 1) && argc != 1){ // Entrada de dados na linha de comando do terminal
		qnt_caixa = ((argc-1)/2); // argc conta quantas string foram digitadas, contando com o nome do programa, entao se subtrai 1 e divide por 2 para obter a quantidade de caixas
		vet_caixa = (fila**)calloc(qnt_caixa,sizeof(fila*)); // alocacao do vetor de filas
		for(i = 0; i < qnt_caixa; i++) // alocacao de cada posicao do vetor
			vet_caixa[i] = nova_fila(arg[2 * i + 1]);

		for(i = 0, k = 2; i < qnt_caixa; i++,k+=2){ // preenche cada fila
			for(j = 0; j < strlen(arg[k]) ; j++)
				insere_fila(vet_caixa[i],arg[k][j]);
		}
	} else { // entrada de dados manual
		printf("Informe a quantidade de caixas: ");
		qnt_caixa = inteiroEntrada(); //Insere a quantidade de caixas, e faz a verificação se o número é realmente inteiro
		vet_caixa = (fila**)calloc(qnt_caixa,sizeof(fila*));//Aloca a quantidade de caixa(s) inserida(s) anteriormente em uma fila
		for(i = 0; i < qnt_caixa; i++){ // Aloca cada posicao do vetor
			printf("Cor da Caixa %d: ",i+1);
			stringEntrada(str);//Chamada função para verificar entrada de string
			vet_caixa[i] = nova_fila(str); // Aloca espaco da caixa 
			printf("Informe a quantidade de bolas: ");
			j = inteiroEntrada(); //Inserção de quantidade de bolas referente a caixa[i], e verificaçao se o número é realmente inteiro
			for(k = 0; k < j; k++){//For para inserçao de bolas na caixa
				printf("Bola %d: ",k+1);
				c = charEntrada(); //Chamada da funcao de entrada do caracter da bola
				insere_fila(vet_caixa[i],c); //Inserção do caracter de cada bola, referente a caixa[i]
			}
		}
	}
	
	//Chamda da função para ordenação de caixas de forma nao decrescente
	Ordena(vet_caixa, qnt_caixa);

	//Chamada da função para permutar
	permutar(vet_caixa,qnt_caixa);

	// Libera memoria alocada
	for(i = 0; i < qnt_caixa ; i++)
		free_fila(vet_caixa[i]);
	free(vet_caixa);

	return 0;
}