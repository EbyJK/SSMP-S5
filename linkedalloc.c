#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct file{
    char name[20];
    int size;
    int block;
    bool alloc;


}f[10];
int main(){



        printf("\nFile allocation table\n");
        printf("\n");
        printf("File name\t File Size \t Blocks Allocated\n");
        
        return 0;
}