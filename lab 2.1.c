/*
Даны целочисленная матрица X[1:n, 1:m] и целочисленный массив Z[1:k].
 Обнулить элементы матрицы X, которых нет в массиве Z и запомнить обнуленные элементы.
 Для решения задачи необходимо использовать алгоритмы с досрочным выходом из цикла.
*/
#include <stdio.h>
#include <stdlib.h>
#define lmax 30
int main()
{
    int m=0, n=0, k=0,w;
    float g,y,v;
    int Z[lmax], X[lmax][lmax];
    printf("task 1\n");
    printf("write n, m, k 1 to %d:\n",lmax);
    do {
        w = scanf("%f%f%f",&g,&y,&v);
        n = (int)g;
        m = (int)y;
        k = (int)v;
        while(getchar()!='\n');
    } while(!(w==3 && n > 0 && n <= lmax && m > 0 && m <= lmax && k > 0 && k <= lmax && n==g && m==y && k==v));
    printf("write Array X with %d line and %d columns:\n",n,m);
    for(int i=0; i<n; ++i)
        for (int j = 0; j < m; ++j) {
            do {
                w = scanf("%f", &v);
                X[i][j] = (int) v;
            } while (v != X[i][j] || w!=1);

        }
    printf("write Array Z with %d elements\n",k);
    for(int i=0; i<k; ++i){
        do {
            w = scanf("%f",&v);
            Z[i] = (int)v;
        } while(v!=Z[i] || w!=1);

    }
    int l=0;
    int Mem[lmax];
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j){
            int flag = 1;
            for(int h=0; h<k && flag; ++h) flag = Z[h]!=X[i][j];
            if(flag){
                Mem[l++]=X[i][j];
                X[i][j]=0;
            }
        }
    int t=l;
    if(t==0) printf("No saved\n");
    else{
        printf("Array X with %d line and %d columns:\n",n,m);
        for(int i=0; i<n; ++i) {
            for (int j = 0; j < m; ++j)
                printf("%5d ", X[i][j]);
            printf("\n");
        }
        printf("Saved valumes:\n");
        for(int i=0; i<t; ++i)
            printf("%d ",Mem[i]);
        printf("\n");
    }

    return 0;
}
