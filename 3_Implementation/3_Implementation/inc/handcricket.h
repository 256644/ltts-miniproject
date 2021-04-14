
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
/**
 * @brief structure used to hold the users name palce and his id
 * 
 */
typedef struct
{
  char user_name[100];
   char user_place[100];
 int user_id;
}handcricket_user; 

void handcricket();
void user_details(handcricket_user *val);
int bat(int over);
int bowl(int over);
