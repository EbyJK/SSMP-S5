#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct process{
    int id;
    int size;
    int nofr;
    int fno[10];
}p[10];

int main(){
            int msize,fsize,totfr,remfr,ch;
            int top=0;
            printf("Enter memory size: \n");
            scanf("%d",&msize);
            printf("enter frame size:\n");
            scanf("%d",&fsize);
            totfr= msize/fsize;
            remfr=totfr;

            srand(time(NULL));

            printf("Select choice\n1.insert process\n2.delete process.\n3.exit.\n");

            while(1){
                printf("\nEnter choice:\n");
                scanf("%d",&ch);

                switch(ch){
                    case 1:{
                        if(remfr==0){
                            printf("memory is full!\n");
                            break;
                        }
                        printf("enter process ID:\n");
                        scanf("%d",&p[top].id);
                        printf("enter process size:\n");
                        scanf("%d",&p[top].size);
                        
                    }
                }
            }




 return 0;
}
