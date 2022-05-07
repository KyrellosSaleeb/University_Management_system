#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>



int s;
FILE *fp,*ft,*fs;
struct
{
    char firstName[20];
    char lastName[20];
    char id[20];
    char year[9];
    float GPA;
    int semster;
    int creditHours;
} student,updateStudent,del,check;

struct
{
    char name[20];
    char id[8];
    char profName[20];
    char year[4];
    int creditHours;
    int studno;
    int semster;
} course, updateCourse,delC,checkC;

void closing()
{
    printf("\n\n\n\nThis Project Coded by Kyrellos Saleeb");
    printf("\n\nExiting in 3 second...........");
    Sleep(3000);
    exit(0);
}

//for time
int t()
{
    time_t t;
    time(&t);
    printf("Date and time:%s\n",ctime(&t));

    return 0 ;
}

//change cursor position
COORD coord = {0, 0};
void changeXY(short x, short y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Password(void) //for password option
{

    system("cls");
    char printedWord[29]="University Management System";
    char ch,pass[20],password[20]="pass";
    int i=0,j;
    changeXY(10,4);

    for(j=0; j<20; j++)
    {
        Sleep(20);
        printf("*");
    }
    for(j=0; j<29; j++)
    {
        Sleep(20);
        printf("%c",printedWord[j]);
    }
    for(j=0; j<20; j++)
    {
        Sleep(20);
        printf("*");
    }


    changeXY(10,10);
    changeXY(15,7);
    printf("Enter Password:");

    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }

    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {

        changeXY(15,9);
        printf("Password correct");
        changeXY(17,10);
        printf("Press any key to countinue.....");
        getch();
        mainmenu();
    }
    else
    {
        changeXY(15,16);
        printf("\aWarning!! Incorrect Password");
        getch();
        Password();
    }
}


void mainmenu()
{
    system("cls");
    int i;
    changeXY(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    changeXY(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add student");
    changeXY(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Delete student");
    changeXY(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Edit student");
    changeXY(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. View student");
    changeXY(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Add course");
    changeXY(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Delete course");
    changeXY(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Edit course");
    changeXY(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2 8. View course");
    changeXY(20,21);
    printf("\xDB\xDB\xDB\xDB\xB2 9. Close Application");
    changeXY(20,23);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    changeXY(20,25);
    t();
    changeXY(20,27);

    printf("Enter your choice:");
    switch(getch())
    {
    case '1':
        addstudent();
        break;
    case '2':
        deletestudent();
        break;
    case '3':
        editstudent();
        break;
    case '4':
        viewstudent();
        break;
    case '5':
        addcourse();
        break;
    case '6':
        deletecourse();
        break;
    case '7':
        editcourse();
        break;
    case '8':
        viewcourse();
        break;
    case '9':
        system("cls");
        closing();
        break;

    default:
    {
        changeXY(10,29);
        printf("\aWrong Entry!!Please re-entered correct option");
        if(getch())
            mainmenu();
    }

    }
}





void addstudent()
{
    system("cls");
    int i;
    FILE *ptr;
    ptr = fopen("student.dat","a+");

    changeXY(20,5);

    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2ADD Student\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    changeXY(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 1. First Name: ");
    scanf("%s",&student.firstName);
    changeXY(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Last Name: ");
    scanf("%s",&student.lastName);
    changeXY(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. ID: ");
    scanf("%s",&student.id);
    changeXY(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Year: ");
    scanf("%s",&student.year);
    changeXY(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Semester: ");
    scanf("%d",&student.semster);
    changeXY(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 6. GPA: ");
    scanf("%f",&student.GPA);
    changeXY(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Credit Hours: ");
    scanf("%d",&student.creditHours);
    changeXY(20,21);

    fprintf(ptr,"%s %s %s %s %i %i %f\n", student.firstName,student.lastName, student.id, student.year,student.semster, student.creditHours, student.GPA);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    changeXY(20,22);

    fclose(ptr);
    printf("\nStudent created successfully!");


add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit or 2 to add another student:");
    scanf("%d",&i);
    system("cls");
    if (i==1)
        mainmenu();
    else if(i==0)
        closing();
    else if(i==2)
        addstudent();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }

}



void deletestudent()
{
    system("cls");
    FILE *old,*newrec;
    int test=0,i;
    old=fopen("student.dat","r+");
    newrec=fopen("new.dat","w+");
    changeXY(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DELETE Student \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    changeXY(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 Enter the id of student you want to delete:");
    scanf("%s",&del.id);
    changeXY(20,9);
    while (fscanf(old,"%s %s %s %s %i %i %f",&student.firstName,&student.lastName,&student.id,&student.year,&student.semster,&student.creditHours,&student.GPA)!=EOF)
    {
        if(strcmp(student.id,del.id)==1)
            fprintf(newrec,"%s %s %s %s %i %i %f\n",student.firstName,student.lastName,student.id,student.year,student.semster,student.creditHours,student.GPA);

        else
        {
            test++;
            printf("\n\xDB\xDB\xDB\xDB\xB2 student deleted successfully!\n");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        }
    }

    fclose(old);
    fclose(newrec);
    remove("student.dat");
    rename("new.dat","student.dat");
    if(test==0)
    {
        printf("\n \xDB\xDB\xDB\xDB\xB2 student not found!!\n\a\a\a");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

delete_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&i);

        if (i==1)
            mainmenu();
        else if (i==2)
            closing();
        else if(i==0)
            deletestudent();
        else
        {
            printf("\nInvalid!\a");
            goto delete_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&i);
        system("cls");
        if (i==1)
            mainmenu();
        else
            closing();
    }

}


void editstudent()
{
    system("cls");
    int choice,test=0,i;
    FILE *old,*newrec;
    old=fopen("student.dat","r");
    newrec=fopen("new.dat","w");
    changeXY(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UPDATE Student \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    changeXY(20,7);
    printf("\n\xDB\xDB\xDB\xDB\xB2 Enter the id of student you want to update: ");
    scanf("%d",&updateStudent.id);
    changeXY(20,9);
    while (fscanf(old,"%s %s %s %s %i %i %f",&student.firstName,&student.lastName,&student.id,&student.year,&student.semster,&student.creditHours,&student.GPA)!=EOF)
    {
        if(student.id!=updateStudent.id)
        {
            test=1;
            printf("\nWhich information do you want to change?\n\xDB\xDB\xDB\xDB\xB2 1.First Name\n \xDB\xDB\xDB\xDB\xB2 2.Last Name\n\xDB\xDB\xDB\xDB\xB2 3. GPA\n \xDB\xDB\xDB\xDB\xB2 4. Credit Hours\n\nEnter your choice(according to index number):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
            {
                printf("\xDB\xDB\xDB\xDB\xB2 Enter the new First Name:");
                scanf("%s",&updateStudent.firstName);
                fprintf(newrec,"%s %s %s %s %i %i %f",updateStudent.firstName,student.lastName,student.id,student.year,student.semster,student.creditHours,student.GPA);
                system("cls");
                printf("\xDB\xDB\xDB\xDB\xB2 Changes saved!");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            }
            else if(choice==2)
            {
                printf("\xDB\xDB\xDB\xDB\xB2 Enter the new Last Name:");
                scanf("%s",&updateStudent.lastName);
                fprintf(newrec,"%s %s %s %s %i %i %f",student.firstName,updateStudent.lastName,student.id,student.year,student.semster,student.creditHours,student.GPA);
                system("cls");
                printf("\xDB\xDB\xDB\xDB\xB2 Changes saved!");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            }

            else if(choice==3)
            {
                printf("\xDB\xDB\xDB\xDB\xB2 Enter the new GPA:");
                scanf("%f",&updateStudent.GPA);
                fprintf(newrec,"%s %s %s %s %i %i %f\n",student.id,student.firstName,student.lastName,student.year,student.creditHours,student.semster,updateStudent.GPA);
                system("cls");
                printf("\xDB\xDB\xDB\xDB\xB2 Changes saved!");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            }

            else if(choice==4)
            {
                printf("\xDB\xDB\xDB\xDB\xB2 Enter the new credit hours:");
                scanf("%i",&updateStudent.creditHours);
                fprintf(newrec,"%s %s %s %s %i %i %f",student.firstName,student.lastName,student.id,student.year,student.semster,updateStudent.creditHours,student.GPA);
                system("cls");
                printf("\xDB\xDB\xDB\xDB\xB2 Changes saved!");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            }
        }
        else
            fprintf(newrec,"%s %s %s %s %i %i %f\n",student.id,student.firstName,student.lastName,student.year,student.creditHours,student.semster,student.GPA);
    }
    fclose(old);
    fclose(newrec);
    remove("student.dat");
    rename("new.dat","student.dat");

    if(test!=1)
    {
        system("cls");
        printf("\n \xDB\xDB\xDB\xDB\xB2 student not found!!\a\a\a");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
edit_invalid:
        printf("\n \xDB\xDB\xDB\xDB\xB2 Enter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&i);
        system("cls");
        if (i==1)

            mainmenu();
        else if (i==2)
            closing();
        else if(i==0)
            editstudent();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\n \xDB\xDB\xDB\xDB\xB2 Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&i);
        system("cls");
        if (i==1)
            mainmenu();
        else
            closing();
    }
}

void viewstudent()
{
    int i=0,j;
    system("cls");
    changeXY(1,1);
    char printedWord[14] = " Student List ";
    for(j=0; j<31; j++)
    {
        Sleep(10);
        printf("*");
    }
    for(j=0; j<14; j++)
    {
        Sleep(10);
        printf("%c",printedWord[j]);
    }
    for(j=0; j<31; j++)
    {
        Sleep(10);
        printf("*");
    }
    changeXY(2,2);
    printf("FIRST NAME      LAST NAME     ID    YEAR   SEMSTER   CREDIT HOURS    GPA");
    j=5;
    rewind(fp);
    fp=fopen("student.dat","r");
    while(fscanf(fp,"%s %s %s %s %i %i %f",&student.firstName,&student.lastName,&student.id,&student.year,&student.semster,&student.creditHours,&student.GPA)!=EOF)
    {
        changeXY(3,j);
        printf("%s",student.firstName);
        changeXY(19,j);
        printf("%s",student.lastName);
        changeXY(32,j);
        printf("%s",student.id);
        changeXY(38,j);
        printf("%s",student.year);
        changeXY(45,j);
        printf("%i",student.semster);
        changeXY(56,j);
        printf("%i",student.creditHours);
        changeXY(72,j);
        printf("%f",student.GPA);
        printf("\n\n");
        j++;
        i++;
    }
    changeXY(3,25);
    printf("\xDB\xDB\xDB\xDB\xB2 Total student =%d",i);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    view_invalid:
    printf("\nEnter 0 to return to main menu and 1 to exit:");
    scanf("%d",&i);
    system("cls");
    if (i==0)
        mainmenu();
    else if (i==1)
        closing();
    else
    {
        printf("\nInvalid!\a");
        goto view_invalid;
    }
    fclose(fp);
}


void addcourse()
{
    system("cls");
    int i;
    FILE *ptr;
    ptr = fopen("course.dat","a+");

    changeXY(20,5);

    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2ADD Course\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    changeXY(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Course Name: ");
    scanf("%s",&course.name);
    changeXY(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Prof. Name: ");
    scanf("%s",&course.profName);
    changeXY(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. ID: ");
    scanf("%s",&course.id);
    changeXY(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Year: ");
    scanf("%s",&course.year);
    changeXY(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Semester: ");
    scanf("%d",&course.semster);
    changeXY(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Student Number: ");
    scanf("%d",&course.studno);
    changeXY(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Credit Hours: ");
    scanf("%d",&course.creditHours);
    changeXY(20,21);

    fprintf(ptr,"%s %s %s %s %d %d %d\n", course.name, course.profName, course.id, course.year, course.semster, course.studno, course.creditHours);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    changeXY(20,22);

    fclose(ptr);
    printf("\nCourse created successfully!");


add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit or 2 to add another course:");
    scanf("%d",&i);
    system("cls");
    if (i==1)
        mainmenu();
    else if(i==0)
        closing();
    else if(i==2)
        addstudent();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }

}


void deletecourse()
{
    system("cls");
    FILE *old,*newrec;
    int test=0,i;
    old=fopen("course.dat","r+");
    newrec=fopen("newc.dat","w+");
    changeXY(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DELETE Student \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    changeXY(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 Enter the id of course you want to delete:");
    scanf("%s",&delC.id);
    changeXY(20,9);
    while (fscanf(old,"%s %s %s %s %d %d %d", &course.name, &course.profName, &course.id, &course.year, &course.semster, &course.studno, &course.creditHours)!=EOF)
    {
        if(strcmp(student.id,del.id)==1)
            fprintf(newrec,"%s %s %s %s %i %i %f\n",course.name, course.profName, course.id, course.year, course.semster, course.studno, course.creditHours);

        else
        {
            test++;
            printf("\n\xDB\xDB\xDB\xDB\xB2 course deleted successfully!\n");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        }
    }

    fclose(old);
    fclose(newrec);
    remove("course.dat");
    rename("newc.dat","course.dat");
    if(test==0)
    {
        printf("\n \xDB\xDB\xDB\xDB\xB2 course not found!!\n\a\a\a");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

delete_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&i);

        if (i==1)
            mainmenu();
        else if (i==2)
            closing();
        else if(i==0)
            deletestudent();
        else
        {
            printf("\nInvalid!\a");
            goto delete_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&i);
        system("cls");
        if (i==1)
            mainmenu();
        else
            closing();
    }

}


void editcourse()
{
    system("cls");
    int choice,test=0,i;
    FILE *old,*newrec;
    old=fopen("course.dat","r");
    newrec=fopen("newc.dat","w");
    changeXY(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UPDATE Course \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    changeXY(20,7);
    printf("\n\xDB\xDB\xDB\xDB\xB2 Enter the id of course you want to update: ");
    scanf("%d",&updateCourse.id);
    changeXY(20,9);
    while (fscanf(old,"%s %s %s %s %d %d %d", &course.name, &course.profName, &course.id, &course.year, &course.semster, &course.studno, &course.creditHours)!=EOF)
    {
        if(course.id!=updateCourse.id)
        {
            test=1;
            printf("\nWhich information do you want to change?\n\xDB\xDB\xDB\xDB\xB2 1.First Name\n \xDB\xDB\xDB\xDB\xB2 2.Last Name\n\xDB\xDB\xDB\xDB\xB2 3. GPA\n \xDB\xDB\xDB\xDB\xB2 4. Credit Hours\n\nEnter your choice(according to index number):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
            {
                printf("\xDB\xDB\xDB\xDB\xB2 Enter the new Name:");
                scanf("%s",&updateCourse.name);
                fprintf(newrec,"%s %s %s %s %d %d %d\n",updateCourse.name, course.profName, course.id, course.year, course.semster, course.studno, course.creditHours);
                system("cls");
                printf("\xDB\xDB\xDB\xDB\xB2 Changes saved!");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            }
            else if(choice==2)
            {
                printf("\xDB\xDB\xDB\xDB\xB2 Enter the new Prof. Name:");
                scanf("%s",&updateCourse.profName);
                fprintf(newrec,"%s %s %s %s %d %d %d\n",course.name, updateCourse.profName, course.id, course.year, course.semster, course.studno, course.creditHours);
                system("cls");
                printf("\xDB\xDB\xDB\xDB\xB2 Changes saved!");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            }

            else if(choice==3)
            {
                printf("\xDB\xDB\xDB\xDB\xB2 Enter the new Student Number:");
                scanf("%d",&updateCourse.studno);
                fprintf(newrec,"%s %s %s %s %d %d %d\n",course.name, course.profName, course.id, course.year, course.semster, updateCourse.studno, course.creditHours);
                system("cls");
                printf("\xDB\xDB\xDB\xDB\xB2 Changes saved!");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            }

            else if(choice==4)
            {
                printf("\xDB\xDB\xDB\xDB\xB2 Enter the new credit hours:");
                scanf("%d",&updateCourse.creditHours);
                fprintf(newrec,"%s %s %s %s %d %d %d\n",course.name, course.profName, course.id, course.year, course.semster, course.studno, updateCourse.creditHours);
                system("cls");
                printf("\xDB\xDB\xDB\xDB\xB2 Changes saved!");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            }
        }
        else
            fprintf(newrec,"%s %s %s %s %d %d %d\n",course.name, course.profName, course.id, course.year, course.semster, course.studno, updateCourse.creditHours);
    }
    fclose(old);
    fclose(newrec);
    remove("course.dat");
    rename("newc.dat","course.dat");

    if(test!=1)
    {
        system("cls");
        printf("\n \xDB\xDB\xDB\xDB\xB2 course not found!!\a\a\a");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
edit_invalid:
        printf("\n \xDB\xDB\xDB\xDB\xB2 Enter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&i);
        system("cls");
        if (i==1)

            mainmenu();
        else if (i==2)
            closing();
        else if(i==0)
            editstudent();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\n \xDB\xDB\xDB\xDB\xB2 Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&i);
        system("cls");
        if (i==1)
            mainmenu();
        else
            closing();
    }
}



void viewcourse()
{
    int i=0,j;
    system("cls");
    changeXY(1,1);
    char printedWord[14] = " course  List ";
    for(j=0; j<31; j++)
    {
        Sleep(10);
        printf("*");
    }
    for(j=0; j<14; j++)
    {
        Sleep(10);
        printf("%c",printedWord[j]);
    }
    for(j=0; j<31; j++)
    {
        Sleep(10);
        printf("*");
    }
    changeXY(2,2);
    printf("NAME      PROF NAME     ID    YEAR   SEMSTER    NUM   CREDIT HOURS");
    j=5;
    rewind(fp);
    fp=fopen("student.dat","r");
    while(fscanf(fp,"%s %s %s %s %d %d %d", &course.name, &course.profName, &course.id, &course.year, &course.semster, &course.studno, &course.creditHours)!=EOF)
    {
        changeXY(3,j);
        printf("%s",course.name);
        changeXY(13,j);
        printf("%s",course.profName);
        changeXY(26,j);
        printf("%s",course.id);
        changeXY(32,j);
        printf("%s",course.year);
        changeXY(39,j);
        printf("%i",course.semster);
        changeXY(50,j);
        printf("%i",course.studno);
        changeXY(66,j);
        printf("%i",course.creditHours);
        printf("\n\n");
        j++;
        i++;
    }
    changeXY(3,25);
    printf("\xDB\xDB\xDB\xDB\xB2 Total Courses =%d",i);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    view_invalid:
    printf("\nEnter 0 to return to main menu and 1 to exit:");
    scanf("%d",&i);
    system("cls");
    if (i==0)
        mainmenu();
    else if (i==1)
        closing();
    else
    {
        printf("\nInvalid!\a");
        goto view_invalid;
    }
    fclose(fp);
}

int main()
{
    Password();
    getch();
    return 0;
}
