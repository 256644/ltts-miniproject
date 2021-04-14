/**
 * @brief structue that keeps the name of the players 
 * and their score
 * 
 */
typedef struct 
{
 char user_name[100];
 char user_w[100];
 int user_p;
}hangman_user;

void print(char ar[][5]);
void hangman();
int i_value(int wrong);
int j_value(int wrong);
int check(char *wtg,char key,int length,char *player);
void users_name(hangman_user *val,int num);