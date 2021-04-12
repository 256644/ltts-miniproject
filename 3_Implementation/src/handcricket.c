#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "handcricket.h"

void handcricket()
{
  int bat_score=0,bowl_score=0;
  printf("WELCOME TO HANDCRICKET GAME\n");
  handcricket_user *player;
  player=(handcricket_user *) malloc(1*sizeof(handcricket_user));
  printf("Enter the player details:\n");
  user_details(player);
  int over;
  printf("Enter the number of overs:");
  scanf("%d",&over);
  printf("choose between batting and bowling\n");
  printf("To bat select 1 , to bowl select 2\n");
  printf("enter your choice(1 or 2):");
  int x;
  scanf("%d",&x);

  if(x==1)
  
  {printf("%s choose to bat, Hit our shots\n",player->user_name) ;
  bat_score=bat(over);
    printf("%s score is %d\n",player->user_name,bat_score);
    printf("%s Its time to bowl\n",player->user_name) ;
    bowl_score=bowl(over);
    printf("computer score is %d",bowl_score);
  	
  }
  else if(x==2)
  
  {printf("%s choose to bowl\n",player->user_name) ;
   bowl_score=bowl(over);
    printf("computer score is %d\n",bowl_score);
    printf("%s time to bat, Hit our shots\n",player->user_name) ;
    bat_score=bat(over);
    printf("%s score is %d\n",player->user_name,bat_score);
  	
  }
  if(bat_score>bowl_score)
  {
    printf("%s congrats you won the match\n",player->user_name);
  }
  else
  printf("computer won the match \n %s better luck next time\n",player->user_name);
  

}

void user_details(handcricket_user *val)
{
  printf(" user name:");
  scanf("%s",(val+0)->user_name);
   printf(" user place:");
  scanf("%s",(val+0)->user_place);
   printf(" user id an integer number:");
  scanf("%d",&(val+0)->user_id);
  
}

int bat(int over)
{
  int run,score=0;
  printf("NOTE enter the shots between 1-6\n");
  for(int i=0;i<over*6;i++)
  {
 
  printf("Enter the batting shots:");
  scanf("%d",&run);
  if(run>6)
  {
  
  printf("invlaid choice");
  exit (0);
}
  srand(time(NULL));
  int k=rand()%6;
  if(run==k)
  {
    printf("OUT\n");
    break;
  }
  else
  {
  if(run==4)
  printf("char ka choka...!!!!!\n");
  if(run==6)
  printf("hits a six ....!!! wow\n");
  score+=run;
}
  }
  return score;
}
int bowl(int over)
{
  int run,score=0;
  printf("NOTE enter the shots between 1-6\n");
  for(int i=0;i<over*6;i++)
  {
  
  printf("Enter the bowling runs:");
  scanf("%d",&run);
   if(run>6)
  {
  
  printf("invlaid choice");
  exit (0);
}
  srand(time(NULL));
  int k=rand()%6;
  if(run==k)
  {
    printf("OUT\n");
    break;
  }
  else{
  
  if(k==4)
  printf("char ka choka...!!!!!\n");
  if(k==6)
  printf("hits a six ....!!! wow\n");
  score+=k;
}
  }
  return score;
}
  

