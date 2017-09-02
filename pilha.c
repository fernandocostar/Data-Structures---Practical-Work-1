#include "pilha.h"
#include <stdlib.h>

Pilha create(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p -> topo = -1;
	return (*p);
}

char pop(Pilha* p){
	if((*p).topo == -1) return '\\';
	char retornar = (*p).elementos[(*p).topo];
	p -> topo--;
	return retornar;
}

void push(Pilha *p, char c){
	if((*p).topo <= 99){
		p -> topo++;
		(*p).elementos[(*p).topo] = c;
	}else{
		printf("Your stack is full.\n");
	}
}

int isEmpty(Pilha p) {return p.topo == -1;}

int isFull(Pilha p) {return p.topo == 99;}

int size(Pilha p) {return p.topo + 1;}



