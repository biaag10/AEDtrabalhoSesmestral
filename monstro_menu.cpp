#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// #include <locale.h>

// Instru��es do jogo
void exibirInstrucoes() {
    printf("===== INSTRUCOES =====\n");
    printf("Bem-vindo! O objetivo eh avan�ar pelo mapa, derrotar o chefe final e vencer o jogo. \n");
    printf("Voce comeca com um deck de 10 cartas e precisa tomar decisoes estrategicas para vencer os monstros e chefes. \n");
    printf("Use sua energia de forma sabia para jogar as cartas e derrotar os inimigos.\n");
    printf("Nao esqueca de descansar quando necess�rio para recuperar vida ou melhorar suas cartas.\n");
    printf("Boa sorte e bom jogo!\n");
    printf("======================\n");
}

typedef struct {
  int vida;
  char ataque[30];
  char defesa[30];
  char *nome;
  char acao[30]; // A��o atual do monstro
} Monstro;

//  fun��o � �til para criar monstros de forma mais conveniente, fornecendo os valores de nome, vida, ataque e defesa como 
// argumentos, e ela retorna um monstro devidamente configurado com essas informa��es
Monstro inicializarMonstro(char *nome, int vida, char *ataque, char *defesa) {
    Monstro monstro; // vari�vel do tipo Monstro chamada monstro
    monstro.nome = nome;
    monstro.vida = vida;
    // Copia as strings dos par�metros ataque e defesa para os campos ataque e defesa da estrutura monstro
	// Permite definir os ataques e defesas do monstro com base nos valores fornecidos como argumentos
    strcpy(monstro.ataque, ataque); 
    strcpy(monstro.defesa, defesa);
    return monstro;
}

// Fun��o para executar a a��o do monstro
void executarAcaoDoMonstro(Monstro *monstro) {
    printf("%s realiza acao: %s\n", monstro->nome, monstro->acao);
    // L�gica para executar a a��o do monstro
    // Aqui voc� pode implementar o comportamento do monstro
}

// Fun��o para escolher e definir a a��o do monstro no in�cio da rodada
void escolherAcaoDoMonstro(Monstro *monstro) {
    // Gere uma a��o aleat�ria entre ataque, defesa e especial
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

int main() {
	//setlocale(LC_ALL, "pt_BR.utf8");
	//setlocale(LC_ALL, �Portuguese�);
	
	srand(time(NULL));

    // Inicializar monstros com suas caracter�sticas
    Monstro Soussa = inicializarMonstro("Sussa", 5, "Ja pode trancar", "Abstrair");
    Monstro Luzia = inicializarMonstro("Lulu", 5, "Ataque de fluido", "Fofa e atenciosa");
    Monstro Elenilson = inicializarMonstro("Lele", 5, "Onda Sonora", "Coerencia");
    Monstro Mariana = inicializarMonstro("Mariana", 5, "Energia cinetica", "Cansaco");

	
    int escolha;
    do {
        printf("===== MENU =====\n");
        printf("1) Jogar \n");
        printf("2) Instrucoes \n");
        printf("3) Monstros \n");
        printf("4) Sair \n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
        	
            case 1:
                // L�gica do jogo 
                printf(" \n");
                break;
                
            case 2:
                exibirInstrucoes();
                break;
                
            case 3:
                printf("===== MONSTROS =====\n");
			    printf("\n");
			    printf(" _______________________\n");
			    printf("|                       |        ___\n");
			    printf("|        %s          |      _/o o\\_\n", Soussa.nome);
			    printf("|-----------------------|     /_  ^  _\\\n");
			    printf("| Vida: %d               |      |/   \\|\n", Soussa.vida);
			    printf("| Atk:  %s |      |\\___/|\n", Soussa.ataque);
			    printf("| Def:  %s        |     /       \\\n", Soussa.defesa);
			    printf("|_______________________|    /_________\\\n");
			    
			    printf("\n\n");

			    printf("2) %s\n", Luzia.nome);
			    printf("   Vida: %d\n", Luzia.vida);
			    printf("   Ataque: %s\n", Luzia.ataque);
			    printf("   Defesa: %s\n", Luzia.defesa);
			    printf("\n");
			    
			    printf("3) %s\n", Elenilson.nome);
			    printf("   Vida: %d\n", Elenilson.vida);
			    printf("   Ataque: %s\n", Elenilson.ataque);
			    printf("   Defesa: %s\n", Elenilson.defesa);
			    printf("\n");
			    
			    printf("4) %s\n", Mariana.nome);
			    printf("   Vida: %d\n", Mariana.vida);
			    printf("   Ataque: %s\n", Mariana.ataque);
			    printf("   Defesa: %s\n", Mariana.defesa);
			    printf("\n");
			    break;
                
            case 4:
                printf("Voce esta saindo do jogo. Ate a proxima! \n");
                break;
                
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
        
    } while (escolha != 4);

    return 0;
}

