#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>


void menu(void);
void password(void);
void add_new(void);
void search(void);
void list(void);
void modify(void);
void delete_f(void);
void exit_f(void);
void gotoxy(int x,int y);

int main(){
    system("color B");
    password();
    return 0;
}


void gotoxy(int x,int y){
    COORD crd;
    crd.X=x;
    crd.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
}

void password(void){

    char passWord[20]={"1"};
    int j,k,i=0;
    char headline[30]={" Authorized Access Only "};
    k=strlen(headline);

    // Headline
    gotoxy(25,3);
    for(j=0; j<=16; j++){
        Sleep(50);
        printf("\xDB");
    }

    for(j=0;j<=k;j++){
        Sleep(60);
        printf("%c", headline[j]);
    }

    for(j=0; j<=16; j++){
        Sleep(50);
        printf("\xDB");
    }


    gotoxy(30,6);

    printf("Enter Password : ");


    //taking input

    char pass[20],ch,asterisk='*';

    while(ch!=13){
        ch=getch();
        if(ch!=13 && ch!=8){
            pass[i]=ch;
            printf("%c", asterisk);
            i++;
        }
    }

    pass[i]=NULL;



    //compare
    gotoxy(30,8);

    if(strcmp(passWord,pass)==0){
        int len;
        char correct[]={"PASSWORD IS CORRECT"};
        len=strlen(correct);

        for(j=0;j<=len;j++){
            Sleep(60);
            printf("%c",correct[j]);
        }
        menu();
    }else{
        char wrong[]={"WRONG PASSWORD, TRY AGAIN"};

        int len=strlen(wrong);

        for(j=0;j<=len;j++){

        Sleep(60);
        printf("%c",wrong[j]);
        }

        printf("\n\nPress Any Key To Start Again...");
        getch();
        system("cls");
        password();
    }


}



void menu(void){
    system("cls");
    fflush(stdin);
    gotoxy(30,3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PHONEBOOK DIRECTORY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");

    gotoxy(46,6);
    printf("\xDB\xDB\xDB\xDB\xDB 1. Add New");

    gotoxy(46,9);
    printf("\xDB\xDB\xDB\xDB\xDB 2. List");

    gotoxy(46,12);
    printf("\xDB\xDB\xDB\xDB\xDB 3. Search");

    gotoxy(46,15);
    printf("\xDB\xDB\xDB\xDB\xDB 4. Modify");

    gotoxy(46,18);
    printf("\xDB\xDB\xDB\xDB\xDB 5. Delete");

    gotoxy(46,21);
    printf("\xDB\xDB\xDB\xDB\xDB 6. Exit");

    int input;
    gotoxy(46,25);
    printf("Go To : ");
    scanf("%d", &input);


    switch(input){
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
        gotoxy(40,28);
        char invalid[]={"Invalid Enter.Trying Again"};
        int len=strlen(invalid);
        for(int k=0; k<len; k++){
           Sleep(60);
           printf("%c", invalid[k]);
        }
        Sleep(2000);
        system("cls");
        menu();
    }

}



void add_new(void){
    system("cls");
    gotoxy(30,3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add New Record \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");
    fflush(stdin);
    FILE *file;
    char name[30];
    char address[50];
    char Mail[30];
    char gender[15];
    char occupation[30];
    double number;

    file=fopen("DATA.txt", "ab+");

    if(file==NULL){
        printf("Failed to open requared file, please try again later");
    }else{
    //taking input
    gotoxy(35,7);
    printf("Name         : ");
    gotoxy(50,7);
    gets(name);

    gotoxy(35,9);
    printf("Address      : ");
    gotoxy(50,9);
    gets(address);

    gotoxy(35,11);
    printf("Mail         : ");
    gotoxy(50,11);
    gets(Mail);

    gotoxy(35,13);
    printf("Gender       : ");
    gotoxy(50,13);
    gets(gender);

    gotoxy(35,15);
    printf("Occupation   : ");
    gotoxy(50,15);
    gets(occupation);

    gotoxy(35,17);
    printf("Phone Number : ");
    gotoxy(50,17);
    scanf("%lf", &number);

    fprintf(file,"%s %s %s %s %s %.0lf\n\n", name,address,Mail,gender,occupation,number);

    }

    fclose(file);

    gotoxy(35,20);
    printf("Data Saved Successfully");

    gotoxy(35,23);
    printf("Press 1 to add another data, otherwise press 2 to return to Menu");
    gotoxy(35,25);
    printf("Press : ");
    int choice;
    scanf("%d", &choice);

    if(choice==1){
        system("cls");
        add_new();
    }else{
       system("cls");
       menu();
    }
}


void search(void){
    FILE *file;
    char name[30];
    char address[30];
    char mail[30];
    char gender[15];
    char occupation[30];
    int count=0;
    double phoneNumber;
    int res;
    char searchName[30];

    fflush(stdin);
    system("cls");

    file=fopen("DATA.txt","r");



    gotoxy(30,3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Search Section \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");

    gotoxy(30,6);
    printf("Enter Name to Search: ");
    gets(searchName);

    while(fscanf(file,"%s %s %s %s %s %lf", name, address, mail, gender, occupation, &phoneNumber)!=EOF){
        res=strcmp(name,searchName);

        if(res==0){
            gotoxy(35,8);
            printf("Search Result Found");
            count ++;

        printf("\n\t------------------------------------------\n");
		printf("\tName       :  %s\n",name);
		printf("\tAddress    :  %s\n",address);
		printf("\tGender     :  %s\n",gender);
		printf("\tMail       :  %s\n",mail);
		printf("\tOccupation :  %s\n",occupation);
		printf("\tPhone      :  %.0lf\n",phoneNumber);
        printf("\t------------------------------------------");
        printf("\n\n");
        }
    }

    fclose(file);

    if(count==0){
        printf("No result found");
    }

}

void list(void){
    FILE *file;
    char name[30],address[30],mail[30],gender[15],occupation[30];
    int count=1;
    double phoneNumber;

    system("cls");

    file=fopen("DATA.txt", "r");

    gotoxy(30,3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 List Section \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");

    while(fscanf(file,"%s %s %s %s %s %lf", name,address,mail,gender,occupation,&phoneNumber)!=EOF){

    printf("\n\n------------------------------------------\n");
        printf("%d\n", count);
		printf("Name       :  %s\n",name);
		printf("Address    :  %s\n",address);
		printf("Gender     :  %s\n",gender);
		printf("Mail       :  %s\n",mail);
		printf("Occupation :  %s\n",occupation);
		printf("Phone      :  %.0lf\n",phoneNumber);
        printf("------------------------------------------");
        printf("\n\n");


    count ++;
    }


    printf("\tEnter 1 to return to Menu : ");

    int choice;
    scanf("%d", &choice);

    if(choice==1){
        system("cls");
        menu();
    }else{
       system("cls");
       menu();
    }
}


void modify(void){
    FILE *file,*file2;
    char name[30],name2[30];
    char address[30],address2[30];
    char mail[30],mail2[30];
    char gender[15],gender2[30];
    char occupation[30],occupation2[30];
    int count=0;
    double phoneNumber,phone2;
    int res;
    char searchName[30];


    system("cls");
    fflush(stdin);

    gotoxy(30,3);
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modify Section \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");

    gotoxy(30,6);
    printf("Enter the name to modify : ");
    gets(searchName);


    file=fopen("DATA.txt", "r");
    file2=fopen("Temp.txt","a");

    while(fscanf(file,"%s %s %s %s %s %lf", name,address,mail,gender,occupation,&phoneNumber)!=EOF){
        res=strcmp(name,searchName);

        if(res==0){
            fflush(stdin);
            count=1;
            gotoxy(30,9);
            printf("Enter new name: ");
            gets(name2);

            gotoxy(30,11);
            printf("Enter new Address: ");
            gets(address2);

            gotoxy(30,13);
            printf("Enter new mail: ");
            gets(mail2);

            gotoxy(30,15);
            printf("Enter new gender: ");
            gets(gender2);

            gotoxy(30,17);
            printf("Enter new occupation: ");
            gets(occupation2);

            gotoxy(30,19);
            printf("Enter new Phone Number: ");
            scanf("%lf", &phone2);

            fprintf(file2,"%s %s %s %s %s %.0lf\n\n", name2,address2,mail2,gender2,occupation2,phone2);
        }else{
            fprintf(file2,"%s %s %s %s %s %.0lf\n\n", name,address,mail,gender,occupation,phoneNumber);
        }

    }

    if(count==0){
        printf("No Result Found");
    }

    fclose(file);
    fclose(file2);

    //file=fopen("DATA.txt", "a");
    //file2=fopen("Temp.txt", "r");

    //while(fscanf(file2,"%s %s %s %s %s %lf",name,address,mail,gender,occupation,&phoneNumber)!=EOF){
        //fprintf(file,"%s %s %s %s %s %.0lf",name,address,mail,gender,occupation,phoneNumber);
   // }

    fclose(file);
    fclose(file2);

    remove("DATA.txt");

    rename("Temp.txt", "DATA.txt");

    //file2=fopen("Temp.txt","w");
	//fclose(file2);
    /*
    // closing files

    fclose(file);
    fclose(file2);

    // transfering file data

    file=fopen("DATA.txt", "ab+");
    file2=fopen("Temp.txt", "ab+");

    while(fscanf(file2,"%s %s %s %s %s %lf",name,address,mail,gender,occupation,&phoneNumber)!=EOF){
        fprintf(file,"%s %s %s %s %s %lf",name,address,mail,gender,occupation,&phoneNumber);
    }

    fclose(file);
    fclose(file2);

    file2=fopen("Temp.txt","w");
	fclose(file2);*/

}
void delete_f(void){}
void exit_f(void){}
