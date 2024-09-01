// #include<stdio.h>
// #include<stdbool.h>
// #include <stdlib.h>
// #include <time.h>

// struct file{
//     char name[20];
//     int size;
//     int block;
//     int index;
//     int bno[50];
//     bool alloc;

// }f[10];


// int main(){

//     int blocks;
//     int n,i,j;
//     bool flag1;
//     bool alloc[50];
//     char ch;
//     int totfile=0;

//     srand(time(0));

//     printf("indexed allocation\n");
//     printf("enter total no. of blocks:\n");
//     scanf("%d",&blocks);

//     for(i=0;i<blocks;i++){
        
//         alloc[i]=false;
//     }
//     do{
//         if(totfile>=10){
//             printf("maximum no. of files reached.\n");
//             break;
//         }
//         printf("enter the name of the file %d:\n",totfile+1);
//         scanf("%s",f[totfile].name);
//         printf("enter the no.of blocks required for the file:\n");
//         scanf("%d",&f[totfile].size);

//         f[totfile].block =f[totfile].size;
//         f[totfile].alloc=false;

//         do
//         {
//             f[totfile].index=rand() % blocks;
//         }while (alloc[f[totfile].index]==true);
        



//         printf("do you want to enter more files ? (Y/n)\n");
//         scanf("%c ",&ch);
//     }while(ch=='Y'||ch=='y');
    

//     printf("FIle allocation table\n");
//     printf("\nIndex\tFile name\t FIle Size\t Blocks Allocated\n");
//     for(i=0;i<totfile;i++){
//         if(f[i].alloc){
//             printf("%d\t%s\t\t%d\t\t",f[i].index,f[i].name,f[i].size);
//             for(j=0;j<f[i].block;j++){
//                 printf("%d",f[i].bno[j]);
//             }
//             printf("\n");
//         }
//         else{
//             printf("%s\t\tNot allocated\n",f[i].name);
//         }
//     }
//   return 0;


// }
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

struct file {
    char name[20];
    int size;
    int block;
    int index;
    int bno[50];
    bool alloc;
} f[10];

int main() {
    int blocks;
    int n, i, j;
    bool flag1;
    bool alloc[50];
    char ch;
    int totfile = 0;

    srand(time(0));

    printf("Indexed allocation\n");
    printf("Enter total number of blocks:\n");
    scanf("%d", &blocks);

    for (i = 0; i < blocks; i++) {
        alloc[i] = false;
    }

    do {
        if (totfile >= 10) {
            printf("Maximum number of files reached.\n");
            break;
        }
        
        printf("Enter the name of the file %d:\n", totfile + 1);
        scanf("%s", f[totfile].name);
        
        printf("Enter the number of blocks required for the file:\n");
        scanf("%d", &f[totfile].size);

        f[totfile].block = f[totfile].size;
        f[totfile].alloc = false;

        // Generate a random index block
        do {
            f[totfile].index = rand() % blocks;
        } while (alloc[f[totfile].index] == true);
        
        // Mark the index block as allocated
        alloc[f[totfile].index] = true;

        // Allocate blocks for the file
        int allocated_blocks = 0;
        for (i = 0; i < blocks && allocated_blocks < f[totfile].block; i++) {
            if (!alloc[i]) {
                f[totfile].bno[allocated_blocks] = i;
                alloc[i] = true;
                allocated_blocks++;
            }
        }

        if (allocated_blocks == f[totfile].block) {
            f[totfile].alloc = true;
            printf("File '%s' allocated successfully.\n", f[totfile].name);
        } else {
            printf("Not enough blocks to allocate the file '%s'.\n", f[totfile].name);
            for (j = 0; j < allocated_blocks; j++) {
                alloc[f[totfile].bno[j]] = false;  // Free the blocks allocated so far
            }
        }

        totfile++;
        printf("Do you want to enter more files? (Y/n)\n");
        scanf(" %c", &ch);  // Add a space before %c to consume the newline character
    } while (ch == 'Y' || ch == 'y');

    printf("File allocation table\n");
    printf("\nIndex\tFile name\tFile Size\tBlocks Allocated\n");
    for (i = 0; i < totfile; i++) {
        if (f[i].alloc) {
            printf("%d\t%s\t\t%d\t\t", f[i].index, f[i].name, f[i].size);
            for (j = 0; j < f[i].block; j++) {
                printf("%d ", f[i].bno[j]);
            }
            printf("\n");
        } else {
            printf("%s\t\tNot allocated\n", f[i].name);
        }
    }

    return 0;
}
