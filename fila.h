#ifndef FILA_H
#define FILA_H
#include <stdio.h>

#define MAX 100

// Define o tipo de item da fila como inteiro
typedef int tp_item;

// Definindo a estrutura da fila
typedef struct {
	tp_item item[MAX]; // Array de itens da fila
	int ini, fim; // Índices de início e fim da fila
} tp_fila;

// Inicializa a fila
void inicializa_fila(tp_fila *f) {
	f->ini = f->fim = MAX - 1; // Inicializa o início e o fim da fila como MAX - 1
}

// Verifica se a fila está vazia
int fila_vazia(tp_fila *f) {
	if (f->ini == f->fim) return 1; // Retorna verdadeiro se o início e o fim da fila forem iguais
	return 0;
}

// Define a próxima posição na fila (sentido horário)
int proximo(int pos) { 
	if (pos == MAX - 1) return 0; // Retorna 0 se a posição for MAX - 1, caso contrário, retorna a posição + 1
	return ++pos;
}

// Verifica se a fila está cheia
int fila_cheia(tp_fila *f) {
	if (proximo(f->fim) == f->ini) return 1; // Retorna verdadeiro se a próxima posição após o fim for igual ao início
	return 0;
}

// Insere um elemento na fila
int insere_fila(tp_fila *f, tp_item e) { 
	if (fila_cheia(f)) return 0; // Retorna 0 se a fila estiver cheia e não puder adicionar mais elementos
	f->fim = proximo(f->fim); // Atualiza o índice do fim da fila
	f->item[f->fim] = e; // Insere o item no fim da fila
	return 1;
}

// Remove um elemento da fila
int remove_fila(tp_fila *f, tp_item *e) { 
	if (fila_vazia(f)) return 0; // Retorna 0 se a fila estiver vazia e não puder remover elementos
	f->ini = proximo(f->ini); // Atualiza o índice do início da fila
	*e = f->item[f->ini]; // Atribui o item removido a uma variável
	return 1;
}

// Imprime os elementos da fila
void imprime_fila(tp_fila f) { 
	tp_item e;
	while(!fila_vazia(&f)) {
		remove_fila(&f, &e); // Remove e imprime os elementos da fila
		printf("\n%d", e);
	}
}

// Duas opções de código para determinar o tamanho da fila
int tamanho_fila(tp_fila *f) {
	if (fila_vazia(f)) return 0; // Retorna 0 se a fila estiver vazia
	if ((f->ini) < (f->fim)) return ((f->fim) - (f->ini)); // Retorna a diferença entre o fim e o início se o início for menor que o fim
	return ((MAX - 1) - (f->ini) + (f->fim) + 1); // Retorna a diferença total se o início for maior que o fim
}

int tamanho_fila1(tp_fila f) {
	int cont = 0;
	tp_item e;
	while(!fila_vazia(&f)) {
		remove_fila(&f, &e); // Remove e conta os elementos da fila
		cont++;
	}
	return cont;
}

#endif
