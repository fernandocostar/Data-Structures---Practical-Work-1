#ifndef PILHA_H_
#define PILHA_H_

#include <stdio.h>

#define MAX 100

typedef struct pilha {
	char elementos[MAX];
	int topo;
} Pilha;

Pilha create();
char pop(Pilha *p);
void push(Pilha *p, char c);
int isEmpty(Pilha p);
int isFull(Pilha p);
int size(Pilha p);

#endif