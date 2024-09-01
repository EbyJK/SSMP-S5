#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <time.h>

struct file{
    char name[20];
    int size;
    int block;
    int index;
    int bno[50];
    bool alloc;

}f[10];


int main(){

    int blocks;
    int n,i,j;
    bool flag1;
    bool alloc[50];
    char ch;
    int totfile=0;

    srand(time(0));

    printf("indexed allocation\n");
    printf("enter total no. of blocks:\n");
    scanf("%d",&blocks);

    for(i=0;i<blocks;i++){
        
        alloc[i]=false;
    }
    do{
        if(totfile>=10){
            printf("maximum no. of files reached.\n");
            break;
        }
        printf("enter the name of the file %d:\n",totfile+1);
        scanf("%s",f[totfile].name);
        printf("enter the no.of blocks required for the file:\n");
        scanf("%d",&f[totfile].size);

        f[totfile].block =f[totfile].size;
        f[totfile].alloc=false;

        do
        {
            f[totfile].index=rand() % blocks;
        }while (alloc[f[totfile].index]==true);
        



        printf("do you want to enter more files ? (Y/n)\n");
        scanf("%c ",&ch);
    }while(ch=='Y'||ch=='y');
    

    printf("FIle allocation table\n");
    printf("\nIndex\tFile name\t FIle Size\t Blocks Allocated\n");
    for(i=0;i<totfile;i++){
        if(f[i].alloc){
            printf("%d\t%s\t\t%d\t\t",f[i].index,f[i].name,f[i].size);
            for(j=0;j<f[i].block;j++){
                printf("%d",f[i].bno[j]);
            }
            printf("\n");
        }
        else{
            printf("%s\t\tNot allocated\n",f[i].name);
        }
    }
  return 0;


}
