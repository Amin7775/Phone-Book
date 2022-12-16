#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>

void menu(void);
void password(void);
void add_new(void);
void search(void);
void list(void);
void modify(void);
void delete_f(void);
void exit_f(void);
void gotoxy(int x, int y);
int exit_f2();

int main()
{
    SetConsoleTitle("Phone Book || By AL Amin");
    system("color B");
    password();
    return 0;
}

void gotoxy(int x, int y)
{
    COORD crd;
    crd.X = x;
    crd.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
}

void password(void)
{
    // variables

    char passWord[20] = {"1"};
    int j, k, i = 0;
    char headline[100] = {" A u t h o r i z e d   A c c e s s   O n l y "};
    k = strlen(headline);

    // Headline
    gotoxy(25, 3);
    for (j = 0; j <= 16; j++)
    {
        Sleep(45);
        printf("\xDB");
    }

    for (j = 0; j <= k; j++)
    {
        Sleep(50);
        printf("%c", headline[j]);
    }

    for (j = 0; j <= 16; j++)
    {
        Sleep(45);
        printf("\xDB");
    }

    gotoxy(50, 7);

    printf("Enter Password : ");

    // taking input

    char pass[20], ch, asterisk = '*';

    while (ch != 13)
    {
        ch = getch();
        if (ch != 13 && ch != 8)
        {
            pass[i] = ch;
            printf("%c", asterisk);
            i++;
        }
    }

    pass[i] = '\0';

    // Comparing Password

    gotoxy(25, 10);

    if (strcmp(passWord, pass) == 0)
    {
        int len;
        char correct[] = {"| PASSWORD IS CORRECT | ENTERING MENU |"};
        len = strlen(correct);

        for (j = 0; j <= len; j++)
        {
            Sleep(60);
            printf("%c", correct[j]);
        }
        printf("\n");
        Sleep(1000);
        menu();
    }
    else
    {
        char wrong[] = {"| WRONG PASSWORD, TRY AGAIN |"};

        int len = strlen(wrong);

        for (j = 0; j <= len; j++)
        {

            Sleep(60);
            printf("%c", wrong[j]);
        }
        printf("\n");
        printf("\n\nPress Any Key To Start Again...");
        getch();
        system("cls");
        password();
    }
}

void menu(void)
{
    system("cls");
    fflush(stdin);
    gotoxy(30, 3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PHONEBOOK DIRECTORY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");

    gotoxy(46, 6);
    printf("\xDB\xDB\xDB\xDB\xDB 1. Add New");

    gotoxy(46, 9);
    printf("\xDB\xDB\xDB\xDB\xDB 2. List");

    gotoxy(46, 12);
    printf("\xDB\xDB\xDB\xDB\xDB 3. Search");

    gotoxy(46, 15);
    printf("\xDB\xDB\xDB\xDB\xDB 4. Modify");

    gotoxy(46, 18);
    printf("\xDB\xDB\xDB\xDB\xDB 5. Delete");

    gotoxy(46, 21);
    printf("\xDB\xDB\xDB\xDB\xDB 6. Exit");

    int input;
    gotoxy(46, 25);
    printf("Go To : ");
    scanf("%d", &input);

    // Switch statement - start of menu

    switch (input)
    {
    case 1:
        add_new();
        break;
    case 2:
        list();
        break;
    case 3:
        search();
        break;
    case 4:
        modify();
        break;
    case 5:
        delete_f();
        break;
    case 6:
        exit_f();
        break;
    default:
        gotoxy(40, 28);
        char invalid[] = {"Invalid Value.Trying Again"};
        int len = strlen(invalid);
        for (int k = 0; k < len; k++)
        {
            Sleep(60);
            printf("%c", invalid[k]);
        }
        Sleep(2000);
        system("cls");
        menu();
    }
}

void add_new(void)
{
    system("cls");

    // headline
    gotoxy(30, 3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add New Record \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");

    fflush(stdin);
    FILE *file;
    char name[30];
    char address[50];
    char Mail[30];
    char gender[15];
    char occupation[30];
    double number;

    file = fopen("DATA.txt", "ab+");

    if (file == NULL)
    {
        printf("Failed to open requared file, please try again later");
    }
    else
    {
        // taking input
        gotoxy(35, 7);
        printf("Name         : ");
        gotoxy(50, 7);
        gets(name);

        gotoxy(35, 9);
        printf("Address      : ");
        gotoxy(50, 9);
        gets(address);

        gotoxy(35, 11);
        printf("Mail         : ");
        gotoxy(50, 11);
        gets(Mail);

        gotoxy(35, 13);
        printf("Gender       : ");
        gotoxy(50, 13);
        gets(gender);

        gotoxy(35, 15);
        printf("Occupation   : ");
        gotoxy(50, 15);
        gets(occupation);

        gotoxy(35, 17);
        printf("Phone Number : ");
        gotoxy(50, 17);
        scanf("%lf", &number);

        fprintf(file, "%s %s %s %s %s %.0lf\n\n", name, address, Mail, gender, occupation, number);
    }

    fclose(file);

    gotoxy(35, 20);
    printf("Data Saved Successfully");

    // Choice

    gotoxy(35, 23);
    printf("Enter 1 to add another data, otherwise enter 2 to return to Menu");
    gotoxy(35, 25);
    printf("Enter : ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        add_new();
    }
    else
    {
        system("cls");
        menu();
    }
}

void search(void)
{
    FILE *file;
    char name[30];
    char address[30];
    char mail[30];
    char gender[15];
    char occupation[30];
    int count = 0;
    double phoneNumber;
    int res;
    char searchName[30];

    fflush(stdin);
    system("cls");

    file = fopen("DATA.txt", "r");

    // Headline

    gotoxy(30, 3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Search Section \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");

    gotoxy(39, 6);
    printf("Enter Name to Search: ");
    gets(searchName);

    while (fscanf(file, "%s %s %s %s %s %lf", name, address, mail, gender, occupation, &phoneNumber) != EOF)
    {
        res = strcmp(name, searchName);

        if (res == 0)
        {
            gotoxy(41, 8);
            printf("Search Result Found");
            count++;

            gotoxy(30, 10);
            printf("------------------------------------------\n");

            gotoxy(30, 12);
            printf("\tName       :  %s\n", name);

            gotoxy(30, 13);
            printf("\tAddress    :  %s\n", address);

            gotoxy(30, 14);
            printf("\tGender     :  %s\n", gender);

            gotoxy(30, 15);
            printf("\tMail       :  %s\n", mail);

            gotoxy(30, 16);
            printf("\tOccupation :  %s\n", occupation);

            gotoxy(30, 17);
            printf("\tPhone      :  %.0lf\n", phoneNumber);

            gotoxy(30, 19);
            printf("------------------------------------------");
            printf("\n\n");
        }
    }

    fclose(file);

    if (count == 0)
    {
        gotoxy(43, 8);
        printf("No Result Found\n");
    }

    // choice

    gotoxy(17, 22);
    printf("Enter 1 to search another data, otherwise enter 2 to return to Menu");
    gotoxy(17, 24);
    printf("Enter : ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        search();
    }
    else
    {
        system("cls");
        menu();
    }
}

void list(void)
{
    FILE *file;
    char name[30], address[30], mail[30], gender[15], occupation[30];
    int count = 1;
    double phoneNumber;

    system("cls");

    file = fopen("DATA.txt", "r");

    gotoxy(30, 3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 List Section \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");

    while (fscanf(file, "%s %s %s %s %s %lf", name, address, mail, gender, occupation, &phoneNumber) != EOF)
    {

        printf("\n\n\t\t\t     ------------------------------------------\n");
        printf("\t\t\t\t\t\t\xB3 %d \xB3\n\n", count);
        printf("\t\t\t\tName       :  %s\n", name);
        printf("\t\t\t\tAddress    :  %s\n", address);
        printf("\t\t\t\tGender     :  %s\n", gender);
        printf("\t\t\t\tMail       :  %s\n", mail);
        printf("\t\t\t\tOccupation :  %s\n", occupation);
        printf("\t\t\t\tPhone      :  %.0lf\n\n", phoneNumber);
        printf("\t\t\t     ------------------------------------------");
        printf("\n\n");

        count++;
    }

    // choice to go back

    printf("\n\t\t\t\tEnter 1 to return to Menu : ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        menu();
    }
    else
    {
        system("cls");
        menu();
    }
}

void modify(void)
{
    FILE *file, *file2; // file2 for duplicate and store data on temp
    char name[30], name2[30];
    char address[30], address2[30];
    char mail[30], mail2[30];
    char gender[15], gender2[30];
    char occupation[30], occupation2[30];
    int count = 0;
    double phoneNumber, phone2;
    int res; // For string compare
    char searchName[30];

    system("cls");

    gotoxy(30, 3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modify Section \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");

    gotoxy(31, 6);
    printf("Enter the name to modify : ");
    scanf("%s", searchName);

    file = fopen("DATA.txt", "r");
    file2 = fopen("Temp.txt", "w");

    while (fscanf(file, "%s %s %s %s %s %lf", name, address, mail, gender, occupation, &phoneNumber) != EOF)
    {
        res = strcmp(name, searchName);

        if (res == 0)
        {
            fflush(stdin);
            count = 1;

            gotoxy(31, 8);
            printf("Search Result Found");

            gotoxy(30, 10);
            printf("------------------------------------------\n");

            gotoxy(31, 12);
            printf("Enter new name: ");
            gets(name2);

            gotoxy(31, 14);
            printf("Enter new Address: ");
            gets(address2);

            gotoxy(31, 16);
            printf("Enter new mail: ");
            gets(mail2);

            gotoxy(31, 18);
            printf("Enter new gender: ");
            gets(gender2);

            gotoxy(31, 20);
            printf("Enter new occupation: ");
            gets(occupation2);

            gotoxy(31, 22);
            printf("Enter new Phone Number: ");
            scanf("%lf", &phone2);

            gotoxy(30, 24);
            printf("------------------------------------------\n");

            fprintf(file2, "%s %s %s %s %s %.0lf\n\n", name2, address2, mail2, gender2, occupation2, phone2);
        }
        else
        {
            fprintf(file2, "%s %s %s %s %s %.0lf\n\n", name, address, mail, gender, occupation, phoneNumber);
        }
    }

    if (count == 0)
    {
        gotoxy(31, 8);
        printf("No Result Found");
    }

    fclose(file);
    fclose(file2);

    // Rewriting data in file

    file = fopen("DATA.txt", "w");
    file2 = fopen("Temp.txt", "r");

    while (fscanf(file2, "%s %s %s %s %s %lf\n", name, address, mail, gender, occupation, &phoneNumber) != EOF)
    {
        fprintf(file, "%s %s %s %s %s %.0lf\n", name, address, mail, gender, occupation, phoneNumber);
    }

    fclose(file);
    fclose(file2);

    // Choice

    gotoxy(30, 26);
    printf("Enter 1 to modify another data, otherwise enter 2 to return to Menu");
    gotoxy(30, 28);
    printf("Press : ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        modify();
    }
    else
    {
        system("cls");
        menu();
    }
}

void delete_f(void)
{
    FILE *file, *file2;
    char name[30];
    char address[30];
    char mail[30];
    char gender[15];
    char occupation[30];
    int count = 0, res;
    double phoneNumber;
    char searchName[30];

    system("cls");

    file = fopen("DATA.txt", "r");
    file2 = fopen("Temp.txt", "w");

    // Headline

    gotoxy(30, 3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Delete Section \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");

    gotoxy(31, 6);
    printf("Enter the name to Delete : ");
    scanf("%s", searchName);

    while (fscanf(file, "%s %s %s %s %s %lf", name, address, mail, gender, occupation, &phoneNumber) != EOF)
    {
        res = strcmp(name, searchName);

        if (res == 0)
        {
            count = 1;
            gotoxy(30, 8);
            printf("------------------------------------------------------");
            gotoxy(31, 9);
            printf("The data of '%s' is deleted successfully", name);
            gotoxy(30, 10);
            printf("------------------------------------------------------");
        }
        else
        {
            fprintf(file2, "%s %s %s %s %s %.0lf\n\n", name, address, mail, gender, occupation, phoneNumber);
        }
    }

    if (count == 0)
    {
        gotoxy(31, 8);
        printf("No Result Found");
    }

    fclose(file);
    fclose(file2);

    file = fopen("DATA.txt", "w");
    file2 = fopen("Temp.txt", "r");

    while (fscanf(file2, "%s %s %s %s %s %lf\n", name, address, mail, gender, occupation, &phoneNumber) != EOF)
    {
        fprintf(file, "%s %s %s %s %s %.0lf\n", name, address, mail, gender, occupation, phoneNumber);
    }

    fclose(file);
    fclose(file2);

    // Choice

    gotoxy(31, 13);
    printf("Enter 1 to delete another data, otherwise enter 2 to return to Menu");
    gotoxy(31, 15);
    printf("Enter : ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        modify();
    }
    else
    {
        system("cls");
        menu();
    }
}

void exit_f(void)
{
    system("cls");
    gotoxy(31, 4);
    printf("\xDB\xDB\xDB\xDB Thank You For Using This Program \xDB\xDB\xDB\xDB");
    gotoxy(31, 5);
    printf("------------------------------------------");
    gotoxy(48, 7);
    printf("Made By");
    gotoxy(48, 8);
    printf("-------");
    gotoxy(48, 10);
    printf("AL Amin");
    gotoxy(44, 12);
    printf("Dhaka, Bangladesh");
    gotoxy(42, 14);
    printf("amin777589@gmail.com\n");

    Sleep(1000);
    exit_f2();
}
int exit_f2()
{
    return 0;
}
