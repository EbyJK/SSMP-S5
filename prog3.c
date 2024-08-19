#include <stdio.h>
#include <stdbool.h>
struct file
{
    char name[20];
    int size, start, block, bno[20];
    bool alloc;
} f[10];
void main()
{
    int dsize, bsize, blocks, n, i, j, choice, index;
    bool alloc[50] = {false}, balo[50] = {false}, flag1, flag2;
    do
    {
        printf("\nAllocation Methods:\n1-Sequential\n2-Indexed\n3-Linked\n0-Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice <= 3 && choice > 0)
        {
            printf("Enter Memory size: ");
            scanf("%d", &dsize);
            printf("Enter Block size: ");
            scanf("%d", &bsize);
            blocks = dsize / bsize;
            printf("Enter no. of files to be allocated: ");
            scanf("%d", &n);
        }
        if (choice == 1)
        {
            for (i = 0; i < blocks; i++)
            {
                alloc[i] = false;
            }
            for (i = 0; i < n; i++)
            {
                flag1 = true;
                printf("Enter name of the file %d: ", i + 1);
                scanf("%s", f[i].name);
                printf("Enter size of %s: ", f[i].name);
                scanf("%d", &f[i].size);
                printf("Enter the start block of %s: ", f[i].name);
                scanf("%d", &f[i].start);
                f[i].alloc = false;

                if (f[i].size % bsize == 0)
                    f[i].block = f[i].size / bsize;
                else
                    f[i].block = (f[i].size / bsize) + 1;
                for (j = f[i].start; j < f[i].start + f[i].block; j++)
                {
                    if (j >= blocks || alloc[j] == true)
                    {
                        flag1 = false;
                        break;
                    }
                }
                if (flag1)
                {
                    for (j = f[i].start; j < f[i].start + f[i].block; j++)
                    {
                        alloc[j] = true;
                    }
                    f[i].alloc = true;
                }
                else
                    printf("%s cannot be allocated\n", f[i].name);
            }
            printf("\nFile\tStart\tBlock Length\n");
            for (i = 0; i < n; i++)
            {
                if (f[i].alloc)
                    printf("%s\t%d\t%d\n", f[i].name, f[i].start, f[i].block);
                else
                    printf("%s\tNot allocated\n", f[i].name);
            }
        }
        else if (choice == 2)
        {
            for (i = 0; i < blocks; i++)
            {
                balo[i] = false;
            }
            for (i = 0; i < n; i++)
            {
                flag1 = true;
                printf("Enter name of the file %d: ", i + 1);
                scanf("%s", f[i].name);
                printf("Enter size of %s: ", f[i].name);

                scanf("%d", &f[i].size);
                if (f[i].size % bsize == 0)
                    f[i].block = f[i].size / bsize;
                else
                    f[i].block = (f[i].size / bsize) + 1;
                do
                {
                    printf("Enter the index block: ");
                    scanf("%d", &index);
                    flag2 = false;
                    if (index >= blocks || index < 0 || balo[index] == true)
                    {
                        printf("Invalid index\nAgain ");
                        flag2 = true;
                    }
                } while (flag2);
                balo[index] = true;
                printf("Enter block numbers: ");
                for (j = 0; j < f[i].block; j++)
                {
                    scanf("%d", &f[i].bno[j]);
                    if (f[i].bno[j] >= blocks || balo[f[i].bno[j]] == true)
                    {
                        flag1 = false;
                        break;
                    }
                }
                if (flag1)
                {
                    for (j = 0; j < f[i].block; j++)
                    {
                        balo[f[i].bno[j]] = true;
                    }
                    f[i].alloc = true;
                }
                else
                {
                    balo[index] = false;
                    printf("%s cannot be allocated\n", f[i].name);
                }
            }
            printf("\nFile\tBlocks\tIndexed at\n");
            for (i = 0; i < n; i++)
            {

                if (f[i].alloc)
                {
                    printf("%s\t%d\t", f[i].name, f[i].block);
                    for (j = 0; j < f[i].block; j++)
                    {
                        printf("%d-> %d ", index, f[i].bno[j]);
                        if (j < f[i].block - 1)
                            printf(", ");
                    }
                    printf("\n");
                }
                else
                    printf("%s\tNot allocated\n", f[i].name);
            }
        }
        else if (choice == 3)
        {
            for (i = 0; i < blocks; i++)
            {
                balo[i] = false;
            }
            for (i = 0; i < n; i++)
            {
                flag1 = true;
                printf("Enter name of the file %d: ", i + 1);
                scanf("%s", f[i].name);
                printf("Enter size of %s: ", f[i].name);
                scanf("%d", &f[i].size);
                if (f[i].size % bsize == 0)
                    f[i].block = f[i].size / bsize;
                else
                    f[i].block = (f[i].size / bsize) + 1;
                printf("Enter block numbers: ");
                for (j = 0; j < f[i].block; j++)
                {
                    scanf("%d", &f[i].bno[j]);
                    if (f[i].bno[j] >= blocks || balo[f[i].bno[j]] == true)
                    {
                        flag1 = false;
                        break;
                    }
                }
                if (flag1)
                {

                    for (j = 0; j < f[i].block; j++)
                    {
                        balo[f[i].bno[j]] = true;
                    }
                    f[i].alloc = true;
                }
                else
                    printf("%s cannot be allocated\n", f[i].name);
            }
            printf("\nFile\tStart\tEnd\tSize\tLinked at\n");
            for (i = 0; i < n; i++)
            {
                if (f[i].alloc)
                {
                    printf("%s\t%d\t%d\t%d\t", f[i].name, f[i].bno[0], f[i].bno[f[i].block - 1], f[i].block);
                    for (j = 0; j < f[i].block; j++)
                    {
                        printf("%d ", f[i].bno[j]);
                        if (j < f[i].block - 1)
                            printf("-> ");
                    }
                    printf("\n");
                }
                else
                    printf("%s\tNot allocated\n", f[i].name);
            }
        }
        else if (choice == 0)
            printf("END\n");
        else
            printf("Invalid choice\n");
    } while (choice != 0);
}