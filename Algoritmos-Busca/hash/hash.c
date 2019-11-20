#include <stdio.h>
#include <stdlib.h>

//Constante definida para saber se naquele espaco um elemento foi deletado, equivale a 3 # que tem o valor 35
#define DELETE_CONST	-105
#define SUCCESS		   0
#define NOT_FOUND	  -1

int hash_insercao(int *t, int valor, int qtd);
int hash_busca(int *t, int valor, int qtd);
int hash_remove(int *t, int valor, int qtd);

int main(void){
	int *t;
	int valor;
	int qtd;
	scanf("%d", &qtd);
	t = (int *) calloc(qtd, sizeof(int));
	scanf("%d", &valor);
	hash_insercao(t, valor, qtd);
	printf("o elemento buscado esta na posicao: %d\n",hash_busca(t, valor, qtd));
	scanf("%d", &valor);
	hash_insercao(t, valor, qtd);
	printf("o elemento buscado esta na posicao: %d\n",hash_busca(t, valor, qtd));
	hash_remove(t, valor, qtd);

	return SUCCESS;
}

int hash_insercao(int *t, int valor, int qtd){
	int colisoes = 0;
	int flag = 0;
	while(!flag){
		int indice = (valor + colisoes) % qtd;
		//Se existe um elemento aqui, e nao eh uma const de delete, eh preciso adicionar 1 nas colisoes
		if(t[indice] && t[indice] != 105) colisoes++;
		else{
			t[indice] = valor;
			flag = 1;
		}
	}
	return SUCCESS;
}

int hash_busca(int *t, int valor, int qtd){
	int colisoes = 0;
	int flag = 0;
	while(!flag){
		int indice = (valor + colisoes) % qtd;
		if(t[indice] == valor) return indice;
		//Se existe um espaco em branco, o elemento nao esta na tabela
		else if(!t[indice]) flag = 1;
		else colisoes++;
	}
	return NOT_FOUND;
}

int hash_remove(int *t, int valor, int qtd){
	int indice = hash_busca(t, valor, qtd);
	//Se o indice for diferente do codigo de nao achado, entao deletar
	if(indice != NOT_FOUND) t[indice] = DELETE_CONST; 
	else return NOT_FOUND;
	return SUCCESS;
}

/*
 INSERÇÃO{
 
	 PASSO 1
	 qtd = 10;
	 valor = 100;
	 indice = (valor + colisoes) % qtd
	 indice = 0;
	 vetor[0] = 100;

	 PASSO 2
	 valor = 10
	 indice = (valor + colisoes) % qtd
	 indice = 0;
	 ja existe valor no indice 0
	 colisoes++
	 indice = (valor + colisoes) % qtd
	 indice = 1
	 vetor[1] = 10;
 }
 
 BUSCA{
 }
 
*/
