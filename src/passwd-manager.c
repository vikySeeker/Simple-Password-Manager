#include<stdio.h>
#include<stdlib.h>
#include "db_handler.h"

int isExist();
int createDbFile();
int listMenu();
int intInput(int*);
void route(int*);

int isExist(){
    FILE* checkFile;
    if((checkFile = fopen("test.db","r"))!=NULL){
        fclose(checkFile);
        return 1;
    }
    else{
        return 0;
    }

}

int createDbFile(){
    FILE* dbFile;
    dbFile=fopen("test.db","wb");
    if(dbFile){
        fclose(dbFile);
        //printf("success!\n");
        int ret=configDb();
        //printf("%d",ret);
    }
    else{
        printf("error!\n");
        return -1;
    }
    printf("successfully configured your password vault ;D\n");
    return 1;
}

int listMenu(){
    printf("[1] Save a new Password\n[2] Show The saved Password\n[3] Create a Random Password\n[4] Update Master Key.\n[5] Exit.\n");
    printf("Enter a Number to Continue... : ");
    int input=0;
    if(intInput(&input)){
        route(&input);
    }
    else{
        system("clear");
        listMenu();
        return 1;
    }
    return 0;
}

int intInput(int* input){
    if(scanf("%d",input)==1 && (*input>0 && *input<6)){
        return 1;
    }
    else{
        printf("please enter a valid input!...(Press y/Y to continue): ");
        char ch='n';
        while ((ch=getchar()!='\n' && ch!=EOF)){continue;}
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y'){
            return 0;
        }
        else{
            exit(0);
        }
    }
}

void route(int *input){
    switch (*input){
        case 1:
            printf("to be continued...\n");
            //savepass();
            break;
        case 2:
            printf("to be continued...\n");
            //list_pass();
            break;
        case 3:
            printf("to be continued...\n");
            //rand_pass_gen();
            break;
        case 4:
            printf("to be continued...\n");
            break;
        case 5:
            exit(0);
            break;
        default:
            exit(0);
            break;
    }
}

int main(void){
    printf("WELCOME T0 PASSWD KEEPER\n\n+----------------------+\n|                      |\n|  Developer : seeKer  |\n|  version 1.5         |\n|                      |\n+----------------------+\n");
    if(!isExist()){
        createDbFile();
    }
    else{
        listMenu();
    }
    return 0;
}