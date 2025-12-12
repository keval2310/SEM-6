#include <stdio.h>

int main(){
    FILE *f1,*f2;
    f1=fopen("input.txt","r");
    if(f1==NULL){
        printf("File not found");
    }

    f2=fopen("output.txt","w");

    char c,next;
    while((c=fgetc(f1))!=EOF){
        if(c=='/'){
            next=fgetc(f1);
            if(next=='/'){
                while((c=fgetc(f1))!='\n' && c!=EOF);
                    fputc('\n',f2);
            }
            else if(next=='*'){
                while((c=fgetc(f1))!=EOF){
                    if(c=='*'){
                        next=fgetc(f1);
                        if(next=='/'){
                            break;
                        }
                    }
                }
            }
            else{
                fputc(c,f2);
                fputc(next,f2);
            }
        }
        else{
            fputc(c,f2);
        }
    }
    fclose(f1);
    fclose(f2); 
    return 0;
}