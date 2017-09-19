#include "pilha.h"
#include <stdlib.h>

Pilha create(){
	Pilha p;
	p.topo = -1; //topo igual a -1 se quisermos declarar uma pilha nao vazia iniciando em 0, comum em programacao
	return p; //retornando o conteudo da memoria referente ao ponteiro p
}

char pop(Pilha* p){ //"remove" o elemento mais externo da pilha e o retorna
	if((*p).topo == -1){
		return '\\'; //se a pilha estiver vazia retorna -1
	}//se a pilha estiver vazia (topo = -1 definido acima) forcar parada do programa
	char retornar = (*p).elementos[(*p).topo]; //chegando ate aqui armazenamos o elemento do topo em retornar 
	(*p).topo--; //precisamos apenas decrementar o topo para informar a retirada de um elemento de acordo com a implementacao que estamos utilizando
	return retornar;
}

void push(Pilha *p, char c){
	if((*p).topo <= (MAX-1)){ //se a pilha nao estiver cheia (visto que comecamos nosso indice de 0 e o MAX definido foi 100)
		(*p).topo++; //aumentamos o topo em uma unidade
		(*p).elementos[(*p).topo] = c; //guardamos o elemento dado como sendo o novo topo
	}else{
		printf("Stack full.\n");
		exit(-1);
	}//se a pilha estourar forcar parada do programa
}

int isEmpty(Pilha p) {return p.topo == -1;} //verifica se esta vazia a partir do topo

int isFull(Pilha p) {return p.topo == (MAX-1);} //verifica se esta vazia a partir do topo

int size(Pilha p) {return p.topo + 1;} //retorna o tamanho da pilha somando um para representar a quantidade de itens
