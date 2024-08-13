#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct {
char dname[10];
char fname[10][10];
int fcnt;

}dir[10];

void main(){
int i,ch,dcnt,k;
char f[30],d[30];
//int flag=-1;
int dcnt=0;
while(1){
printf("\n---MENU---\n");
printf("--------------------");
printf("\n 1.Create Directory\n 2.create File\n 3.delete File\n 4.Display File\n 5.Search File\n 6.Exit \n");
printf("--------------------");
printf("Enter choice :--\n");
scanf("%d",&ch);
switch(ch){

case 1: printf("Enter directory name:--\n");
scanf("%s",dir[dcnt].dname);
dir[dcnt].fcnt=0;
dcnt ++;
printf("directory created");
break;


case 2:
printf("enter directory name where to create file\n");
scanf("%s",d);
for(i=0;i<dcnt;i++){
if(strcmp(d,dir[i].dname)==0){
printf("enter the name of the file:--\n");
scanf("%s",dir[i].fname[dir[i].fcnt]);
dir[i].fcnt++;
printf("file created");
break;
}
}
if (i==dcnt){
printf("directory not found. please create a directory  / use another directory\n");


}
case 3:
int flag=-1;
printf("enter the name of directory:--\n");
scanf("%s",d);
for(i=0;i<dcnt;i++){
if (strcmp(d,dir[i].dname)==0)
{
printf("enter name of the file:--\n");
scanf("%s",f);
for(k=0;k<dir[i].fcnt;k++){

if(strcmp(f,dir[i].fname[k])==0)
{
printf("File %s is deleted..!",f);
dir[i].fcnt--;

strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
flag=1;
}

}
}




}
if(flag==-1){
   printf("directory  %s not found !!", d);

}
break;
 
case 4: printf("enter name of directory:--");
scanf("%s",d);
for(i=0;i<dcnt;i++){
if(strcmp(d,dir[i].dname)==0){
printf("enter the name of the file:--");
scanf("%s",f);
for(k=0;k<dir[i].fcnt;k++){
if(strcmp(f,dir[i].fname[k])){
    //
}

}

}

}  






case 5:  //search

case 6: printf("exitting program!\n");
exit(0);
break;

default: printf("invalid choice, Enter another choice..\n");



}


}








}