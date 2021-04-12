
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "hangman.h"

void print(char ar[][5])
{
 int i,j;
  for(i=0;i<6;i++)
 {
  for(j=0;j<5;j++)
  {
   printf("%c",ar[i][j]);
  }
  printf("\n");
 }
}
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


void users_name(hangman_user *val,int num)
{
 int i=0;
 for(i=0;i<num;i++)
 {
  printf("%d users name:\n",i+1);
  scanf("%s",(val+i)->user_name);
 }
}

void hangman()
{
 int num_p,i=1;
 int num_p_c;

 printf("WELCOME TO HANGMAN\n");
  char arr[6][5]={' ',' ','_','_','_',
      ' ',' ',' ',' ','|',
      ' ',' ',' ',' ','|',
      ' ',' ',' ',' ','|',
      ' ',' ',' ',' ','|'};
 printf("enter the number of players\n");
 scanf("%d",&num_p);
 num_p_c=num_p;
 hangman_user *players;
 players=(hangman_user *)calloc(num_p,sizeof(hangman_user));
 printf("enter players name\n");
 users_name(players,num_p);
 for(i=0;i<num_p;i++)
 {
  players[i].user_p=0;
 }
 
 printf("enter the number of rounds\n");
 int num_rounds;
 int round=0;
 
 scanf("%d",&num_rounds);
 while(num_rounds--)
 {
  int k=0;
  
  printf("round=%d\n",round+1);
  while(num_p--)
  {
  printf("%s turn\n",players[k].user_name);
  
  char word_t_guess[100];
  int tries=6,j=0,tries_p=6;
  int lenght_of_word;
   printf("\nenter the word to guess and make sure the one whose turn is not seeing this\n");
   scanf("%s",word_t_guess);
   system("cls");
   lenght_of_word=strlen(word_t_guess);
   char *player_word;
   player_word=(char *)calloc(lenght_of_word,sizeof(char));
   for(i=0;i<lenght_of_word;i++)
   {
    player_word[i]='-';
   }
  
   while(j<tries)
   {
    char a[2],check1=0;
    printf("\n%d tries pending\n",tries_p);
    printf("enter the character you are guessing  should nt be a number\n");
    scanf("%s",a);
   
    check1=check(word_t_guess,a[0],lenght_of_word,player_word);
    if(check1==1)
    {
     printf("good work\n");
      printf("%s\n",player_word);
      if(strcmp(player_word,word_t_guess)==0)
      {
       printf("%s guessed it right\n",players[k].user_name);
       players[k].user_p+=10;
       break;
      }
    }
    else
    {
     printf("not quite\n");
     printf("%s\n",player_word);
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