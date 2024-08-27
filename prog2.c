#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILES 10
#define MAX_NAME 30

struct {
    char dname[MAX_NAME];
    char fname[MAX_FILES][MAX_NAME];
    int fcnt;
} dir[MAX_DIR];

char parentDir[MAX_NAME] = "";
int dcnt = 0;

int main() {
    int i, ch, k;
    char f[MAX_NAME], d[MAX_NAME];
    int flag = -1, flag1 = -1;

    printf("Do you want to use an existing parent directory or create a new one? (0 for existing, 1 for new): ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter parent directory name: ");
        scanf("%s", parentDir);
        printf("Parent directory '%s' created\n", parentDir);
    } else {
        printf("Enter parent directory name: ");
        scanf("%s", parentDir);
        printf("Using existing parent directory '%s'\n", parentDir);
    }

    while (1) {
        printf("---------------------------------------------\n");
        printf("---MENU---\n");
        printf("1. Create SubDirectory\n2. Create File\n3. Delete File\n4. Display Files & directory\n5. Search File & directory\n6. Delete Directory\n7. Exit\n");
        printf("---------------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (dcnt < MAX_DIR) {
                    printf("Enter subdirectory name: ");
                    scanf("%s", dir[dcnt].dname);
                    dir[dcnt].fcnt = 0;
                    dcnt++;
                    printf("subDirectory created\n");
                } else {
                    printf("Directory limit reached\n");
                }
                break;

            case 2:
                printf("Enter directory name where to create file: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter the name of the file: ");
                        scanf("%s", f);

                        int fileExists = 0;
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                fileExists = 1;
                                break;
                            }
                        }

                        if (fileExists) {
                            printf("File %s already exists in the directory '%s'. Cannot create duplicate files.\n", f, d);
                        } else {
                           
                            strcpy(dir[i].fname[dir[i].fcnt], f);
                            dir[i].fcnt++;
                            printf("File %s created in directory '%s'\n", f, d);
                        }
                        break;
                    }
                }
                if (i == dcnt) {
                    printf("Directory not found. Please create a directory or use another directory.\n");
                }
                break;

            case 3:
                printf("Enter the name of directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        flag = 1;
                        printf("Enter name of the file: ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                printf("File %s is deleted!\n", f);
                                dir[i].fcnt--;
                                strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                                flag1 = 1;
                                break;
                            }
                        }
                        if (flag1 == -1) {
                            printf("File %s not found!\n", f);
                        }
                        break;
                    }
                }
                if (flag == -1) {
                    printf("Directory %s not found!\n", d);
                }
                break;

            case 4:
                if (dcnt == 0) {
                    printf("No directories\n");
                } else {
                    printf("\nDirectory\t\tFiles\n");
                    for (i = 0; i < dcnt; i++) {
                        printf("%s\n", dir[i].dname);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            printf("\t\t\t%s\n", dir[i].fname[k]);
                        }
                    }
                }
                break;

            case 5:
                printf("Enter name of directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        flag = 1;
                        printf("Enter the name of the file: ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                flag1 = 1;
                                printf("File %s found\n", f);
                                printf("File path: %s/%s/%s\n", parentDir, d, f);
                                break;
                            }
                        }
                        if (flag1 == -1) {
                            printf("File %s not found\n", f);
                        }
                        break;
                    }
                }
                if (flag == -1) {
                    printf("Directory not found!\n");
                }
                break;

            case 6:
                printf("Enter directory name to delete: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        flag = 1;
                      if (dir[i].fcnt>0){

printf("Directory '%s' cannot be deleted as it has %d files\n", d,dir[i].fcnt);
}else{
                      for (int j = i; j < dcnt - 1; j++) {
                            dir[j] = dir[j + 1];
                        }
                        dcnt--;
                        printf("Directory '%s' is deleted\n", d);}
                        break;
                    }
                }
                if (flag == -1) {
                    printf("Directory %s not found!\n", d);
                }
                break;

            case 7:
                printf("Exiting program!\n");
                printf("--------------------------\n");
                exit(0);

            default:
                printf("Invalid choice, Enter another choice..\n");
        }
    }

    return 0;
}
