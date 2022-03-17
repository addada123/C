#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define true 1
#define false 0

int region;
char user;
char player = 'X';
int gameState = 0;
int mainMenu = 1;
int winnerState;
int height = 18;
int width = 18;

void board(player, region){
    int x = region * ((width / 6) - 1);
    int y = region * ((height / 6) - 1);

    for (int i = 0; i < width; i++){
        printf("*");
    }

    printf("\n");
    for (int i = 0; i < height; i++){
        printf("*");
        for(int j = 0; j < width - 2; j++){
            if (j == (width / 3) - 1 || j == 2 * (width / 3) - 1){
                printf("|");
            }
            else if(i == (width / 3) - 1 || i == 2 * (width / 3) - 1){
                printf("-");
            }
            else if(j == x && i == y){
                if (player == 'X'){
                    printf("X");
                }
                else if(player == '0'){
                    printf("0");
                }
                else{
                    printf(" ");
                }
            }
            else{
                printf(" ");
            }
        }
        printf("*\n");
    }

    for(int i = 0; i < width; i++){
        printf("*");
    }

    system("cls");
}

void functions(){
    
}

void main_Menu(){
    if(mainMenu == 1 && gameState == 0){
        printf("Welcome to the Tic Tac Toe!\n");
        printf("To play as X enter '1'!\n");
        printf("To play as O enter '2'!\n");
        printf("To read rules enter '3'\n");
        printf("If you want to quit enter 'Q'!\n");
        scanf(" %c", &user);
        if(user == '1'){
            player = 'X';
            gameState = 1;
            mainMenu = 0;
        }
        else if(user == '2'){
            player = 'O';
            gameState = 1;
            mainMenu = 0;
        }
        else if(user == '3'){
            printf("1. The game is played on a grid that's 3 squares by 3 squares.\n");
            printf("2. You are X, your friend (or the computer in this case) is O. Players take turns putting their marks in empty squares.\n");
            printf("3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n");
            printf("4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n");
        }
        else if(user == 'Q'){
            printf("Exiting the game!\n");
            gameState = 0;
            mainMenu = 0;
            return EXIT_SUCCESS;
        }
    }
}

int main() {
    while(true){
        board(player, 5);
    }
    return 0;
}