#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
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
     int Quantity;
     char In_Stock;
     char Song_Name[20];
     char Composed_By[20];
     char Contact_no[15];

     char Album[30];
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
void Title(void)
{

    printf("\n\n\t\t--------------------------------------------");
    printf("\n\t\t\t\t       Hexagon Music Inc.        ");
    printf("\n\t\t--------------------------------------------");
}
/* ******** main menu******** */
void MainMenu(void)
{

    system("clscr");
    int choose;
    Title();
    printf("\n\n\n\n\n\t\t\t\t 1. Add Music Record\n");
    printf("\n\t\t\t\t 2. List Music Records\n");
    printf("\n\t\t\t\t 3. Search Music Record\n");
    printf("\n\t\t\t\t 4. Edit Music Record\n");
    printf("\n\t\t\t\t 5. Delete Music Record\n");
    printf("\n\t\t\t\t 6. Exit\n");
    printf("\n\n\n \n\t\t\t Choose from 1 to 6:");
    scanf("%i",&choose);
    switch(choose)
    {

    case 1:
        Add_rec();
        break;
    case 2:
        func_list();
        break;
    case 3:
        Search_rec();
        break;
    case 4:
        Edit_rec();
        break;
    case 5:
        Dlt_rec();
        break;
    case 6:
        ex_it();
        break;
    default:
        printf("\t\t\t Invalid Entry. Please Enter the right option");
        getch();
    }

}
/* *******Exit Screen********** */
void ex_it(void)
{
    system("clscr");
    Title();
    printf("\n\n\n\n\n\t\t\t Thank You For visiting");
    getch();
}
/* LOGIN SCREEN */
 void LoginScreen(void)
 {

     int e=0;
     char Username[15];
     char Password[15];
     char original_Username[25]="admin";
     char original_Password[15]="1234";
     do
        {

     printf("\n\n\n\n\t\t\t\t Enter your Username and Password:");
     printf("\n\n\n\t\t\t\t\t Username:");
     scanf("%s",&Username);
     printf("\n\n\t\t\t\t\t Password:");
     scanf("%s",&Password);
     if(strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
     {
         printf("\n\n\n\t\t\t\t\t....Login Successful....");
         getch();
         MainMenu();
         break;
     }
     else
     {
         printf("\n\t\t\t Password is incorrect, Please Try again");
         e++;
         getch();
     }
 }while(e<=2);
 if(e>2)
 {
     printf("You have crossed the limit of failed attempts.");
     getch();
     ex_it();
 }
 system("cls");
 }

 /* ***** Adding Record ****/
 void Add_rec(void)
 {
     system("clscr");
     Title();

     char ans;
     FILE*ek;
     ek=fopen("Record.dat","a");
     prinf("\n\n\t\t\t!!!!!!!!!!! Add Music Record !!!!!!!!!!!!\n");
     /* ******* Name ********/
     A:
     printf("\n\t\t\t Name:");
     scanf("%s",p.Song_Name[0]);
     p.Song_Name[0]=toupper(p.Song_Name[0]);
     if(strlen(p.Song_Name)>20||strlen(p.Song_Name)<2)
     {

         printf("\n\t Invalid; The max character limit is 20 & minimum is 2");
         goto A;
     }
     else{
        for(b=0;b<strlen(p.Song_Name);b++)
        {
            if(isalpha(p.Song_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Invalid Character in Song Name, Try again!");
            goto A;
        }
     }
 }
/* Composed By */
B:
    printf("\n\t\t\t Last Name:");
    scanf("%s",p.Composed_By);
    p.Composed_By[0]=toupper(p.Composed_By[0]);
    if(strlen(p.Composed_By)>20||strlen(p.Composed_By)<2)
    {
        printf("\n\t Invalid, Maximum Character Range is 20 and minimum is 2");
        goto B;
    }
    else{
        for(b=0;b<strlen(p.Composed_By);b++)
        {
            if(isalpha(p.Composed_By[b]))
            {
                valid=1;
            }
            else{
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Composor Name contains Invalid character, Enter again");
            goto B;

        }
    }
    /* ********ITEM IN STOCK******* */

    do
    {

        printf("\n\t\t\t Item In stock[Y/N]:");
        scanf("%c",&p.In_Stock);
        if(toupper(p.In_Stock)=='Y'|| toupper(p.In_Stock)=='N')
        {

            ok=1;
        }
        else{
            ok=0;
        }
        if(!ok)
        {
            printf("\n\t\t Contains invalid character, Enter either Y(yes) or N(no)");

        }

    }while(!ok);

    /* Quantity */

    printf("\n\t\t\t Quantity:");
    scanf("%i",&p.Quantity);

    /* Album */

    do{
        C:
            printf("\n\t\t\t Album Name:");
            scanf("%s",p.Album);
            p.Album[0]=toupper(p.Album[0]);
            if(strlen(p.Album)>20||strlen(p.Album)<4)
            {
                printf("\n\t Invalid, Maximum character Range is 20 & minimum is 4");
                goto C;
            }

    }while(!valid);

    /

