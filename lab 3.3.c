/*
 * III.	Дан целочисленный массив A[1:n].
 * Написать программу, включающую две функции с параметрами.
 * В первой функции необходимо подсчитать количество повторений каждого элемента массива A.
 * Вторая процедура решает следующую задачу:
 * сформировать новый массив, состоящий из элементов, которые повторяются в массиве A.
 */
#include <stdio.h>
#include <math.h>
#define lmax 20


void input_array(int *a,int n){
    printf("write array with %d elements:\n",n);
    for (int *pa=a;pa<a+n;++pa){
        int k=0; float p;
        while(k!=1 || *pa != p ){
            k = scanf("%f",&p);
            *pa=(int)p;
        }
    }
}


int new_array(const int *a, int *b, int n){
    int k = 0;
    for(int i=0; i<n; ++i){
        int flag = 1;
        for (int j=0; j<n && flag; ++j){
            flag = a[i]!=a[j] || i==j;
        }
        if(! flag) b[k++] = a[i];
    }
    return k;
}


int repeat(const int *a, int *b, int *Num, int n){
    int j, m=0;
    for (int i=0;i<n;++i){
        for(j=0; j<m && a[i]!=b[j]; ++j){}
        if(j==m)
            b[m++]=a[i];
        Num[j]+=1;
    }
    return m;
}


void print_array(const int *a, int n){
    printf("Array B:\n");
    for (int *pa=a; pa<a+n; ++pa){
        printf("%d ",*pa);
    }
}


int main() {
    int A[lmax], B[lmax], C[lmax], Num[lmax]={};
    int n=0,k=0, m=0;
    float p;
    printf("write n 1 to %d:\n",lmax);
    while (n<=0 || n>lmax || m!=1 || n != p){
        m = scanf("%f",&p);
        n = (int)p;
        while(getchar()!='\n');}
    input_array(A,n);
    m = repeat(A, C, Num, n);
    printf("numbers of repetitions:\n");
    for (int i=0; i<m; ++i){
        printf("'%d' = %d\n",C[i],Num[i]);
    }
    k = new_array(A,B,n);
    if(k==0){
        printf("Array B is empty");
    }
    else{ print_array(B, k);}
    return 0;
}
