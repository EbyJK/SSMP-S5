#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char dname[50];  
    char fname[10][10];  
    int fcnt;  
} dir;

void main() {
    int i, ch;
    char f[30];

    dir.fcnt = 0;
    printf("\nEnter name of master file directory (MFD): ");
    scanf("%s", dir.dname);
    
    while (1) {
        printf("----------------------------------------------------------");
        printf("\n---MENU----\n");
        printf("\n 1. Create File\n 2. Delete File\n 3. Display Files\n 4. Search File\n 5. Exit\n ");
        printf("------------------------------------------------------------");
        printf("\nEnter choice: \n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the name of the file: ");
                scanf("%s", f);

             
                int fileExists = 0;
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        fileExists = 1;
                        break;
                    }
                }

                if (fileExists) {
                    printf("\nFile %s already exists in the directory! Cannot create duplicate files.\n", f);
                } else {
                    
                    strcpy(dir.fname[dir.fcnt], f);
                    dir.fcnt++;
                    printf("\nFile %s has been created successfully.\n", f);
                }
                break;

            case 2:
                printf("\nEnter the name of the file: ");
                scanf("%s", f);
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("\nFile %s is deleted from the directory!\n", f);
                        strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                        dir.fcnt--;
                        break;
                    }
                }
                if (i == dir.fcnt) {
                    printf("\nFile %s is not found in the directory\n", f);
                }
                break;

            case 3:
                if (dir.fcnt == 0) {
                    printf("\nDirectory is empty\n");
                } else {
                    printf("\nThe files are: \n");
                    for (i = 0; i < dir.fcnt; i++) {
                        printf("\t%s/%s\n", dir.dname, dir.fname[i]);
                    }
                }
                break;

            case 4:
                printf("\nEnter the name of the file: ");
                scanf("%s", f);
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("File %s is found at path: %s/%s\n", f, dir.dname, f);
                        break;
                    }
                }
                if (i == dir.fcnt) {
                    printf("\nAlas, file %s is not found\n", f);
                }
                break;

            case 5:
                printf("\nExiting the program!!\n\n");
                exit(0);
                break;

            default:
                printf("Invalid choice, please enter another choice!\n");
        }
    }
}
