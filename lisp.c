#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/*TRABALHO 1 - ESTRUTURAS DE DADOS PARA SISTEMAS DE INFORMAÇÃO*/
//FERNANDO COSTA RODRIGUES - 116031058//

/*
SOBRE WARNINGS AO COMPILAR USANDO -O2 -Wall
- nesse programa nao temos a necessidade de armazenar o valor retornado pelas chamadas a funcao scanf
- considerando que nao sera passado um valor de pos invalido podemos ignorar o warning de que nivel pode ser retornado sem ser inicializado,
uma vez que sempre que tivermos um valor de pos dentro do escopo do programa a variavel nivel sera inicializada com cont ou entao nao sera
retornada
MESMO ASSIM O CODIGO SERA COMPILADO NORMALMENTE
*/

int resolve_lisp(char *texto, int pos, int tam){ //funcao que analisa o balanceamento de parenteses e o nivel do char no indice dado
	
	/* -1 RETORNA ERRO NO BALANCEAMENTO, CASO CONTRARIO O RETORNO SERA O NIVEL EM QUE O CARACTER DESEJADO SE ENCONTRA*/

	Pilha p = create(); //criando uma Pilha para armazenar os caracteres do codigo em Lisp
	int i, nivel, cont = 0; //declarando variaveis, sendo nivel o nivel onde o caracter no indice pos se encontrará e cont sera utilizado para o balanceamento de parenteses (numero de parenteses abertos)
	char atual; //variavel do tipo char que auxiliara na analise char por char a seguir

	for(i = 0; i <= tam; i++){ //adicionando todos os caracteres na pilha criada
		push(&p, texto[i]); //adicionamos o caracter lido da vez na pilha criada

		atual = pop(&p); //guardamos o caracter lido em uma variavel auxiliar retirando o ultimo elemento da pilha

		if(i == pos){
			nivel = cont; //caso estejamos na posicao desejada, resultado True, guardaremos como nivel o numero de parenteses abertos ate o momento	
		}
		if(atual == '('){
			cont++; //contador incrementa para cada parentese aberto.
		}else if(atual == ')'){
			cont--; //contador decrementa para cada parentese fechado
		}
		if(cont < 0){
			return -1; //ao fechar um parentese sem ter aberto um anteriormente retornamos -1, sinal de quebra de regra (ex.: (teste(n))(, retorna -1 na primeira iteração) 		
		}
	}

	if(cont == 0){
		return nivel; //se o programa chegou ate aqui ele seguiu a ordem dos parenteses, logo basta checar se ( e ) tem a mesma quantidade
	}
	
	return -1; //caso chegue aqui é sinal de que temos mais parenteses abrindo do que fechando, logo balanceamento incorreto
}

int main(){
	int i, num_chars, pos, resultado; //inicializando variaveis, num_chars o tamanho do codigo dado em caracteres, pos a posicao que queremos analisar e resultado o nivel encontrado para o char na posicao "pos"
    char elemento; //guardando o elemento para o print

	scanf("%d %d", &num_chars, &pos); //recebendo numero de caracteres e posicao

	char texto[num_chars]; //criando vetor com tamanho do codigo a ser dado (num_chars)
	for(i = 0; i <= num_chars; i++){
		scanf("%c", &texto[i]); //lendo e armazenando caracter por caracter do codigo dado
	}

	elemento = texto[pos]; //ja deixando armazenado o elemento na posicao desejada

    resultado = resolve_lisp(texto, pos, num_chars); //chamando funcao que resolve o problema dando o codigo, posicao desejada e tamanho em chars do codigo

    if(resultado != -1){ //se a funcao tiver retornado algo diferente de -1 (codigo de erro), imprimimos a frase dada no enunciado contendo elemento, que e o char na posicao pos e resultado sendo o nivel em que esse se encontra
        printf("O programa está correto e o elemento %c esta no nivel %d.\n", elemento, resultado);
        return 0;
    }
    printf("O programa está incorreto.\n"); //se o programa chegar aqui é porque tinha algo errado ( :c ), logo imprimimos a frase referente a esse estado
    return 0;
}