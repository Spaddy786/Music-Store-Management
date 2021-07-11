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
void func_list();
void Search_rec(void);
void Edit_rec(void);
void Dlt_rec(void);
void ex_it(void);
void gotoxy(short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

struct user
{
     int Quantity;
     char In_Stock;
     char Song_Name[20];
     char Composed_By[20];
     int Price[15];
     char Type[10];
     char Album[30];
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
     printf("\n\n\t\t\t!!!!!!!!!!! Add Music Record !!!!!!!!!!!!\n");
     /* ******* Name ********/
     A:
     printf("\n\t\t\t Name:");
     scanf("%s",&p.Song_Name);
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

/* Composed By */
B:
    printf("\n\t\t\t Last Name:");
    scanf("%s",&p.Composed_By);
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
            scanf("%s",&p.Album);
            p.Album[0]=toupper(p.Album[0]);
            if(strlen(p.Album)>20||strlen(p.Album)<4)
            {
                printf("\n\t Invalid, Maximum character Range is 20 & minimum is 4");
                goto C;
            }

    }while(!valid);

    /* ********************* PRICE **************************** */

    printf("\n\t\t\t Enter Price(in INR):");
    scanf("%i",&p.Price);

    /* ********************* TYPE ****************************** */
    D:
     printf("\n\t\t\t Enter Song Type:");
     scanf("%s",&p.Type);
     p.Type[0]=toupper(p.Type[0]);
     if(strlen(p.Type)>10||strlen(p.Type)<2)
     {

         printf("\n\t Invalid; The max character limit is 10 & minimum is 2");
         goto D;
     }
     else{
        for(b=0;b<strlen(p.Type);b++)
        {
            if(isalpha(p.Type[b]))
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
            goto D;
        }
     }

 fprintf(ek," %s %s %s %s %c %i %i", p.Song_Name,p.Composed_By,p.Album,p.Type,p.In_Stock,p.Quantity,p.Price);
 printf("\n\n\t\t\t...... Information Record Successful......");
 fclose(ek);
 sd:
 getch();
 printf("\n\n\t\t\t Do you want to add more[Y/N]?");
 scanf("%c",&ans);
 if(toupper(ans)=='Y')
 {

     Add_rec();
 }
 else if(toupper(ans)=='N')
 {
     printf("\n\t\t Thank You!");
     getch();
     MainMenu();
 }
 else{
    printf("\n\t\t Invalid Input");
    goto sd;
 }
 }

/* ************* VIEW RECORDS ****************** */
void func_list()
{

    int row;
    system("clscr");
    Title();
    FILE *ek;
    ek=fopen("Record2.dat","r");
    printf("\n\n\t\t\t!!!!!!!!!!! List of Music Records!!!!!!!!!!\n");
    gotoxy(1,15);
    printf("Song Name");
    gotoxy(20,15);
    printf("Composed By");
    gotoxy(32,15);
    printf("Album");
    gotoxy(37,15);
    printf("Type");
    gotoxy(49,15);
    printf("Availability");
    gotoxy(64,15);
    printf("Quantity");
    gotoxy(88,15);
    printf("Price in INR");
    printf("=================================================================================================================");
    row=17;
    while(fscanf(ek,"%s %s %s %s %c %i %i\n",p.Song_Name,p.Composed_By,p.Album,p.Type,p.In_Stock,p.Quantity,p.Price)!=EOF)
    {

        gotoxy(1,row);
        printf("%s",p.Song_Name);
        gotoxy(20,row);
        printf("%s", p.Composed_By);
        gotoxy(32,row);
        printf("%s",p.Album);
        gotoxy(37,row);
        printf("%s",p.Type);
        gotoxy(49,row);
        printf("%c",p.In_Stock);
        gotoxy(64,row);
        printf("%i",p.Quantity);
        gotoxy(88,row);
        printf("%i",p.Price);
        row++;
    }
    fclose(ek);
    getch();
    MainMenu();

}
void Search_rec(void)
{

    char name[20];
    system("clscr");
    Title();
    FILE *ek;
    ek=fopen("Record2.dat","r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!!!! Search A Music Record !!!!!!!!!!!!!!!!");
    printf("\n Enter Song Name:");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    while(fscanf(ek,"%s %s %s %s %c %i %i\n",p.Song_Name,p.Composed_By,p.Album,p.Type,p.In_Stock,p.Quantity,p.Price)!=EOF)
    {
        if(strcmp(p.Song_Name,name)==0)
        {

            gotoxy(1,15);
            printf("Song Name");
            gotoxy(25,15);
            printf("Composed By");
            gotoxy(32,15);
            printf("Album");
            gotoxy(37,15);
            printf("Song-Type");
            gotoxy(52,15);
            printf("Availability");
            gotoxy(64,15);
            printf("Quantity");
            gotoxy(80,15);
            printf("Price\n");
            printf("=================================================================================================================");
            gotoxy(1,18);
            printf("%s",p.Song_Name);
            gotoxy(25,18);
            printf("%s", p.Composed_By);
            gotoxy(32,18);
            printf("%s",p.Album);
            gotoxy(37,18);
            printf("%s",p.Type);
            gotoxy(52,18);
            printf("%c",p.In_Stock);
            gotoxy(64,18);
            printf("%i",p.Quantity);
            gotoxy(80,18);
            printf("%i",p.Price);
            printf("\n");
            break;
        }
    }
    if(strcmp(p.Song_Name,name)!=0)
    {
        gotoxy(5,10);
        printf("Record Not Found!");
        getch();
    }
    fclose(ek);
    L:
        getch();
        printf("\n\n\t\t\t Do you want to search again[Y/N]?");
        scanf("%c",&ans);
        if(toupper(ans)=='Y')
        {

            Search_rec();
        }
        else if(toupper(ans)=='N')
        {
            printf("\n\t\t Thank you!");
            getch();
            MainMenu();
        }
        else
        {
            printf("\n\t Invalid input\n");
            goto L;
        }
}

/* ************************* EDIT RECORD ********************** */
void Edit_rec(void)
{

    FILE *ek,*ft;
    int i,b, valid=0;
    char ch;
    char name[20];
    system("clscr");
    Title();
    ft=fopen("temp.dat","w+");
    ek=fopen("Record.dat","r");
    if(ek==NULL)
    {
        printf("\n\t Cannot Open File!");
        getch();
        MainMenu();
    }
    printf("\n\n\t\t\t!!!!!!!!!!!!!!!! Edit Music Records !!!!!!!!!!!!!!!!\n");
    gotoxy(12,13);
    printf("Edit Song Name to :");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12,15);
    if(ft==NULL)
    {

        printf("\n Cannot open File!");
        getch();
        MainMenu();
    }
    while(fscanf(ek,"%s %s %s %s %c %i %i\n",p.Song_Name,p.Composed_By,p.Album,p.Type,p.In_Stock,p.Quantity,p.Price)!=EOF)
    {
        if(strcmp(p.Song_Name,name)==0)
        {
            valid=1;
            gotoxy(25,17);
            printf("*** Existing Record ***");
            gotoxy(10,19);
            printf("%s \t%s \t%s \t%s \t%c \t%i \t%i\n",p.Song_Name,p.Composed_By,p.Album,p.Type,p.In_Stock,p.Quantity,p.Price);
            gotoxy(12,22);
            printf("Enter New song name:");
            scanf("%s",&p.Song_Name);
            gotoxy(12,26);
            printf("Composed By:");
            scanf("%s",&p.Composed_By);
            p.Composed_By=toupper(p.Composed_By);
            gotoxy(12,28);
            printf("Album:");
            scanf("%s",&p.Album);
            p.Album[0]=toupper(p.Album[0]);
            gotoxy(12,30);
            printf("Song Type:");
            scanf("%s",&p.Type);
            gotoxy(12,32);
            printf("Availability :");
            scanf("%c",&p.In_Stock);
            p.In_Stock=toupper(p.In_Stock);
            gotoxy(12,34);
            printf("Quantity:");
            scanf("%i", &p.Quantity);
            gotoxy(12,36);
            printf("Update Price");
            scanf("%i",&p.Price);
            printf("\nPress U to Update the Records:");
            ch=getche();
            if(ch=='u' || ch=="U")
            {
                fprintf(ft,"%s %s %s %s %c %i %i\n",p.Song_Name,p.Composed_By,p.Album,p.Type,p.In_Stock,p.Quantity,p.Price);
                printf("\n\n\t\t\t Music records updated Successfully");
            }
            }
            else
            {
                fprintf(ft,"%s %s %s %s %c %i %i\n",p.Song_Name,p.Composed_By,p.Album,p.Type,p.In_Stock,p.Quantity,p.Price);
            }
    }
    if(!valid)
    {
        printf("\n\t\t NO RECORD FOUND.....");
        fclose(ft);
        fclose(ek);
        remove("Record2.dat");
        remove("temp2.dat","Record2.dat");
        getch();
        MainMenu();

    }
    /* *********** DELETING RECORD ********** */
    void Dlt_rec









        }
    }
}
