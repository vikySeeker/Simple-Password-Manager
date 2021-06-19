#include <stdio.h>
#include<stdlib.h>

int inp();

char savepass(){                                           //function to save new password.
    char self[5],name[20], mid[30], pw[30];
    char con;
    FILE *pstr;

    fgets(self,sizeof(self),stdin);
    puts("\nEnter The Account Name:");
    fgets(name,sizeof(name),stdin);
    puts("\nEnter The Email ID used to Create or Login to that Account:\t");
    fgets(mid,sizeof(mid),stdin);
    puts("\nEnter The Password:\t");
    fgets(pw,sizeof(pw),stdin);
    printf("\nDo you want to store it (y/n)...");
    scanf("%c",&con);
    if (con=='y'){
            pstr=fopen("pass.txt","a");
    fprintf(pstr,"\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\nAccount Name : %s\nMail ID : %s\nPassword : %s\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",name,mid,pw);
    fclose(pstr);
    exit(1);
    }
    else if(con=='n'){
            puts("Not Saved!");
        exit(1);
    }

}

char list_pass(){                                           //function to list saved password.
char fcont[200];
FILE *flst;
flst=fopen("pass.txt","r");
if (flst==NULL){
    puts("\n\t\t!!File Not Found!!\n");
    inp();
    }
while (!feof(flst)){
fgets(fcont,sizeof(fcont),flst);
puts(fcont);}
fclose(flst);
}

int inp(){
    int i;
    puts("[1] Save a new Password\n[2] Show The saved Password\n");
    printf("Enter a Number to Continue... : ");
    scanf("%d",&i);
    if (i>2){
        puts("\n\t\t!!Invalid Input!!\n");
        i=0;
        inp();
    }
    switch (i){
case 1:
    savepass();
    break;
case 2:
    list_pass();
    break;}
return 0;
}

void main()
{
    char w[130]="Welcome To Passwd Keeper\n------------------------\n\n    Developer : seeKer\n    version 1.0\n\n------------------------\n";
    puts(w);
    inp();
    }
