#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <<string.h>
#include <stdlib.h>
char ans=0;
int ok;
int b,valid=0;

//Function Declaration
void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void LoginScreen(void);
void Add_rec(void);
void func_list(void);
void Search_rec(void);
void Edit_rec(void);
void Dlt_rec(void);
void ex_it(void);
void gotoxy(short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetHandle(STD_OUTPUT_HANDLE),pos);
}

struct user
{
     int age;
     char Gender;
     char First_Name[20];
     char Last_Name[20];
     char Contact_no[15];
     char Address[30];
     char Email[30];
};
struct user p,temp_c;
main(void)
{

    WelcomeScreen();
    Title();
    LoginScreen();
}
void WelcomeScreen(void)
{
printf("\n\n\n\n\n\n\n\n\t\t\t##################################");
printf("\n\t\t\t#\t\t Welcome To#");
printf("\n\t\t\t\t# Music Store Management System    #");
printf("\n\t\t\t\t##################################");
printf("\n\n\n\n\n Press any key to continue......\n");
getch();
system("clscr");
}
void Title("void")
{

    printf("\n\n\t\t--------------------------------------------");
    printf("\n\t\t\t\t       Hexagon Music Inc.        ");
    printf("\n\t\t--------------------------------------------")
}
/* ******** main menu******** */
void MainMenu(void)
{

    system("clscr");
    int choose;
    Title();
    printf("\n\n\n\n\n\n\n\t\t\t\t 1. Add Music Record\n");
    printf("\n\t\t\t")
}
