// Ana Carolina Silva de Souza; Bianca Andrade Galvão; Diego Perpétuo Andrade de Oliveira; João Pedro Borges Matos Rocha; Rafael Athaliba Bomfim Fraga.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
        char nome[30];
        int idade;
        char genero[30];
} dadosJogador;

typedef struct {
	    char nome[20];
	    char tipo[10];
	    int valor;
	    int custo;
} Carta;

typedef struct {
  int vida;
  char ataque[30];
  char defesa[30];
  char *nome;
  char acao[30]; // Ação atual do monstro
} Monstro;

void jogador() {

    dadosJogador jogador;
    int dadosCorretos = 0;

    printf("\n");

    do {
        printf("Escreva seu nome: \n");
        scanf("%s", jogador.nome);

        printf("Escreva sua idade: \n");
        scanf("%d", &jogador.idade);

        printf("Escreva seu genero: \n");
        scanf("%s", jogador.genero);

        // Exiba os dados inseridos pelo jogador e pergunte se eles estão corretos
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
    } while (!dadosCorretos);
}

// Função para embaralhar o deck de cartas
void embaralharCartas(Carta deck[], int tamanho) {
	    srand(time(NULL));
	    int i;
	    tamanho = 12;
	    for (i = 0; i < tamanho; i++) {
	        int j = rand() % tamanho;
	        Carta temp = deck[i];
	        deck[i] = deck[j];
			deck[j] = temp;
	    }
}

// Função para exibir as cartas do deck
void exibirCartas(Carta deck[], int tamanho) {
	int i;
	tamanho = 12;
	for (i = 0; i < tamanho; i++) {
	    printf("Carta %d:\n %s\n Valor: %d\n Custo: %d\n Tipo: %s\n\n", i + 1, deck[i].nome, deck[i].valor, deck[i].custo, deck[i].tipo);
	}
	    
}

// Função para criar uma nova carta

Carta criarCarta(char *nome, int valor, int custo, char *tipo) {
	    Carta novaCarta;
	    strcpy(novaCarta.nome, nome);
	    novaCarta.valor = valor;
	    novaCarta.custo = custo;
	    strcpy(novaCarta.tipo, tipo);
	    return novaCarta;
}

void deckCartas() {
    Carta deck[52];
	
	// Criação de um deck de cartas
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
		
	int tamanhoDeck = 3;
	
	printf("\nCartas:\n");
 	embaralharCartas(deck, tamanhoDeck);	            
	exibirCartas(deck, tamanhoDeck);
}

// Instruções do jogo
void exibirInstrucoes() {
    printf("===== INSTRUCOES =====\n");
    printf("Bem-vindo! O objetivo eh avançar pelo mapa, derrotar o chefe final e vencer o jogo. \n");
    printf("Voce comeca com um deck de 10 cartas e precisa tomar decisoes estrategicas para vencer os monstros e chefes. \n");
    printf("Use sua energia de forma sabia para jogar as cartas e derrotar os inimigos.\n");
    printf("Nao esqueca de descansar quando necessário para recuperar vida ou melhorar suas cartas.\n");
    printf("Boa sorte e bom jogo!\n");
    printf("======================\n");
}

//  função é útil para criar monstros de forma mais conveniente, fornecendo os valores de nome, vida, ataque e defesa como 
//  argumentos, e ela retorna um monstro devidamente configurado com essas informações
Monstro inicializarMonstro(char *nome, int vida, char *ataque, char *defesa) {
    Monstro monstro; // variável do tipo Monstro chamada monstro
    monstro.nome = nome;
    monstro.vida = vida;
    // Copia as strings dos parâmetros ataque e defesa para os campos ataque e defesa da estrutura monstro
	// Permite definir os ataques e defesas do monstro com base nos valores fornecidos como argumentos
    strcpy(monstro.ataque, ataque); 
    strcpy(monstro.defesa, defesa);
    return monstro;
}

// Função para executar a ação do monstro
void executarAcaoDoMonstro(Monstro *monstro) {
    printf("%s realiza acao: %s\n", monstro->nome, monstro->acao);
    // Lógica para executar a ação do monstro
    // Aqui você pode implementar o comportamento do monstro
}

// Função para escolher e definir a ação do monstro no início da rodada
void escolherAcaoDoMonstro(Monstro *monstro) {
    // Gere uma ação aleatória entre ataque, defesa e especial
    int escolha = rand() % 3;
    
    if (escolha == 0) {
        strcpy(monstro->acao, monstro->ataque);
    } 
	else if (escolha == 1) {
        strcpy(monstro->acao, monstro->defesa);
    } 
	else {
        strcpy(monstro->acao, "Especial");
    }
}

void menu() {
	
	srand(time(NULL));
	
	// Inicializar monstros com suas características
    Monstro Elenilson = inicializarMonstro("Lele", 50, "Onda Sonora", "Coerencia");
    Monstro Mariana = inicializarMonstro("Mariana", 80, "Energia cinetica", "Cansaco");
    Monstro Luzia = inicializarMonstro("Lulu", 110, "Ataque de fluido", "Fofa e atenciosa");
    Monstro Edag = inicializarMonstro("EdagDevil", 140, "Imprevisibilidade", "Salva semestre");
    Monstro Zouza = inicializarMonstro("ZouzaBoss", 170, "Ja pode trancar", "Abstrair");
	
	int escolha;
    do {
        printf("===== MENU =====\n");
        printf("1) Jogar \n");
        printf("2) Exibir Cartas \n");
        printf("3) Instrucoes \n");
        printf("4) Exibir Monstros \n");
        printf("5) Sair \n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
        	
            case 1:
                // JOGADOR
                jogador();
			    printf("\n");
			    printf(" ____     ___    __  __         _    ___     ____    ___ \n| __ )   / _ \\  |  \\/  |       | |  / _ \\   / ___|  / _ \\ \n|  _ \\  | | | | | |\\/| |    _  | | | | | | | |  _  | | | |\n| |_) | | |_| | | |  | |   | |_| | | |_| | | |_| | | |_| |\n|____/   \\___/  |_|  |_|    \\___/   \\___/   \\____|  \\___/ ");
			    printf("\n");
				break; 
                
			case 2:
                deckCartas();
                break;
                
            case 3:
                exibirInstrucoes();
                break;
                
            case 4:
                printf("===== MONSTROS =====\n");
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
                printf("Voce esta saindo do jogo. Ate a proxima! \n");
                break;
                
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
        
    } while (escolha != 5);
	
}

int main() {
	
	menu();
	
    return 0;
}
