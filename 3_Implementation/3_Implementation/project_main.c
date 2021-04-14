#include "hangman.h"
#include "handcricket.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Gaming Application...\n");
    printf("Available games are Hangman and Handcricket..\n");
    printf("For hangman enter 1\n");
    printf("For handcricket enter 2\n");
    int ch;
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:hangman();
        break;
        case 2:handcricket();
        break;
    }
    printf("Hope you enjoyed..!!");
}