#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int throw_dice(void) ;

int main(){

    printf("Welcome to Crabs Game...\n");
    printf("About The Crabs Game:\n\tCrabs Game is very common gambling game. The basic idea is the player throws two dice at the same time.\n");
    printf("The dices have points on its face like regular dice. When dices' movement is stop, the numbers on upper faces\nare summed up. ");
    printf("If this sum is equals to 7 or 11 on very first throw of the dices,\nthe player wins the game. If it's equals to 2,3 or 12 on the first throw, the player loses the game.\n");
    printf("(This is also called Craps.)If the sum of numbers is not equals to none of these numbers,\nthat sum of numbers will be players number goal to win the game. The player has\n");
    printf("to throw the dices to reach that number to win the game. In the meantime if the player throws up dices\nthat has the sum of 7 you'll lost the game... \n\n");

    int counter=1,sum,current=0,goal=0;
    srand(time(NULL));
    sum=throw_dice();
    printf("You threw up %d\n",sum);

    do{

        if(counter==1){
            switch(sum){
                case 7: case 11:
                    printf("Congratulations! You won at the first time...\n");
                    break;
                case 2: case 3: case 12:
                    printf("Crabs! You lost the game...\n");
                    break;
                default:
                    goal=sum;
                    printf("Your goal is %d\n",goal);
                    current=throw_dice();
                    printf("You threw up %d\n",current);
                    counter++;
                    break;
                    }
            }
        if(current==goal&&counter!=1){
            printf("Congratulations! You won the game...\n");
            }
        else if (current==7&&counter!=1){
            printf("You lost the game...\n");
            break;
            }

        else if(current!=goal&&counter!=1){
            current=throw_dice();
            printf("You threw up %d\n",current);
            counter++;
            if(current==goal){
                printf("You won the game...\n");
                }

        }

        }while(current!=goal);

        printf("Throw up counter: %d\n",counter);

    return 0;
}

int throw_dice(){

    int dice1,dice2,sum;
    dice1=1+rand()%6;
    dice2=1+rand()%6;
    sum=dice1+dice2;

    return sum;

}


