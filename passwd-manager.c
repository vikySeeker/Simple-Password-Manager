#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int inp();

char rand_pass_gen(){
int l=1,i=0,r=0;
srand((unsigned)(time(NULL)));
char n[10]="0123456789";
char le[26]="qwertyuiopasdfghjklzxcvbnm";
char LE[26]="QWERTYUIOPASDFGHJKLZXCVBNM";
char sy[34]="~!@#$%^&*()_+} {|:?><-=][\';/.,']}";
puts("\nEnter the Length of the Password : \n");
scanf("%d",&l);
char pass[l];

r=rand()%4;

puts("\nYour Generated Password is...\n");
for(i=0;i<l;i++){

    if(r==1){
        pass[i]=n[rand()%10];
        r=rand()%4;
        }
    else if(r==2){
        pass[i]=le[rand()%26];
        r=rand()%4;
        }
    else if(r==3){
        pass[i]=LE[rand()%26];
        r=rand()%4;
        }
    else {
        pass[i]=sy[rand()%34];
        r=rand()%4;
    }
    printf("%c",pass[i]);
}
puts("\n\n\t!!Copy the Password for Later Use case!!\n");
inp();
}

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
    puts("\n\tStored Successfully!!\n\n");
    fclose(pstr);
    inp();
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
puts("\n\tListed Successfully!!\n\n");
inp();
}

int inp(){
    int i;
    puts("[1] Save a new Password\n[2] Show The saved Password\n[3] Create a Random Password.\n");
    printf("Enter a Number to Continue... : ");
    scanf("%d",&i);
    if (i>3){
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
    break;
case 3:
    rand_pass_gen();
    break;}
return 0;
}

void main()
{
    char w[200]="WELCOME T0 PASSWD KEEPER\n\n+----------------------+\n|                      |\n|  Developer : seeKer  |\n|  version 1.5         |\n|                      |\n+----------------------+\n";
    puts(w);
    inp();
    }
