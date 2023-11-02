#ifndef JOGADOR_H
#define JOGADOR_H
#include <stdio.h>
#include <string.h>

// Definição da estrutura dos dados do jogador
typedef struct {
    char nome[30]; // Variável para armazenar o nome do jogador
    int idade; // Variável para armazenar a idade do jogador
    char genero[30]; // Variável para armazenar o gênero do jogador
} dadosJogador;

// Função para capturar os dados do jogador
void jogador() {

    dadosJogador jogador; // Criação de uma instância de dadosJogador para armazenar os dados do jogador
    int dadosCorretos = 0; // Variável para controlar se os dados inseridos estão corretos

    printf("\n");

    do {
        // Solicitação e leitura dos dados do jogador
        printf("Escreva seu nome: \n");
        scanf("%s", jogador.nome);

        printf("Escreva sua idade: \n");
        scanf("%d", &jogador.idade);

        printf("Escreva seu genero: \n");
        scanf("%s", jogador.genero);

        // Exibição dos dados inseridos e verificação se estão corretos
        printf("Dados inseridos:\n");
        printf("Nome: %s\n", jogador.nome);
        printf("Idade: %d\n", jogador.idade);
        printf("Genero: %s\n", jogador.genero);

        char escolha;
        printf("Os seus dados estao corretos? (Digite S para Sim ou N para Nao): ");
        scanf(" %c", &escolha); 

        if (escolha == 'S' || escolha == 's') {
            dadosCorretos = 1; // Marca os dados como corretos e sai do loop
        } else {
            printf("Por favor, insira os dados novamente de forma correta.\n");
        }
    } while (!dadosCorretos); // Continua o loop até que os dados estejam corretos
}

#endif
