#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define maxmemory 200
#define framesize 20
#define maxprocess 10
struct process
{
    int pid;
    int size;
    int frames[maxmemory / framesize];
    bool allocated;
};

struct process processes[maxprocess];
int totframe = maxmemory / framesize;
int nextframe = 0;

void initializememory()
{
    for (int i = 0; i < maxprocess; i++)
    {
        processes[i].allocated = false;
    }
}

bool allocateprocess(int pid, int size)
{
    int framesneeded = (size + framesize - 1) / framesize;
    if (framesneeded > totframe - nextframe)
    {
        printf("Memory full.\n");
        return false;
    }
    processes[pid].allocated = true;
    processes[pid].size = size;

    for (int i = 0; i < framesneeded; i++)
    {
        processes[pid].frames[i] = nextframe++;
    }
    printf("Process %d allocated.\n", pid);
    return true;
}
void deallocateprocess(int pid)
{
    if (!processes[pid].allocated)
    {
        printf("Process %d is not allocated.\n", pid);
        return;
    }
    for (int i = 0; i < (processes[pid].size + framesize - 1) / framesize; i++)
    {
        nextframe = processes[pid].frames[i];
    }
    processes[pid].allocated = false;
    printf("process %d deleted.\n", pid);
}

void displayPCB()
{
    printf("process control block\n");
    printf("------------------------\n");
    printf("Process ID\t Process SIze\t Frames Allocated\n");
    printf("------------------------\n");

    int totalintfrag = 0;
    for (int i = 0; i < maxprocess; i++)
    {
        if (processes[i].allocated)
        {
            printf("%d\t\t%d\t\t", processes[i].pid, processes[i].size);
            for (int j = 0; j < (processes[i].size + framesize - 1) / framesize; j++)
            {
                printf("%d", processes[i].frames[j]);
            }
            printf("\n");

            totalintfrag += (processes[i].size + framesize - 1) % framesize;
        }
    }
    printf("-------------------------------------------------------\n");
    printf("total internal fragmentation: %d\n", totalintfrag);
}

int main()
{
    // printf("enter maximum memory : \n");
    // scanf("%d",&maxmemory);
    // printf("enter frame size:\n");
    // scanf("%d",&framesize);
    // printf("enter maximum no. of processes:\n");
    // scanf("%d",&maxprocess);

    initializememory();
    int ch;
    int pid, size;
    while (1)
    {
        printf("Menu\n");
        printf("1.insert 2. delete 3. display pcb 4.exit\n");
        printf("enter choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter process id:\n");
            scanf("%d", &pid);
            printf("enter process size:\n");
            scanf("%d", &size);
            allocateprocess(pid, size);
            break;
        case 2:
            printf("enter process id :\n");
            scanf("%d", &pid);

            deallocateprocess(pid);
            break;
        case 3:
            displayPCB();
            break;
        case 4:
            printf("exitting the program..\n");
            exit(0);
        default:
            printf("invalid choice!.. enter another choice\n");
        }
    }
    return 0;
}
