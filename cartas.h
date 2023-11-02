#ifndef CARTAS_H
#define CARTAS_H
#include <stdio.h>
#include <string.h>
#include "stack.h"

// Função para embaralhar as cartas usando pilha
void embaralharCartas(Carta deck[], PilhaCartas *pilha, int tamanho) {
    srand(time(NULL)); // Inicializa a geração de números aleatórios
    for (int i = 0; i < tamanho; i++) {
        int j = rand() % tamanho; // Gera um índice aleatório para a troca de cartas
        Carta temp = deck[i];
        deck[i] = deck[j]; // Troca as cartas no deck
        deck[j] = temp;
        push_carta(pilha, deck[i]); // Empilha as cartas durante o embaralhamento
    }
}

// Função para exibir as cartas do deck usando pilha
void exibirCartas(PilhaCartas *pilha) {
    for (int i = 0; i <= pilha->topo; i++) {
        printf("Carta %d:\n %s\n Valor: %d\n Custo: %d\n Tipo: %s\n\n", i + 1, pilha->cartas[i].nome, pilha->cartas[i].valor, pilha->cartas[i].custo, pilha->cartas[i].tipo);
    }
}

// Função para criar uma nova carta
Carta criarCarta(char *nome, int valor, int custo, char *tipo) {
    Carta novaCarta;
    strcpy(novaCarta.nome, nome); // Copia o nome para a nova carta
    novaCarta.valor = valor; // Define o valor da nova carta
    novaCarta.custo = custo; // Define o custo da nova carta
    strcpy(novaCarta.tipo, tipo); // Copia o tipo para a nova carta
    return novaCarta; // Retorna a nova carta
}

// Função para exibir o deck de cartas
void deckCartas() {
    Carta deck[MAX_CARTAS]; // Criação de um array para o deck de cartas
    
	// Criação de um deck de cartas com valores e tipos específicos
    deck[0] = criarCarta("Tirar duvida (*)", 5, 2, "Ataque");
	deck[1] = criarCarta("Derivar (**)", 5, 1, "Ataque");
	deck[2] = criarCarta("Pescar (***)", 7, 2, "Ataque"); 
	deck[3] = criarCarta("Recorrigir (****)", 8, 2, "Ataque");
	deck[4] = criarCarta("Ir na Maquina (*)", 2, 4, "Defesa");
	deck[5] = criarCarta("Cochilar (**)", 1, 5, "Defesa");
	deck[6] = criarCarta("All Mossar (***)", 7, 2, "Defesa");
	deck[7] = criarCarta("Codar (****)", 8, 3, "Defesa");
	deck[8] = criarCarta("Feriadao (*)", 10, 3, "Especial");
	deck[9] = criarCarta("Apresentacao (**)", 10, 2, "Especial");
	deck[10] = criarCarta("Gabaritar (***)", 16, 5, "Especial");
	deck[11] = criarCarta("Ponto Extra (****)", 16, 5, "Especial");
		
	printf("\nCartas:\n");
	
 	// Inicialização da pilha de cartas
    PilhaCartas pilha;
    inicializa_pilha_cartas(&pilha);

    // Embaralhamento das cartas e empilhamento na pilha
    embaralharCartas(deck, &pilha, MAX_CARTAS);

    // Exibição das cartas do deck embaralhado
    exibirCartas(&pilha);
}

#endif
