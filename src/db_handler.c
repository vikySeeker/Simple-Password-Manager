#include<stdio.h>
#include<sqlite3.h>

/*
    sqlite3* db;
    sqlite3_stmt* res;
    int rc=0;
    rc=sqlite3_open("test.db",&db);
    if(rc!=SQLITE_OK) printf("Error opening the file\n ");
    else printf("Success in opening file\n");
    rc = sqlite3_prepare_v2(db,"create table auth(username varchar2(15),hash varchar2(512))",-1,&res,0);
    if(rc!=SQLITE_OK) printf("error on prepare");
    rc = sqlite3_step(res);
    if(rc==SQLITE_ROW) printf("%s\n",sqlite3_column_text(res,0));
    sqlite3_finalize(res);
    sqlite3_close(db);
    return 0;
*/

//int createTable(sqlite3*);

int configDb(){
    sqlite3* db;
    int rc=0;
    char*err=0;
    rc=sqlite3_open("test.db",&db);
    if(rc!=SQLITE_OK){
        printf("Error opening the file\n "); 
        return -1;
    }
    else{
        //printf("Success in opening file\n");
        char* table_qurey = "create table mk(name text,key varchar(64));"
                            "create table vault(acc_name text,email text,pass text);"
                            "insert into vault values('gmail','vikyseeker@gmail.com','12345678');";
        rc=sqlite3_exec(db,table_qurey,0,0,&err);
        if(rc!=SQLITE_OK){
            printf("%s\n",err);
            sqlite3_free(err);
            sqlite3_close(db);
            return -2;
        }
        sqlite3_close(db);
        return 1;
    }
}

/*int createTable(sqlite3* db){
    sqlite3 stmt* res;
    int rc = sqlite3_prepare_v2(&edb,"create table auth(username varchar2(15),hash varchar2(512))",-1,&res,0);
    if(rc!=SQLITE_OK){
        printf("error on prepare");
        return -2;
    }
    return 1;
}*/