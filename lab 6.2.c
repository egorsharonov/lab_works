/*
 * Модифицировать программу, написанную в первом пункте, таким образом,
 * чтобы она вводила структуры из текстового файла и записывала результаты в файл.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ln 40
#define lc 15
#define lmax 100
#define CLR while (getchar()!='\n');


struct book {
    char name[ln];
    int num;
    float price;
    char auth[ln];
    struct{
        int year;
        char name[ln];
        char city[lc];
    }publish;
};


void deln(char *s){
    for(;*s && *s!='\n';++s);
    *s='\0';
}


int input(struct book *bk, FILE* f1){
    int n=0;
    float tmp, r;
    puts("write number of books");
    while(tmp!=1 || r != n || n<=0 || n>lmax){
        tmp = scanf("%f",&r);
        CLR
        n = (int)r;
    }
    for(int i=0; i<n; ++i){
        fgets(bk->name,ln,f1);deln(bk->name);
        fscanf(f1,"%f", &bk->price);
        fscanf(f1,"%d\n", &bk->num);
        fgets(bk->auth,ln,f1);deln(bk->auth);
        fscanf(f1,"%d\n",&bk->publish.year);
        fgets(bk->publish.name,ln,f1);deln(bk->publish.name);
        fgets(bk->publish.city,lc,f1);deln(bk->publish.city);
        ++bk;
    }
    return n;
}


void output(char names[lmax][ln], int k, FILE *f2){
    puts("Appropriate books:");
    fputs("Appropriate books:\n",f2);
    for(int i=0; i<k; ++i){
        printf("%s\n",names[i]);
        fprintf(f2,"%s\n",names[i]);
    }
    printf("\n");
}


void output2(struct book *bk, int n){
    for(int i=0; i<n; ++i){
        printf("Title............");puts(bk->name);
        printf("Price............");printf("%f\n", bk->price);
        printf("Pages............");printf("%d\n", bk->num);
        printf("Author...........");puts(bk->auth);
        printf("publishing\n");
        printf("\tyear...........");printf("%d\n",bk->publish.year);
        printf("\tname...........");puts(bk->publish.name);
        printf("\tcity...........");puts(bk->publish.city);
        printf("\n");
        ++bk;
    }
}


int name(struct book *bk, char names[lmax][ln], int n){
    int k=0;
    char city[lc];
    puts("write searching city");
    scanf("%s",city);
    for(int i=0; i<n; ++i){
        if(!strcmp(city,bk->publish.city) && bk->price <= 500){
            int flag=0;
            for(int j=0; j<k && !flag;++j){
                flag = !strcmp(bk->name,names[j]);
            }
            if(!flag) strcpy(names[k++],bk->name);
        }
        ++bk;
    }
    return k;
}


int main() {
    char name1[20], name2[20];
    printf("write names of input and output files\n");
    scanf("%s %s",name1,name2);
    FILE *f1,*f2;
    if( !(f1=fopen(name1, "r+")) ){
        puts("File no found");
        exit(1);
    }
    f2 = fopen(name2, "w+");
    struct book bk[lmax];
    int n = input(bk,f1);
    char names[lmax][ln]={};
    int k = name(bk, names, n);
    if(k==0){
        printf("No appropriate books\n\n");
        fprintf(f2,"No appropriate books\n");
    } else{
        output(names, k, f2);
    }
    output2(bk,n);
    return 0;
}
