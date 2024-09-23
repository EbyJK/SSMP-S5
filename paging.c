
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// struct process {
//     int id;
//     int size;
//     int nofr;
//     int fno[10];
// } p[10];

// int main() {
//     int msize, fsize, totfr, remfr, ch;
//     int top = 0;
//     int infrag, pid;

//     printf("Enter memory size(in kb): \n");
//     scanf("%d", &msize);
//     printf("Enter frame size:\n");
//     scanf("%d", &fsize);
//     totfr = msize / fsize;
//     printf("Total no of frames available: %d\n", totfr);
//     remfr = totfr;

//     srand(time(NULL));

//     printf("\nSelect choice\n1. Insert process\n2. Delete process.\n3. Exit.\n");

//     while (1) {
//         printf("\nEnter choice:\n");
//         scanf("%d", &ch);

//         switch (ch) {
//             case 1: {
//                 if (remfr == 0) {
//                     printf("Memory is full!\n");
//                     break;
//                 }
//                 printf("Enter process ID:\n");
//                 scanf("%d", &p[top].id);
//                 printf("Enter process size:\n");
//                 scanf("%d", &p[top].size);

//                 p[top].nofr = (p[top].size + fsize - 1) / fsize;  // Calculate frames required
//                 if (p[top].nofr > remfr) {
//                     printf("Memory overflow! Choose a smaller size!\n");
//                     break;
//                 }
//                 remfr -= p[top].nofr;

//                 for (int i = 0; i < p[top].nofr; i++) {
//                     p[top].fno[i] = rand() % totfr + 1;  // Limit to available frames
//                 }
//                 top++;

//                 printf("\nProcess ID    Size    Frames\n");
//                 infrag = 0;
//                 for (int i = 0; i < top; i++) {
//                     printf("%7d%7d", p[i].id, p[i].size);
//                     for (int j = 0; j < p[i].nofr; j++) {
//                         printf("%4d ", p[i].fno[j]);
//                     }
//                     int last_frame_unused = fsize - (p[i].size % fsize);
//                     infrag += last_frame_unused ;  // Internal fragmentation
//                     printf("\n");
//                 }
//                 printf("\nRemaining Frames: %d\nInternal fragmentation: %d bytes\n", remfr, infrag);
//                 break;
//             }
//             case 2: {
//                 printf("Enter process ID:\n");
//                 scanf("%d", &pid);
//                 int d;
//                 for (d = 0; d < top; d++) {
//                     if (p[d].id == pid) {
//                         break;
//                     }
//                 }
//                 if (d == top) {
//                     printf("Process doesn't exist\n");
//                     break;
//                 }
//                 remfr += p[d].nofr;
//                 for (int i = d; i < top - 1; i++) {
//                     p[i] = p[i + 1];
//                 }
//                 top--;

//                 printf("\nProcess ID    Size    Frames\n");
//                 infrag = 0;
//                 for (int i = 0; i < top; i++) {
//                     printf("%7d%7d", p[i].id, p[i].size);
//                     for (int j = 0; j < p[i].nofr; j++) {
//                         printf("%4d ", p[i].fno[j]);
//                     }
//                     int last_frame_unused = fsize - (p[i].size % fsize);
//                     infrag += last_frame_unused % fsize;
//                     printf("\n");
//                 }
//                 printf("\nRemaining frames: %d\nInternal fragmentation: %d bytes\n", remfr, infrag);
//                 break;
//             }
//             case 3: {
//                 printf("Exiting the program!\n");
//                 exit(0);
//             }
//         }
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct process {
    int id;        
    int size;      
    int nofr;      
    int fno[10];   
} p[10];

int main() {
    int msize, fsize, totfr, remfr, ch;
    int top = 0;
    int infrag, pid;
    int total_infrag = 0;

    printf("Enter memory size(in kb): \n");
    scanf("%d", &msize);
    printf("Enter frame size:\n");
    scanf("%d", &fsize);
    totfr = msize / fsize;
    printf("Total no of frames available: %d\n", totfr);
    remfr = totfr;

    srand(time(NULL));

    while (1) {
        printf("\nMenu\n1. Insert\n2. Delete\n3. Display PCB\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                if (remfr == 0) {
                    printf("Memory full!\n");
                    break;
                }
                
                printf("Enter process ID :\n");
                scanf("%d", &p[top].id);
                printf("Enter process size:\n");
                scanf("%d", &p[top].size);

                p[top].nofr = (p[top].size + fsize - 1) / fsize;  // round-off considered
                if (p[top].nofr > remfr) {
                    printf("Memory full or insufficient space for this process!\n");
                    break;
                }
                remfr -= p[top].nofr;

                for (int i = 0; i < p[top].nofr; i++) {
                    p[top].fno[i] = rand() % totfr + 1;  //limited by total frame
                }

                int last_frame_unused = fsize - (p[top].size % fsize);
                if (p[top].size % fsize != 0) {
                    infrag = last_frame_unused;
                } else {
                    infrag = 0;
                }
                total_infrag += infrag;

                printf("Process allocated\n");
                printf("Internal Fragmentation: %d\n", total_infrag);
                top++;
                break;
            }
            case 2: {
                if (top == 0) {
                    printf("No processes to delete!\n");
                    break;
                }

                printf("Enter process ID (integer):\n");
                scanf("%d", &pid);

                int d;
                for (d = 0; d < top; d++) {
                    if (p[d].id == pid) {
                        break;
                    }
                }

                if (d == top) {
                    printf("Process doesn't exist\n");
                    break;
                }

                remfr += p[d].nofr;

                int last_frame_unused = fsize - (p[d].size % fsize);
                if (p[d].size % fsize != 0) {
                    total_infrag -= last_frame_unused;
                }

                for (int i = d; i < top - 1; i++) {
                    p[i] = p[i + 1];  
                }
                top--;

                printf("Process deleted\n");
                printf("Internal Fragmentation: %d\n", total_infrag);
                break;
            }
            case 3: {
                if (top == 0) {
                    printf("No processes to display!\n");
                    break;
                }

                printf("\nProcess Control Block\n");
                printf("-------------------------------------------------\n");
                printf("Process ID  Process Size   Frames Allocated\n");
                printf("-------------------------------------------------\n");
                for (int i = 0; i < top; i++) {
                    printf("%10d%14d", p[i].id, p[i].size);
                    for (int j = 0; j < p[i].nofr; j++) {
                        printf("%4d ", p[i].fno[j]);
                    }
                    printf("\n");
                }
                printf("-------------------------------------------------\n");
                printf("Total Internal Fragmentation: %d\n", total_infrag);
                break;
            }
            case 4: {
                printf("Exiting the program!\n");
                printf("\n");
                exit(0);
            }
            default: {
                printf("Invalid choice, please enter again!\n");
            }
        }
    }

    return 0;
}
