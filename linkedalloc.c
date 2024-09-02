#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct block{
    int next;
    bool isalloc;
};
struct file{
    char name[20];
    int size;
    int startblock;
    bool isalloc;


};
int main(){
        int totalblocks;
        int i,j;
        char moreFiles;
        int totfile=0;

        struct block disk[50];
        struct file files[10];
        printf("Linked allocation\n");
        printf("enter total no. of blocks\n");
        scanf("%d",&totalblocks);
        for(i=0;i<totalblocks;i++){
            disk[i].isalloc=false;
            disk[i].next=-1;
        }
        do{
            if(totfile>=10){
                printf("Maximum no. of files reached.\n");
                break;
            }
            printf("enter the name of the file %d:",totfile+1);
            scanf("%s",files[totfile].name);
            printf("enter the number of blocks required for the file:\n");
            scanf("%d",&files[totfile].size);
            int requiredblocks=files[totfile].size;
            int previousblock=-1;
            bool allocationpossible=true;
            if(requiredblocks>totalblocks){
                    allocationpossible=false;
            }
            else{
                for(i=0;i<totalblocks && requiredblocks >0;i++){
                    if(!disk[i].isalloc){
                        if(previousblock !=-1){
                            disk[previousblock].next=i;

                        }else
                        {
                            files[totfile].startblock=i;
                        }
                        previousblock=i;
                        disk[i].isalloc=true;
                        requiredblocks--;

                    }
                }
                if(requiredblocks>0){
                    allocationpossible=false;
                    for(i=0;i<totalblocks;i++){
                        if(disk[i].isalloc && disk[i].next!=-1){
                            disk[i].next=-1;
                        }
                    }
                }
            }
            if(allocationpossible){
                files[totfile].isalloc=true;
                totfile++;


            }
            else{
                printf("File %s cannot be allocated\n",files[totfile].name);

            }
            printf("do you want to enter more files?(Y/N): ");
            scanf(" %c",&moreFiles);

        }while(moreFiles=='Y'|| moreFiles=='y');

         printf("\nFile Allocation Table:\n");
        printf("File Name\tFile Size\tBlocks Allocated\n");
        for (i = 0; i < totfile; i++) {
        if (files[i].isalloc) {
            printf("%s\t\t%d\t\t", files[i].name, files[i].size);
            int currentblock = files[i].startblock;
            while (currentblock != -1) {
                printf("%d ", currentblock);
                currentblock = disk[currentblock].next;
            }
            printf("\n");
        }
    }

        
        return 0;
}

