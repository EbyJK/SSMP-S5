
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct {
char dname[10];
char fname [10][10];
int fcnt;
}dir;

void main(){
int i,ch;
char f[30];

dir.fcnt=0;
printf("\n Enter name of directory:-- ");
scanf("%s",dir.dname);
         while(1){
            printf("----------------------------------------------------------");
          printf("\n---MENU----\n");
          printf("\n 1.create FIle\n 2.Delete FIle\n 3.Display file\n 4.Search FIle\n 5. Exit\n ");
          printf("------------------------------------------------------------");
          printf("\nEnter choice: \n");
          scanf("%d",&ch);
          switch(ch){
          case 1: printf("\n enter the name of the file:-- ");
          scanf("%s",dir.fname[dir.fcnt]);
          dir.fcnt++;
          break;
         
         
          case 2: printf("\n enter the name of the file:-- \n");
          scanf("%s",f);
          for(i=0;i<dir.fcnt;i++){
          if (strcmp(f,dir.fname[i])==0){
          printf("\nFile %s is deleted from the directory!!\n",f);
          strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
          break;
          }
          }
          if(i==dir.fcnt){
          printf("\nfile %s is not found in the directory\n",f);
          }
                else{
                dir.fcnt--;
                break;
               
                }
         
         
         
          case 3: if (dir.fcnt==0){
          printf("\n Directory EMpty\n");
         
          }
          else{
          printf("\n the files are:-- \n");
          for(i=0;i<dir.fcnt;i++){
          printf("\t%s",dir.fname[i]);
          }
          }
          break;
         
         
         
          case 4:printf("\nEnter the name of the file--\n");
          scanf("%s",f);
          for(i=0;i<dir.fcnt;i++){
          if(strcmp(f,dir.fname[i])==0){
          printf("file %s is found \n",f);
          break;
         
          }
         
         
          }
          if(i==dir.fcnt){
          printf("\nAlas,,file %s is not found\n",f);
         
          }
          break;
         
         
         
         
         
          case 5: printf("\n exitting the program !! \n");
                    printf("\n");
        
                    exit(0);
                 break;
                 
          default: printf("invalid choice\n please enter another choice !\n");
         
         
          }
         
         
         }

}

