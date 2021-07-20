#include <stdio.h> ///for input output functions like printf, scanf
#include <stdlib.h>
#include <conio.h>
#include <windows.h> ///for windows related functions (not important)
#include <string.h>  ///string operations

/** List of Global Variable */
COORD coord = {0,0}; /// top-left corner of window


void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/** Main function started */

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n  ::::::::::::::::::::::::::  LOGIN FORM  ::::::::::::::::::::::::::  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO MUSIC STORE MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL");
	    printf("\n LOADING PLEASE WAIT... \n");
    for(i=0; i<3; i++)
    {
        printf(".");
        Sleep(500);
    }
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n  SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}


int main()
{
	int i=0;
	login();
    FILE *fp, *ft; /// file pointers
    char another, choice;

    /** structure that represent a employee */
    struct song
    {
        char songname[40];
        int published_in;
        char composed_by[20];
        float duration;
    };

    struct song e; /// structure variable creation

    char sname[40];

    long int recsize; /// size of each record of employee

    /** open the file in binary read and write mode

    * if the file doesn't exit it simply create a new copy */
    fp = fopen("record.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("record.DAT","wb+");
        if(fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }

    /// sizeo of each record i.e. size of structure variable e
    recsize = sizeof(e);

    /// infinite loop continues untile the break statement encounter
    while(1)
    {

        system("cls"); ///clear the console window

        printf(" \n  ::::::::::::::::::::::::::  |MUSIC STORE MANAGEMENT|  :::::::::::::::::::::::::: \n");
        gotoxy(30,05); /// move the cursor to postion 30, 10 from top-left corner
		printf("1> Add  Records"); /// option for add record
        gotoxy(30,07);
        printf("2> List Records"); /// option for showing existing record
        gotoxy(30,9);
        printf("3> Modify Records"); /// option for editing record
        gotoxy(30,11);
        printf("4> Delete Records"); /// option for deleting record
        gotoxy(30,13);
        printf("5> Exit System"); /// exit from the program
        gotoxy(30,15);
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        choice  = getche(); /// get the input from keyboard
        switch(choice)


        {
        case '1':  /// if user press 1
            system("cls");
            fseek(fp,0,SEEK_END);
            another = 'y';
            while(another == 'y')  /// if user want to add another record
            {
                printf("\nEnter songname: ");
                scanf("%s",e.songname);
                printf("\nEnter published_in: ");
                scanf("%d", &e.published_in);
                printf("\nEnter Composer name:");
                scanf("%s",e.composed_by);
                printf("\nEnter duration: ");
                scanf("%f", &e.duration);

                fwrite(&e,recsize,1,fp); /// write the record in the file

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
        case '2':
            system("cls");
            printf("Music RECORD LIST (songname, published_in, Composed by, salary)");
            rewind(fp); ///this moves file cursor to start of the file
            while(fread(&e,recsize,1,fp)==1)  /// read the file and fetch the record one record per fetch
            {

                printf("\n\n%s \t\t%d \t%s \t%.2f",e.songname,e.published_in,e.composed_by,e.duration); /// print the songname, published_in and basic salary
            }
            getch();
            break;

        case '3':  /// if user press 3 then do editing existing record
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the employee songname to modify: ");
                scanf("%s", sname);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file
                {
                    if(strcmp(e.songname,sname) == 0)  ///if entered songname matches with that in file
                    {
                        printf("\nEnter new songname,published_in,composed by and duration: ");
                        scanf("%s%d%s%f",e.songname,&e.published_in,&e.composed_by,&e.duration);
                        fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                        fwrite(&e,recsize,1,fp); /// override the record
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter songname of employee to delete: ");
                scanf("%s",sname);
                ft = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                rewind(fp); /// move record to starting of file
                while(fread(&e,recsize,1,fp) == 1)  /// read all records from file
                {
                    if(strcmp(e.songname,sname) != 0)  /// if the entered record match
                    {
                        fwrite(&e,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("record.DAT"); /// remove the orginal file
                rename("Temp.dat","record.DAT"); /// rename the temp file to original file songname
                fp = fopen("record.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            fclose(fp);  /// close the file
            exit(0); /// exit from the program
        }
    }
    return 0;
}
