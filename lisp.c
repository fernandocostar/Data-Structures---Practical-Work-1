#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int resolve_lisp(char *texto, int pos, int tam){
	Pilha p = create();
	int i, nivel, cont = 0;
	char atual;
	for(i = 0; i <= tam; i++){
		push(&p, texto[i]);
	}

	for(i = 0; i <= tam; i++){
        atual = pop(&p);

        if(i == (tam-1) - pos) nivel = cont;
        if(atual == ')') cont++;
        else if(atual == '(') cont--;

        if(cont < 0) return -1;
	}

	if(cont == 0) return nivel;
	return -1;
}

int main(){
	int i, num_chars, pos, resultado;
    char elemento;

	scanf("%d %d", &num_chars, &pos);

	char texto[num_chars];
	for(i = 0; i <= num_chars; i++){
		scanf("%c", &texto[i]);
	}

	elemento = texto[pos];

    resultado = resolve_lisp(texto, pos, num_chars);

    if(resultado != -1){
        printf("O programa está correto e o elemento %c esta no nivel %d.\n", elemento, resultado);
        return 0;
    }
    printf("O programa está incorreto.\n");
    return 0;
}
