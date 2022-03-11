/*
 * После ввода массива структур программа ищет в нем следующую информацию
 * (все данные в полученном массиве должны быть различны):
 * Названия книг, изданных в указанном городе, цена которых не превышает 500 р.
 */

#include <stdio.h>
#include <string.h>
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


int input(struct book *bk){
    int n=0;
    float tmp, r;
    puts("write number of books");
    while(tmp!=1 || r != n || n<=0 || n>lmax){
        tmp = scanf("%f",&r);
        CLR
        n = (int)r;
    }
    for(int i=0; i<n; ++i){
        printf("Title............");gets(bk[i].name);
        printf("Price............");scanf("%f", &bk[i].price);
        printf("Pages............");scanf("%d", &bk[i].num);CLR
        printf("Author...........");gets(bk[i].auth);
        printf("publishing\n");
        printf("\tyear...........");scanf("%d",&bk[i].publish.year);CLR
        printf("\t\t\bname...........");gets(bk[i].publish.name);
        printf("\t\t\b\bcity...........");gets(bk[i].publish.city);
    }
    return n;
}


void output(char names[lmax][ln], int k){
    puts("Appropriate books:");
    for(int i=0; i<k; ++i){
        printf("%s\n",names[i]);
    }
    printf("\n");
}


void output2(struct book *bk, int n){
    for(int i=0; i<n; ++i){
        printf("Title............");puts(bk[i].name);
        printf("Price............");printf("%f\n", bk[i].price);
        printf("Pages............");printf("%d\n", bk[i].num);
        printf("Author...........");puts(bk[i].auth);
        printf("publishing\n");
        printf("\tyear...........");printf("%d\n",bk[i].publish.year);
        printf("\tname...........");puts(bk[i].publish.name);
        printf("\tcity...........");puts(bk[i].publish.city);
        printf("\n");
    }
}


int name(struct book *bk, char names[lmax][ln], int n){
    int k=0;
    char city[lc];
    puts("write searching city");
    scanf("%s",city);
    for(int i=0; i<n; ++i){
        if(!strcmp(city,bk[i].publish.city) && bk[i].price <= 500){
            int flag=0;
            for(int j=0; j<k && !flag;++j){
                flag = !strcmp(bk[i].name,names[j]);
            }
            if(!flag) strcpy(names[k++],bk[i].name);
        }
    }
    return k;
}


int main() {
    struct book bk[lmax];
    int n = input(bk);
    char names[lmax][ln]={};
    int k = name(bk, names, n);
    if(k==0){
        printf("No appropriate books\n\n");
    } else{
        output(names, k);
    }
    output2(bk,n);
    return 0;
}
