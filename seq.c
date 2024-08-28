#include <stdio.h>
#include <stdbool.h>

struct file
{
    char name[20];
    int size, start, block;
    bool alloc;
} f[10];
int main()
{

    int blocks;
    int n, i, j;
    bool flag1;
    bool alloc[50];
    char moreFiles;
    int totfile = 0;

    printf("sequential allocation\n");
    printf("enter total number of blocks:\n");
    scanf("%d", &blocks);

    for (i = 0; i < blocks; i++)
    {
        alloc[i] = false;
    }
    do
    {
        if (totfile >= 10)
        {
            printf("maximum no. files reached.\n");
            break;
        }
        printf("enter name of the file %d :\n", totfile + 1);
        scanf("%s", f[totfile].name);
        printf("enter no. of blocks required for file:\n");
        scanf("%d", &f[totfile].size);
        f[totfile].block = f[totfile].size;
        f[totfile].alloc = false;

        flag1 = false;
        for (i = 0; i <= blocks - f[totfile].block; i++)
        {
            flag1 = true;
            for (j = i; j < i + f[totfile].block; j++)
            {
                if (alloc[j] == true)
                {
                    flag1 = false;
                    break;
                }
            }
            if (flag1)
            {
                f[totfile].start = i;
                break;
            }
        }
        if (flag1)
        {
            for (j = f[totfile].start; j < f[totfile].start + f[totfile].block; j++)
            {

                alloc[j] = true;
            }
            f[totfile].alloc = true;
            totfile++;
        }
        else
        {

            printf("file %s cannot be allocated\n", f[totfile].name);
        }
        printf("do you want to enter more files? (y/n):\n");
        scanf(" %c", &moreFiles);
    }while(moreFiles == 'Y' || moreFiles == 'y');

    printf("\nfile allocation table\n");
    printf("\n");
    printf("filename\t size\t blocks allocated\n");
    for (i = 0; i < totfile; i++)
    {
        if (f[i].alloc)
        {
            printf("%s\t\t%d\t\t",f[i].name,f[i].size);
            for(j=f[i].start;j<f[i].start+ f[i].block;j++){
                printf("%d ",j);
                if(j<f[i].start+ f[i].block -1){
                    printf("");

                }
            }
            printf("\n");

        }
        else{
            printf("%s\t\tNot allocated\n",f[i].name);
        }
    }
    return 0;
}
