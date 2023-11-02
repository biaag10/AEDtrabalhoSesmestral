#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogador.h"
#include "cartas.h"
#include "monstros.h"

// Função para exibir as instruções do jogo
void exibirInstrucoes() {
    printf("===== INSTRUCOES =====\n");
    printf("Bem-vindo! O objetivo eh avançar pelo mapa, derrotar o chefe final e vencer o jogo. \n");
    printf("Voce comeca com um deck de 10 cartas e precisa tomar decisoes estrategicas para vencer os monstros e chefes. \n");
    printf("Use sua energia de forma sabia para jogar as cartas e derrotar os inimigos.\n");
    printf("Nao esqueca de descansar quando necessário para recuperar vida ou melhorar suas cartas.\n");
    printf("Boa sorte e bom jogo!\n");
    printf("======================\n");
}

// Função para exibir o menu principal
void menu() {
	
	// Inicialização do gerador de números aleatórios
	srand(time(NULL));
	
	// Inicialização dos monstros com suas características
    Monstro Elenilson = inicializarMonstro("Lele", 50, "Onda Sonora", "Coerencia");
    Monstro Mariana = inicializarMonstro("Mariana", 80, "Energia cinetica", "Cansaco");
    Monstro Luzia = inicializarMonstro("Lulu", 110, "Ataque de fluido", "Fofa e atenciosa");
    Monstro Edag = inicializarMonstro("EdagDevil", 140, "Imprevisibilidade", "Salva semestre");
    Monstro Zouza = inicializarMonstro("ZouzaBoss", 170, "Ja pode trancar", "Abstrair");
	
	int escolha;
    do {
        // Opções do menu
        printf("===== MENU =====\n");
        printf("1) Jogar \n");
        printf("2) Exibir Cartas \n");
        printf("3) Instrucoes \n");
        printf("4) Exibir Monstros \n");
        printf("5) Sair \n");
        printf("\n*-------------------*\n");
        printf("\nEscolha uma opcao: \n");
        scanf("%d", &escolha);

        switch (escolha) {
        	
            case 1:
                // Chama a função para jogar
                jogador();
			    printf("\n");
			    printf(" ____     ___    __  __         _    ___     ____    ___ \n| __ )   / _ \\  |  \\/  |       | |  / _ \\   / ___|  / _ \\ \n|  _ \\  | | | | | |\\/| |    _  | | | | | | | |  _  | | | |\n| |_) | | |_| | | |  | |   | |_| | | |_| | | |_| | | |_| |\n|____/   \\___/  |_|  |_|    \\___/   \\___/   \\____|  \\___/ ");
			    printf("\n");
				break; 
                
			case 2:
				// Chama a função para exibir o deck de cartas
				deckCartas();
				break;
            case 3:
                // Chama a função para exibir as instruções
                exibirInstrucoes();
                break;
                
            case 4:
                // Exibe os monstros e suas características
                printf("\n===== MONSTROS =====\n");
			    printf("\n");
			    printf("1) %s\n", Elenilson.nome);
			    printf("   Vida: %d\n", Elenilson.vida);
			    printf("   Ataque: %s\n", Elenilson.ataque);
			    printf("   Defesa: %s\n", Elenilson.defesa);
			    printf("\n");
			    
			    printf("2) %s\n", Mariana.nome);
			    printf("   Vida: %d\n", Mariana.vida);
			    printf("   Ataque: %s\n", Mariana.ataque);
			    printf("   Defesa: %s\n", Mariana.defesa);
			    printf("\n");

			    printf("3) %s\n", Luzia.nome);
			    printf("   Vida: %d\n", Luzia.vida);
			    printf("   Ataque: %s\n", Luzia.ataque);
			    printf("   Defesa: %s\n", Luzia.defesa);
			    printf("\n");
			    
			    printf("4) %s\n", Edag.nome);
			    printf("   Vida: %d\n", Edag.vida);
			    printf("   Ataque: %s\n", Edag.ataque);
			    printf("   Defesa: %s\n", Edag.defesa);
			    printf("\n");
			    
			    printf("5) %s\n", Zouza.nome);
			    printf("   Vida: %d\n", Zouza.vida);
			    printf("   Ataque: %s\n", Zouza.ataque);
			    printf("   Defesa: %s\n", Zouza.defesa);
			    printf("\n");
			    
			    break;
                
            case 5:
                // Mensagem de saída
                printf("Voce esta saindo do jogo. Ate a proxima! \n");
                break;
                
            default:
                // Mensagem de opção inválida
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
        
    } while (escolha != 5);
	
}

int main() {
    // Chama a função do menu
    menu();
    return 0;
}
