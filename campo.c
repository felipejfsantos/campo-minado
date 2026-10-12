#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int campo[9][9]; //0 > sem bomba; 1 > com bomba
int bombas[9][9]; //quantas bomas tem ao redor
char tela[9][9];
bool estadoJogo = true;

void inicializarMatriz(){
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            campo[i][j] = 0;
        }
    }
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            tela[i][j] = '#';
        }
    }
}

void imprimirMatriz(){
/*    printf("    1 2 3 4 5 6 7 8 9\n");
    printf("\n");
    for(int i = 0; i < 9; i++){
        printf("%d   ", i + 1); 
        for (int j = 0; j < 9; j++){
            printf("%d ", campo[i][j]);
        }
        printf("\n");
        
    }
    printf("------------------------------------------------\n");*/
    printf("    1 2 3 4 5 6 7 8 9\n");
    printf("\n");
    for(int i = 0; i < 9; i++){
        printf("%d   ", i + 1); 
        for (int j = 0; j < 9; j++){
            printf("%c ", tela[i][j]);
        }
        printf("\n");
        
    }
    printf("------------------------------------------------\n");
}

void sortearBomba(){
int i = 0; //quantidade de bombas na partida
srand(time(NULL));
    while(i < 9){
        int linha = rand() % 10;
        int coluna = rand() % 10;
        if (campo[linha][coluna] == 0){
            campo[linha][coluna] = 1;
            i++;
        }
    }
}

void exibirBombas(){                   
int n_bombas = 0;
        for(int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if(campo[i][j] == 0){
                    if(campo[i-1][j] == 1 && (i-1 >= 0)){
                        n_bombas++;
                    }       
                    if(campo[i+1][j] == 1 && (i+1 < 9)){
                        n_bombas++;
                    }
                    if(campo[i][j-1] == 1 && (j-1 >= 0)){
                        n_bombas++;
                    }       
                    if(campo[i][j+1] == 1 && (j+1 < 9)){
                        n_bombas++;
                    }
                    if(campo[i-1][j-1] == 1 && (i-1 >= 0) && (j-1 >= 0)){
                        n_bombas++;
                    }       
                    if(campo[i-1][j+1] == 1 && (i-1 >= 0) && (j+1 < 9)){
                        n_bombas++;
                    }
                    if(campo[i+1][j-1] == 1 && (i+1 < 9) && (j-1 >= 0)){
                        n_bombas++;
                    }       
                    if(campo[i+1][j+1] == 1 && (i+1 < 9) && (j+1 < 9)){
                        n_bombas++;
                    }
                }
                bombas[i][j] = n_bombas;
                n_bombas = 0;
            }
    }
/*    printf("    1 2 3 4 5 6 7 8 9\n");
    printf("\n");
    for(int i = 0; i < 9; i++){
        printf("%d   ", i + 1); 
        for (int j = 0; j < 9; j++){
            printf("%d ", bombas[i][j]);
        }
        printf("\n");
        
    }
    printf("------------------------------------------------\n");*/
}

int escolhaGesto(){
    int acao;
    printf("Escolha uma acao para realizar\n");
    printf("1 - Revelar slot\n");
    printf("2 - Marcar slot como bomba\n");
    printf("3 - Cancelar escolha\n");
    scanf("%d", &acao);
    return acao;
}

void alterarTela(int i, int j){
    int gesto = escolhaGesto();
    if(gesto == 2){
        tela[i][j] = 'B';
        imprimirMatriz();
    }
    else if(gesto == 1){
        srand(time(NULL));
        int quantidade = rand() % 8; //mostra até 8 quadrados ao redo do ponto escolhido
        if(campo[i][j] != 1){
            tela[i][j] = '0' + bombas[i][j];
            for(int k = 0; k < quantidade; k++){
                int slot = (rand() % 8) + 1;

                if(campo[i-1][j] != 1 && i-1 >= 0 && slot == 1){
                    tela[i-1][j] = '0' + bombas[i-1][j];// 1 esquerda
                }       
                if(campo[i+1][j] != 1 && (i+1 < 9) && slot == 2){ 
                    tela[i+1][j] = '0' + bombas[i+1][j];// 1 direita
                }
                if(campo[i][j-1] != 1 && (j-1 >= 0) && slot == 3){         
                    tela[i][j-1] = '0' + bombas[i][j-1];// 1 cima
                }       
                if(campo[i][j+1] != 1 && (j+1 < 9) && slot == 4){         
                    tela[i][j+1] = '0' + bombas[i][j+1];// 1 baixo
                }
                if(campo[i-1][j-1] != 1 && (i-1 >= 0) && (j-1 >= 0) && slot == 5){    
                    tela[i-1][j-1] = '0' + bombas[i-1][j-1];// 1 esquerda 1 cima
                }       
                if(campo[i-1][j+1] != 1 && (i-1 >= 0) && (j+1 < 9) && slot == 6){   
                    tela[i-1][j+1] = '0' + bombas[i-1][j+1];// 1 esquerda 1 baixo
                }
                if(campo[i+1][j-1] != 1 && (i+1 < 9) && (j-1 >= 0) && slot == 7){   
                    tela[i+1][j-1] = '0' + bombas[i+1][j-1];// 1 direita 1 cima
                }       
                if(campo[i+1][j+1] != 1 && (i+1 < 9) && (j+1 < 9) && slot == 8){   
                    tela[i+1][j+1] = '0' + bombas[i+1][j+1];// 1 direita 1 baixo
                }    
            }
            imprimirMatriz();
        }
        if(campo[i][j] == 1){
            estadoJogo = false;
            printf("Bomba!! Voce perdeu!!!\n");
        }
    }else if(gesto == 3){
    }

}

void conferirMatriz(){
    int bombasEncontradas = 0, numBombas = 0;
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
          if(campo[i][j] == 1){
            numBombas++;
          }
        }
    }
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if(campo[i][j] == 1 && tela[i][j] == 'B'){
                bombasEncontradas++;
            }
        }
    }
    if(bombasEncontradas == numBombas){
        estadoJogo = false;
        printf("Parabens, voce ganhou!!\n");
    }
}

void iniciarJogo(){
    int linha, coluna;
    inicializarMatriz();
    sortearBomba();
    imprimirMatriz();
    exibirBombas();
    while(estadoJogo == true){
        printf("Escolha um slot\n");
        printf("Selecione a linha: 1-9\n");
        scanf("%d", &linha);
        printf("Selecione a coluna: 1-9\n");
        scanf("%d", &coluna);
        if(linha >= 1 && linha <= 9 && coluna >= 1 && coluna <= 9){
            alterarTela(linha - 1, coluna - 1);
        }
        else{
            printf("Informe um numero valido!\n");
        }
        conferirMatriz();
    }
}

int main(){
    int r, q;
    do{
        printf("Deseja iniciar o jogo?\n");
        printf("1 - Sim\n");
        printf("0 - Nao\n");
        scanf("%d", &q);
            switch(q){
                case 1:
                iniciarJogo();
                printf("Continuar?\n");
                printf("1 - Sim\n");
                printf("0 - Nao\n");
                scanf("%d", &r);
                while(r != 1 && r != 0){
                    printf("Opcao invalida, responda!\n");
                    printf("Continuar?\n");
                    printf("1 - Sim\n");
                    printf("0 - Nao\n");
                    scanf("%d", &r);
                }
                case 0: printf("Ate a proxima!!"); break;
                default: printf("Opcao invalida, responda!\n");
                r = 1;
                break;
            
    }
    }while(r == 1);
    return 0;
}