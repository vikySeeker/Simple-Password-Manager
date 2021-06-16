#include <stdio.h>
#include<conio.h>
#include<strings.h>

char savepass(){
    char self[10],name[20], mid[30], pw[30];
    char con;
    FILE *pstr;

    fgets(self,sizeof(self),stdin);
    puts("\nEnter The Account Name:");
    fgets(name,sizeof(name),stdin);
    puts("Enter The Email ID used to Create or Login to that Account:\t");
    fgets(mid,sizeof(mid),stdin);
    puts("Enter The Password:\t");
    fgets(pw,sizeof(pw),stdin);
    printf("Do you want to store it (y/n)...");
    scanf("%c",&con);
    if (con=='y'){
            pstr=fopen("pass.txt","a");
    fprintf(pstr,"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\nAccount Name : %s\nMail ID : %s\nPassword : %s\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n",name,mid,pw);
    fclose(pstr);
    }
    else if(con=='n'){
            puts("Not Saved!");
        exit(1);
    }

}



void main()
{
    int i;
    char w[50]="Hey Seeker,Welcome to Passwd Keeper\n";
    puts(w);
    puts("[1] Save a new Password\n[2] Show a specific Password\n");
    printf("Enter a Number to Continue... : ");
    scanf("%d",&i);
    switch (i){
case 1:
    savepass();
    break;
    }

    return 0;
}

