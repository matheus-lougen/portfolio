#include<stdio.h>


void mostrarTabuleiro(int tabuleiroNumerico[3][3]) {
    char tabuleiro[3][3];
    char caractere;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (tabuleiroNumerico[i][j]){
                case -1:
                    caractere = 'O';
                    break;

                case 0:
                    caractere = ' ';
                    break;

                case 1:
                    caractere = 'X';
                    break;
            }
            tabuleiro[i][j] = caractere;
        }
    }
    system("cls");
    printf("  0 | 1 | 2 \n");
    printf("0 %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("-----------\n");
    printf("1 %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("-----------\n");
    printf("2 %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

int converterSomaEmGanhador (int soma, int ganhadorAtual) {
    switch (soma) {
    case 3:
        return 1;
        break;
    case -3:
        return -1;
        break;
    default:
        return ganhadorAtual;
        break;
    }
}

int checarGanhador (int tabuleiroNumerico[3][3]) {
    // '-1': O Ganhou
    // '0': Houve um empate
    // '1': X Ganhou
    // '2': Ainda há pelo menos uma jogada possível

    int i;
    int j;
    int ganhador = 0;
    int somaLinha = 0;
    int somaColuna = 0;
    int somaDiagonal = 0;
    int somaDiagonalInvertida = 0;

    // Checa as linhas e colunas do tabuleiro
    for (i = 0; i < 3; i++) {
        somaLinha = 0;
        somaColuna = 0;
        for (j = 0; j < 3; j++) {
            somaLinha += tabuleiroNumerico[i][j];
            somaColuna += tabuleiroNumerico[j][i];
        }
        
        ganhador = converterSomaEmGanhador(somaLinha, ganhador);
        ganhador = converterSomaEmGanhador(somaColuna, ganhador);
        
    }


    // Checa uma das diagonais do tabuleiro
    somaDiagonal = tabuleiroNumerico[0][0] + tabuleiroNumerico[1][1] + tabuleiroNumerico[2][2];
    ganhador = converterSomaEmGanhador(somaDiagonal, ganhador);

    // Checa a outra diagonal do tabuleiro
    somaDiagonalInvertida = tabuleiroNumerico[2][0] + tabuleiroNumerico[1][1] + tabuleiroNumerico[0][2];
    ganhador = converterSomaEmGanhador(somaDiagonalInvertida, ganhador);

    if (ganhador != 0) {
        return ganhador;
    }

    // Checa se ainda há jogadas possíveis no tabuleiro
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiroNumerico[i][j] == 0) {
                return 0;
            }
        }
    }
    return 2;
}

int main() {
    int coordX = 0;
    int coordY = 0;
    int jogadorAtual = 1;
    int ganhador = 0;
    int tabuleiroNumerico[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    printf("Bem-vindo ao jogo da velha!\n");
    printf("------------------------------------\n");
    mostrarTabuleiro(tabuleiroNumerico);
    while (ganhador == 0) {
        if (jogadorAtual == 1) {
            printf("Digite as coordenadas em que deseja colocar o 'X' (Coluna, Linha)\n> ");
            scanf("%d %d",&coordY, &coordX);
            if (tabuleiroNumerico[coordX][coordY] != 0) {
                printf("Essa posicao ja foi escolhida, por favor escolha outra!\n");
            } else {
                tabuleiroNumerico[coordX][coordY] = 1;
                jogadorAtual = -1;    
            }
        } else if (jogadorAtual == -1) {
            printf("Digite as coordenadas em que deseja colocar o 'O' (Coluna, Linha)\n> ");
            scanf("%d %d",&coordY, &coordX);
            if (tabuleiroNumerico[coordX][coordY] != 0) {
                printf("Essa posicao ja foi escolhida, por favor escolha outra!\n");
            } else {
                tabuleiroNumerico[coordX][coordY] = -1;
                jogadorAtual = 1;    
            }
        }
        
        ganhador = checarGanhador(tabuleiroNumerico);
        mostrarTabuleiro(tabuleiroNumerico);
    }
    switch (ganhador)5
    {
    case 2:
        printf("Parece que houve um empate!\n");
        break;
    case -1:
        printf("O jogador 'O' ganhou!\n");
        break;
    case 1:
        printf("O jogador 'X' ganhou!\n");
        break;
    
    default:
        break;
    }
    system("pause");
}
