#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
char h[5];
void int_to_hex(int num,char hex[]);
void main(){
    FILE *objectprogram,*intermediate_file,*symbtab,*optab,*program_size;
    objectprogram=fopen("objectprogram.txt","r");
    optab=fopen("optab.txt","r");
    symbtab=fopen("symbtab.txt","r");
    intermediate_file=fopen("intermediatefile.txt","w");
    program_size=fopen("size.txt","w");

    char str1[100],str2[100],str3[100],s1[100],s2[100],start[100],temp[100];
    char str[100]="";
    int need=0,size;
    strcat(str,"H");
    fscanf(intermediate_file,"%s %s %s",str1,str2,str3);
    strcat(str,str1);
    strcpy(start,str3);
    if(strlen(start)<6){
        need=6-strlen(start);
        for(int i=0;i<need;i++){
            strcat(str,"0");
        }
        strcat(str,start);
    }
    else if(strlen(start)==6){
        strcat(str,start);

    }
    fscanf(program_size,"%d",&size);
    int_to_hex(size,h);
    strcpy(temp,"");
    if(strlen(h)<6){
        need=6-strlen(h);
        for(int i=0;i<need;i++){
            strcat(str,"0");
        }
        strcat(str,h);
    }
    else if(strlen(h)==6){      
        strcat(str,h);

    }
    fprintf(objectprogram,"%s\n",str);
    strcpy(str,"");
    strcat(str,"T");
    if(strlen(start)<6){
        need=6-strlen(start);
        for(int i=0;i<need;i++){
            strcat(str,"0");
        }
        strcat(str,start);
    }
    else if(strlen(start)==6){
        strcat(str,start);
    }
    //


}
void int_to_hex(int num,char hex[]){
for (int j=0;j<4;j++){
hex[j]='0';
}
hex[4]='\0';
int i=3;
while(num!=0){
int remainder=num%16;
if(remainder<10){
hex[i]=remainder+48;

}else{

hex[i]=(remainder-10)+65;
}
num/=16;
i--;

}
}