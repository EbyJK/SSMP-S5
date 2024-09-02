

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
    int available_blocks;
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

    available_blocks = blocks;

    do {
        if (totfile >= 10) {
            printf("Maximum number of files reached.\n");
            break;
        }

        printf("Enter the name of the file %d:\n", totfile + 1);
        scanf("%s", f[totfile].name);

        printf("Enter the number of blocks required for the file:\n");
        scanf("%d", &f[totfile].size);

        if (f[totfile].size > available_blocks) {
            printf("Not enough blocks available to allocate the file '%s'. Exiting...\n", f[totfile].name);
            break;  // Exit the loop if there aren't enough blocks
        }

        f[totfile].block = f[totfile].size;
        f[totfile].alloc = false;

        do {
            f[totfile].index = rand() % blocks;
        } while (alloc[f[totfile].index] == true);

        alloc[f[totfile].index] = true;
        available_blocks--;

        int allocated_blocks = 0;
        for (i = 0; i < blocks && allocated_blocks < f[totfile].block; i++) {
            if (!alloc[i]) {
                f[totfile].bno[allocated_blocks] = i;
                alloc[i] = true;
                allocated_blocks++;
                available_blocks--;
            }
        }

        if (allocated_blocks == f[totfile].block) {
            f[totfile].alloc = true;
            printf("File '%s' allocated successfully.\n", f[totfile].name);
        } else {
            printf("Not enough blocks to allocate the file '%s'.\n", f[totfile].name);
            for (j = 0; j < allocated_blocks; j++) {
                alloc[f[totfile].bno[j]] = false;
                available_blocks++;
            }
        }

        totfile++;
        printf("Do you want to enter more files? (Y/n)\n");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
    printf("\n");
    printf("File allocation table\n");
    printf("\nIndex\tFile name\tFile Size\tBlocks Allocated\n");
    for (i = 0; i < totfile; i++) {
        if (f[i].alloc) {
            printf("%d\t%s\t\t%d\t\t", f[i].index, f[i].name, f[i].size);
            for (j = 0; j < f[i].block; j++) {
                printf("%d ", f[i].bno[j]);
            }
            printf("\n");
        } 
        else {
            printf("\t%s\t\tNot allocated\n", f[i].name);
        }
    }

    return 0;
}
