#include<stdio.h>
#include<stdlib.h>
struct process
{
	int id;
	int size;
	int fn;
	int f[10];
}p[10];
void main()
{
	int m,n,i,tm,f,ch,top=0,rf,pid,ind,infr;
	printf("Enter memory size: ");
	scanf("%d",&m);
	printf("Enter frame size: ");
	scanf("%d",&f);
	tm=m/f;
	rf=tm;
	printf("Select choice\n[1]Insert process\n[2]Delete process\n[3]Exit");
	while(1)
	{
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				if(rf==0)
				{
					printf("Memory is full!\n");
					break;
				}
				printf("Enter process ID: ");
				scanf("%d",&p[top].id);
				printf("Enter process size: ");
				scanf("%d",&p[top].size);
				p[top].fn=(p[top].size+tm-1)/tm;
				rf-=p[top].fn;
				if(rf<0)
				{
					printf("Memory overflow!\nChoose smaller size!\n");
					rf+=p[top].fn;
					break;
				}
				for(i=0;i<p[top].fn;i++)
					p[top].f[i]=rand()%f+1;
				top++;
				printf("\nProcess   Size   Frames\n");
				infr=0;
				for(i=0;i<top;i++)
				{
					printf("%7d%7d  ",p[i].id,p[i].size);
					infr+=p[i].size;
					for(int j=0;j<p[i].fn;j++)
					{
						printf("%2d",p[i].f[j]);
					}
					printf("\n");
				}
				infr=m-infr;
				printf("\nRemaining frames: %d\nInternal fragmentation: %d\n",rf,infr);
				break;
			}
			case 2:
			{
				printf("Enter process ID: ");
				scanf("%d",&pid);
				for(i=0;i<top;i++)
					if(p[i].id==pid)
					{
						ind=i;
						break;
					}
				if(i==top)
				{
					printf("Process dosen't exist\n");
					break;
				}
				rf+=p[ind].fn;
				struct process temp;
				for(i=ind;i<top-1;i++)
				{
					temp=p[i];
					p[i]=p[i+1];
					temp=p[i];
				}
				top--;
				printf("\nProcess   Size   Frames\n");
				infr=0;
				for(i=0;i<top;i++)
				{
					printf("%7d%7d  ",p[i].id,p[i].size);
					infr+=p[i].size;
					for(int j=0;j<p[i].fn;j++)
					{
						printf("%2d",p[i].f[j]);
					}
					printf("\n");
				}
				infr=m-infr;
				printf("\nRemaining frames: %d\nInternal fragmentation: %d\n",rf,infr);
				break;
			}
			case 3:
				exit(0);
		}
	}
}
