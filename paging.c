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
            int infrag,pid;
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
                        
                        p[top].nofr=(p[top].size+fsize-1)/fsize;
                        if(p[top].nofr>remfr){
                            printf("Memory overflow!\n choose a smaller size!\n");
                        }
                        remfr -= p[top].nofr;

                        for(int i=0;i<p[top].nofr;i++){
                            p[top].fno[i] =rand() % msize +1;
                        }
                        top++;

                        printf("\n Process SIze Frames\n");
                        infrag=0;
                        for(int i=0;i<top;i++){
                            printf("%7d%7d", p[i].id,p[i].size);
                            for(int j=0;j<p[i].nofr;j++){
                                printf("%2d",p[i].fno[j]);
                            }
                            int last_frame_unused=fsize -(p[i].size%fsize);
                            if(last_frame_unused!=fsize)
                             {
                                infrag += last_frame_unused;
                             }
                             printf("\n");


                        }
                        printf("\nRemaining Frames: %d\nInternal fragmentation: %d bytes\n",remfr,infrag);
                        break;
                    }
                    case 2:{
                        int d;
                        printf("Enter process ID:\n");
                        scanf("%d",&pid);
                        for(d=0;d< top;d++){
                            if(p[d].id == pid){
                                break;
                            }
                        }
                        if(d==top){
                            printf("Process doesn't exist\n");
                            break;
                        }
                        remfr += p[d].nofr;
                        for(int i=d; i<top-1;i++){
                            p[i]=p[i+1];

                        }
                        top --;
                        printf("\n process size frames\n");
                        infrag=0;
                        for(int i=0;i<top;i++){
                            printf("%7d%7d",p[i].id,p[i].size);
                            for(int j=0;j<p[i].nofr;j++){
                                printf("%2d",p[i].fno[j]);

                            }
                            int last_frame_unused =fsize-(p[i].size% fsize);
                            if(last_frame_unused !=fsize){
                                infrag += last_frame_unused;

                            }
                            printf("\n");
                        } 
                        printf("\nRemaining frames: %d\nInternal fragmentation: %d bytes\n",remfr,infrag);
                        break;

                    }
                    case 3:
                    {
                        printf("Exitting the program!\n");
                        exit(0);
                    }
                }
            }




 return 0;
}
