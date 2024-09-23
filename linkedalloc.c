// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// struct block{
//     int next;
//     bool isalloc;
// };
// struct file{
//     char name[20];
//     int size;
//     int startblock;
//     bool isalloc;


// };
// int main(){
//         int totalblocks;
//         int i,j;
//         char moreFiles;
//         int totfile=0;

//         struct block disk[50];
//         struct file files[10];
//         printf("Linked allocation\n");
//         printf("enter total no. of blocks\n");
//         scanf("%d",&totalblocks);
//         for(i=0;i<totalblocks;i++){
//             disk[i].isalloc=false;
//             disk[i].next=-1;
//         }
//         do{
//             if(totfile>=10){
//                 printf("Maximum no. of files reached.\n");
//                 break;
//             }
//             printf("enter the name of the file %d:",totfile+1);
//             scanf("%s",files[totfile].name);
//             printf("enter the number of blocks required for the file:\n");
//             scanf("%d",&files[totfile].size);
//             int requiredblocks=files[totfile].size;
//             int previousblock=-1;
//             bool allocationpossible=true;
//             if(requiredblocks>totalblocks){
//                     allocationpossible=false;
//             }
//             else{
//                 for(i=0;i<totalblocks && requiredblocks >0;i++){
//                     if(!disk[i].isalloc){
//                         if(previousblock !=-1){
//                             disk[previousblock].next=i;

//                         }else
//                         {
//                             files[totfile].startblock=i;
//                         }
//                         previousblock=i;
//                         disk[i].isalloc=true;
//                         requiredblocks--;

//                     }
//                 }
//                 if(requiredblocks>0){
//                     allocationpossible=false;
//                     for(i=0;i<totalblocks;i++){
//                         if(disk[i].isalloc && disk[i].next!=-1){
//                             disk[i].next=-1;
//                         }
//                     }
//                 }
//             }
//             if(allocationpossible){
//                 files[totfile].isalloc=true;
//                 totfile++;


//             }
//             else{
//                 printf("File %s cannot be allocated\n",files[totfile].name);

//             }
//             printf("do you want to enter more files?(Y/N): ");
//             scanf(" %c",&moreFiles);

//         }while(moreFiles=='Y'|| moreFiles=='y');

//          printf("\nFile Allocation Table:\n");
//         printf("File Name\tFile Size\tBlocks Allocated\n");
//         for (i = 0; i < totfile; i++) {
//         if (files[i].isalloc) {
//             printf("%s\t\t%d\t\t", files[i].name, files[i].size);
//             int currentblock = files[i].startblock;
//             while (currentblock != -1) {
//                 printf("%d ", currentblock);
//                 currentblock = disk[currentblock].next;
//             }
//             printf("\n");
//         }
//     }

        
//         return 0;
// }
#include<stdio.h>
struct Alloc_Table{
    char Name[100];
    int start;
    int size;
};
void main(){
    int ch,count=0,size_used=0,totalsize=0,in,prev,current;
    struct Alloc_Table A[100];
    
    printf("\tLinked File Allocation\n");
    printf("Enter the Total No. of Blocks : ");
    scanf("%d",&totalsize);
    int mem[totalsize];
    for(int i=0;i<totalsize;i++){
        mem[i]=-1;
    }
    while(1){
        printf("Enter the Name of the File : ");
        scanf("%s",A[count].Name);
        printf("Enter the number of blocks for File : ");
        scanf("%d",&A[count].size);
        size_used+=A[count].size;
        if(size_used>totalsize){
            printf("Not Enough Space! File Cannot Be Allocated\n");
            size_used-=A[count].size;
        }
        else{
            in=rand()%totalsize;
            while(mem[in]!=-1){
                in=rand()%totalsize;
            }
            A[count].start=in;
            prev=in;
            mem[in]=-2;
            for(int i=1;i<A[count].size;i++){
                current=rand()%totalsize;
                while(mem[current]!=-1){
                    current=rand()%totalsize;
                }
                mem[prev]=current;
                prev=current;
                mem[current]=-2;
            }
            mem[prev]=-3;//end
            count++;
        }
        printf("Do you want to add more files?\n1. Yes\n2. No\n[Choose 1 or 2] : ");
        scanf("%d",&ch);
        if(ch==2){
            break;
        }
    }
    if(count==0){
        printf("Nothing to Show!\n");
    }
    else{
        printf("\n\tAllocation table\n");
        printf("Start\tName\tSize\tBlocks Allocated\n");
        for(int i=0;i<count;i++){
            printf("%d\t%s\t%d\t",A[i].start,A[i].Name,A[i].size);
            int block=A[i].start;
            while(block!=-3){
                printf("%d ",block);block=mem[block];
            }
            printf("\n");
 }
}
}
