#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
char h[5];
int hex_to_int(char s[]);
void int_to_hex(int num,char hex[]);
void main(){
        FILE *input_file,*intermediate_file,*symbtab,*optab, *program_size;
        input_file=fopen("input.txt","r");
        optab=fopen("optab.txt","r");
        symbtab=fopen("symbtab.txt","w");
        intermediate_file=fopen("intermediatefile.txt","w");
        program_size=fopen("size.txt","w");

        char str1[100],str2[100],str3[100],s1[100],s2[100],start[100];
        int locctr,error=0,prev=0;
        fscanf(input_file,"%s %s %s\n",str1,str2,str3);
        strcpy(start,str3);
        if (strcmp(str3,"--")==0){
            printf("error!\n");
            exit(0);
        }
        if(strcmp(str2,"START")!=0){
            printf("No start!\n");
            exit(0);

        }
        locctr=hex_to_int(str3);
        fprintf(intermediate_file," %s %s %s\n",str1,str2,str3);
        prev=locctr;
        while(1){
            strcpy(str1,"");
            strcpy(str2,"");
            strcpy(str3,"");
            fscanf(input_file,"%s %s %s",str1,str2,str3);
            if(strcmp(str1,"END")==0){
                printf("Pass1 COmplete\n");
                fprintf(intermediate_file,"%s %s",str1,start);
                break;
            }
            if(strcmp(str1,"-")!=0){
                while(fscanf(symbtab,"%s %s",s1,s2)!=EOF){
                    if(strcmp(s1,str1)==0){
                        printf("Already exisiting in symbol table\n");
                        exit(0);

                    }
                }
                int_to_hex(locctr,h);
                fprintf(symbtab,"%s %s\n",str1,h);
            }
            int flag=0;
            while(fscanf(optab,"%s %s",s1,s2)!=EOF){
                if(strcmp(s1,str2)==0){
                    flag=1;
                    locctr+=3;
                    break;
                }
            }
            rewind(optab);
            if(flag==0){
                if(strcmp(str2,"WORD")==0){
                        locctr+=3;
                }
                else if(strcmp(str2,"RESW")==0){
                    locctr+=3*atoi(str3);

                }
                else if(strcmp(str2,"RESB")==0){
                    locctr+=atoi(str3);


                }
                else if(strcmp(str2,"BYTE")==0){
                    locctr+=strlen(str3)-3;

                }
                else{
                    printf("error in opcode %s\n",str2);
                    exit(0);

                }
            }
            int_to_hex(prev,h);
            prev=locctr;
            fprintf(intermediate_file,"%s %s %s %s\n",h,str1,str2,str3);
        }
fprintf(program_size, "Program size: %d\n", locctr - hex_to_int(start));


}
int hex_to_int(char s[]){
  int value=0;
  for (int i=0;i<strlen(s);i++){
char c=s[strlen(s)-1-i];
int digit=0;
if(c>='0'&& c<='9'){
digit =c-'0';


}
else if(c>='A'&& c<='F'){
digit=c-'A'+10;


}
value+=digit*pow(16,i);

}
return value;

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