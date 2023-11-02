#ifndef MONSTROS_H
#define MONSTROS_H
#include <stdio.h>
#include <string.h>
#include "fila.h"

// Definição da estrutura Monstro
typedef struct {
    int vida;
    char ataque[30];
    char defesa[30];
    char *nome;
    tp_fila acoes; // Fila de ações do monstro
} Monstro;

// Função para inicializar o Monstro com as características fornecidas
Monstro inicializarMonstro(char *nome, int vida, char *ataque, char *defesa) {
    Monstro monstro; 
    monstro.nome = nome; // Atribui o nome ao monstro
    monstro.vida = vida; // Atribui a vida ao monstro
    strcpy(monstro.ataque, ataque); // Atribui o ataque ao monstro
    strcpy(monstro.defesa, defesa); // Atribui a defesa ao monstro
    inicializa_fila(&(monstro.acoes)); // Inicializa a fila de ações do monstro
    return monstro; // Retorna o monstro devidamente configurado
}

// Função para executar a ação do monstro
void executarAcaoDoMonstro(Monstro *monstro) {
    tp_item acao;
    if (remove_fila(&(monstro->acoes), &acao)) {
        // Imprime a ação realizada pelo monstro com base no valor da acao
        printf("%s realiza acao: %d\n", monstro->nome, acao);
        // Lógica para executar a ação do monstro com base no valor de acao
    } else {
        printf("%s nao tem acoes para realizar.\n", monstro->nome); // Imprime se o monstro não tem ações para realizar
    }
}

// Função para escolher a ação do monstro
void escolherAcaoDoMonstro(Monstro *monstro, tp_item acao) {
    // Esvazia a fila antes de adicionar novas ações
    while (!fila_vazia(&(monstro->acoes))) {
        tp_item temp;
        remove_fila(&(monstro->acoes), &temp);
    }
    insere_fila(&(monstro->acoes), acao); // Insere a ação na fila de ações do monstro
}

#endif
