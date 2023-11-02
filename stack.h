#ifndef stack_h
#define stack_h
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARTAS 12

// Definição da estrutura Carta
typedef struct {
    char nome[20];
    char tipo[10];
    int valor;
    int custo;
} Carta;

// Definição da estrutura PilhaCartas
typedef struct {
    Carta cartas[MAX_CARTAS]; // Array de cartas na pilha
    int topo; // Índice do topo da pilha
} PilhaCartas;

// Inicialização da pilha de cartas
void inicializa_pilha_cartas(PilhaCartas *pilha) {
    pilha->topo = -1; // Inicializa o topo da pilha como -1
}

// Verifica se a pilha está vazia
int pilha_vazia_cartas(PilhaCartas *pilha) {
    return (pilha->topo == -1); // Retorna verdadeiro se o topo da pilha for -1
}

// Verifica se a pilha está cheia
int pilha_cheia_cartas(PilhaCartas *pilha) {
    return (pilha->topo == MAX_CARTAS - 1); // Retorna verdadeiro se o topo da pilha for MAX_CARTAS - 1
}

// Insere uma carta na pilha
void push_carta(PilhaCartas *pilha, Carta carta) {
    if (!pilha_cheia_cartas(pilha)) { // Verifica se a pilha não está cheia
        pilha->topo++; // Aumenta o topo da pilha
        pilha->cartas[pilha->topo] = carta; // Insere a carta no topo da pilha
    } else {
        printf("A pilha de cartas está cheia.\n"); // Imprime uma mensagem se a pilha estiver cheia
    }
}

// Remove uma carta da pilha
Carta pop_carta(PilhaCartas *pilha) {
    if (!pilha_vazia_cartas(pilha)) { // Verifica se a pilha não está vazia
        Carta carta = pilha->cartas[pilha->topo]; // Atribui a carta no topo da pilha a uma variável
        pilha->topo--; // Diminui o topo da pilha
        return carta; // Retorna a carta removida
    } else {
        printf("A pilha de cartas está vazia.\n"); // Imprime uma mensagem se a pilha estiver vazia
        Carta carta_vazia;
        strcpy(carta_vazia.nome, ""); // Cria e retorna uma carta vazia se a pilha estiver vazia
        return carta_vazia;
    }
}

#endif
