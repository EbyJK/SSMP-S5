
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
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
