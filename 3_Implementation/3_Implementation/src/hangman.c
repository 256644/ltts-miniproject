/**
 * @file hangman.c
 * @author ramya name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "hangman.h"

/**
 * @brief it prints the 2 dimensional array in which the hangman is drawn
 * 
 * @param arr it is a 2 dimenional array
 */
void print(char arr[][5])
{
 int i,j;
  for(i=0;i<6;i++)
 {
  for(j=0;j<5;j++)
  {
   printf("%c",arr[i][j]);
  }
  printf("\n");
 }
}
/**
 * @brief it gives the indexes at which the hangman characters should be drawn
 * @param wrong the number of times the user guessed it wrong
 * @return int 
 */
int i_value(int wrong)
{
 if(wrong==1)
 {
  return (2);
 }
 if(wrong==2)
 {
  return (3);
 }
 if(wrong==3)
 {
  return (4);
 }
 if(wrong==4)
 {
  return (3);
 }
 if(wrong==5)
 {
  return (3);
 }
 if(wrong==6)
 {
  return(5);
 }
 if(wrong==7)
 {
  return(5);
 }
}
/**
 * @brief similar to that of the above description
 * 
 * @param wrong 
 * @return int 
 */
int j_value(int wrong)
{
 if(wrong==1)
 {
  return (2);
 }
 if(wrong==2)
 {
  return(2);
 }
 if(wrong==3)
 {
  return (2);
 }
 if(wrong==4)
 {
  return (1);
 }
 if(wrong==5)
 {
  return(3);
 }
 if(wrong==6)
 {
  return (1);
 }
 if(wrong==7)
 {
  return(3);
 }
}
/**
 * @brief it checks if the character that is guessed is wrong or not
 * 
 * @param wtg word to guess
 * @param key the key pressed by the user to guess
 * @param length the length of the array
 * @param player the word that is displayed to the player after guess
 * @return int returns 1 if the word that is guessed is present if not it return2 0
 */
int check(char *wtg,char key,int length,char *player)
{
 int i=0,flag=0;
 for(i=0;i<length;i++)
 {
  if(*(wtg+i)==key)
  {
   *(player+i)=key;
   flag=1;
  }
 }
 if(flag==1)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}
/**
 * @brief function which takes the users name
 * 
 * @param val it is a structure which contains the template of the users data 
 * @param num it talks about the number of plauyers
 */
void users_name(hangman_user *val,int num)
{
 int i=0;
 for(i=0;i<num;i++)
 {
  printf("%d USERS NAME:\n",i+1);
  scanf("%s",(val+i)->user_name);
 }
}
/**
 * @brief acts as a main function which takes number of players 
 * as input and calls other function.
 * 
 */
void hangman()
{
 int num_p,i=1;
 int num_p_c;
 printf("WELCOME TO HANGMAN\n");
 printf("HAPPY PLAYING..!!");
 printf("\n Enter the number of players:");
 scanf("%d",&num_p);
 num_p_c=num_p;
 hangman_user *players;
 /**
  * @brief takes the input of number of players who are playing
  * 
  */
 players=(hangman_user *)calloc(num_p,sizeof(hangman_user));
 printf("Enter players name:\n");
 users_name(players,num_p);
 /**
  * @brief initialising the users point as zero
  * 
  */
 for(i=0;i<num_p;i++)
 {
  players[i].user_p=0;
 }
 printf("\nEnter the number of rounds:");
 int num_rounds;
 int round=0;
 scanf("%d",&num_rounds);
 /**
  * @brief this loop will continue for the number of ounds that was given
  * 
  */
 while(num_rounds--)
 {
  int k=0;
  printf("round=%d\n",round+1);
  /**
   * @brief this loop will continue for the number of players
   * 
   */
  while(num_p--)
  {
   /**
    * @brief to initialize array after each player has completed his turn
    * 
    */
   char arr[6][5]={' ',' ','_','_','_',
      ' ',' ','|',' ','|',
      ' ',' ',' ',' ','|',
      ' ',' ',' ',' ','|',
      ' ',' ',' ',' ','|',
      ' ',' ',' ',' ','|'};
  printf("%s turn\n",players[k].user_name);
  char word_t_guess[100];
  int tries=6,j=0,tries_p=6;
  int lenght_of_word,wrong_g=0;
   printf("\nEnter the word to guess and make sure the one whose turn is not seeing this\n");
   scanf("%s",word_t_guess);
   system("cls");
   lenght_of_word=strlen(word_t_guess);
   char *player_word;
   player_word=(char *)calloc(lenght_of_word,sizeof(char));
   for(i=0;i<lenght_of_word;i++)
   {
    player_word[i]='-';
   }
  /**
   * @brief this loop will take care of the number of tries that id pending
   * 
   */
   while(j<tries)
   {
    char a[2],check1=0;
    printf("\n%d tries pending\n",tries_p);
    printf("enter the character you are guessing  should nt be a number\n");
    scanf("%s",a);
    check1=check(word_t_guess,a[0],lenght_of_word,player_word);
    /**
     * @brief Construct a new if object
     * if the guessed character is present in the word 
     * 
     */
    if(check1==1)
    {
     printf("good work\n");
      printf("%s\n",player_word);
      print(arr);
      if(strcmp(player_word,word_t_guess)==0)
      {
       printf("%s guessed it right\n",players[k].user_name);
       players[k].user_p+=10;
       break;
      }
    }
    /**
     * @brief if the guessed character is not present in the word
     * 
     */
    else
    {
     int pos1,pos2;
     wrong_g++;
     /**
      * @brief Construct a new if object
      * the if is used to draw the hagman each time the user failes to guess the character that is present
      * 
      */
     if(wrong_g==1)
     {
      pos1=i_value(wrong_g);
      pos2=j_value(wrong_g);
      arr[pos1][pos2]='O';
     }
     else if(wrong_g==2)
     {
      pos1=i_value(wrong_g);
      pos2=j_value(wrong_g);
      arr[pos1][pos2]='|';
      wrong_g++;
      pos1=i_value(wrong_g);
      pos2=j_value(wrong_g);
      arr[pos1][pos2]='|';
     }
     else if(wrong_g==4)
     {
      pos1=i_value(wrong_g);
      pos2=j_value(wrong_g);
      arr[pos1][pos2]='/';
     }
     else if(wrong_g==5)
     {
      pos1=i_value(wrong_g);
      pos2=j_value(wrong_g);
      arr[pos1][pos2]='\\';
     }
     else if(wrong_g==6)
     {
      pos1=i_value(wrong_g);
      pos2=j_value(wrong_g);
      arr[pos1][pos2]='/';
     }
     else if(wrong_g==7)
     {
      pos1=i_value(wrong_g);
      pos2=j_value(wrong_g);
      arr[pos1][pos2]='\\';
     }
     printf("not quite\n");
     printf("%s\n",player_word);
     print(arr);
     tries_p=tries_p-1;
     j=j+1;
    }
    }
   k=k+1;
   if(j>=tries)
   {
    printf(" BETTER LUCK NEXT TIME\n");
    printf("the correct word is %s\n",word_t_guess);
   }
}
  round++;
  printf("the scores after %d round is\n",round);
  int m=0;
  for(m=0;m<num_p_c;m++)
  {
   printf("%s score =%d\n",players[m].user_name,players[m].user_p);
  }
 }
}