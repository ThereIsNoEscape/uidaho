#include<stdio.h>

int main(){
    FILE *fp;
    char *mode = "w";
    while(1){
        fp = fopen("test.txt", mode);
        fprintf(fp, "a");
        fclose(fp);
    }
}