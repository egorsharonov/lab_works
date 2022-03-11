/*
 * I.	Создать файл для хранения действительных чисел, вводимых с клавиатуры.
 * Прочитать этот файл и вычислить минимальное число среди чисел с четными номерами.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define lmax 20
#define clr while(getchar()!='\n');


float read(void){
    char str[80]; float n; int k, f=0;
    do{
        k=scanf("%s", str);
        if(k){
            if(strcmp(str,"0")==0) n=0,f=1;
            else if(strcmp(str,"")!=0){
                char *s=str;
                while(isdigit(*s) || *s=='.' || *s=='-')
                    s++;
                if(!*s){
                    n=atof(str);
                    if(n) f=1;}
            }
        }
    }
    while (!f);
    clr;
    return n;
}


int main() {
    FILE* f = fopen("output.txt","w+");
    int n=0; float x=1;
    printf("write number of digits from 1 to %d\n",lmax);
    while(x!=n || n<1 || n>lmax){
        n = x = read();
    }
    printf("write %d digits\n",n);
    for(int i=0; i<n; ++i){
        x = read();
        fprintf(f,"%f\n",x);
    }
    fclose(f);
    f = fopen("output.txt","r");
    float min=10e10;
    if(n<2){
        printf("Only one digit\n");
    }else{
        for(int i=1;!feof(f);++i){
            fscanf(f, "%f\n",&x);
            if(i%2==0 && min > x){
                min = x;
            }
        }
        printf("%f",min);
    }
    fclose(f);
    return 0;
}
