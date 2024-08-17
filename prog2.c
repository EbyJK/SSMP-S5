#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct {
    char dname[10];
    char fname[10][10];
    int fcnt;

}dir[10];

void main(){
int i,ch,k;
char f[30],d[30];
 int flag=-1;
int flag1=-1;
//int flag=-1;
int dcnt=0;
while(1){
    printf("---------------------------------------------");
    printf("\n---MENU---\n");

    printf("\n 1.Create Directory\n 2.create File\n 3.delete File\n 4.Display File\n 5.Search File\n 6.Exit \n");
    printf("---------------------------------------------\n");
    printf("Enter choice :--\n");
    scanf("%d",&ch);

switch(ch){

case 1: 

printf("Enter directory name:--\n");
scanf("%s",dir[dcnt].dname);
dir[dcnt].fcnt=0;
dcnt ++;
printf("directory created\n");
break;


case 2:


printf("enter directory name where to create file\n");
scanf("%s",d);
for(i=0;i<dcnt;i++){
if(strcmp(d,dir[i].dname)==0){
printf("enter the name of the file:--\n");
scanf("%s",dir[i].fname[dir[i].fcnt]);
dir[i].fcnt++;
printf("file created\n");
break;
}
}
if (i==dcnt){
printf("directory not found. please create a directory  / use another directory\n");


}
break;

case 3:


printf("enter the name of directory:--\n");
scanf("%s",d);

// int flag=-1;
// int flag1=-1;
for(i=0;i<dcnt;i++){
if (strcmp(d,dir[i].dname)==0)
{
flag=1;
printf("enter name of the file:--\n");
scanf("%s",f);
for(k=0;k<dir[i].fcnt;k++){

if(strcmp(f,dir[i].fname[k])==0)
{
printf("File %s is deleted..!\n",f);
dir[i].fcnt--;

strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
flag1=1;
}

}

}
if (flag1==-1){
        printf("file %s not found !!\n",f);
}




}
if(flag==-1){
   printf("directory  %s not found !!\n", d);

}


break;
 
case 4: 
        if(dcnt==0){
                printf("No directories\n");
        }
        else{
                printf("\nDirectory\tFiles");
                for(i=0;i<dcnt;i++){
                        printf("\n%s\t",dir[i].dname);
                        for(k=0;k<dir[i].fcnt;k++){
                                printf("\t%s",dir[i].fname[k]);
                        }
                }
        }
        printf("\n");
            

        break;


case 5:   
        printf("enter name of directory:--");
        scanf("%s",d);
       
        for(i=0;i<dcnt;i++){
                if(strcmp(d,dir[i].dname)==0){
                        flag=1;
                        printf("enter the name of the file:--");
                        scanf("%s",f);
                        for(k=0;k<dir[i].fcnt;k++){
                                if(strcmp(f,dir[i].fname[k])==0){
                                        flag1=1;
                                        printf("file %s found\n",f);
                                        printf("file path:\tMFD/%s/%s\n",d,f);
        
                    }

                }
        if(flag1==-1){
                printf("file %s not found\n",f);
        }


        }
         
        if(flag==-1){
                printf("directory not found !!\n");
        }
        
        }         
        
        

        break;

case 6: printf("exitting program!\n");
        printf("--------------------------\n");
        exit(0);
       
        break;

default: printf("invalid choice, Enter another choice..\n");



}


}








}