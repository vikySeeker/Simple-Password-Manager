#include <stdio.h>
#include<conio.h>
#include<strings.h>

char savepass(){
    char self[5],name[20], mid[30], pw[30];
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
    fprintf(pstr,"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\nAccount Name : %s\nMail ID : %s\nPassword : %s\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",name,mid,pw);
    fclose(pstr);
    }
    else if(con=='n'){
            puts("Not Saved!");
        exit(1);
    }

}

char list_pass(){
char fcont[200];
puts("working");
FILE *flst;
flst=fopen("Pass.txt","r");
while (!feof(flst)){
fgets(fcont,sizeof(fcont),flst);
puts(fcont);}
fclose(flst);
}

void main()
{
    int i;
    char w[50]="Hey Seeker,Welcome to Passwd Keeper\n";
    puts(w);
    puts("[1] Save a new Password\n[2] Show The saved Password\n");
    printf("Enter a Number to Continue... : ");
    scanf("%d",&i);
    switch (i){
case 1:
    savepass();
    break;
case 2:
    list_pass();
    break;
    }

}

