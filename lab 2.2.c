/*
 * Сформировать новый массив,
 * состоящий из элементов исходного массива,
 * начинающихся с заданной цифры Q
 */
#include <stdio.h>
#include <stdlib.h>
#define lmax 30
int main() {
    int Q=0, k, w;
    int Z[lmax];
    printf("task 2\n");
    printf("write k 1 to %d:\n",lmax);
    float v;
    do {
        w = scanf("%f",&v);
        k = (int)v;
        while(getchar()!='\n');
    } while(!(k > 0 && k <= lmax && k==v && w==1));
    printf("write Array Z with %d elements\n",k);
    for(int i=0; i<k; ++i){
        do {
            w = scanf("%f", &v);
            Z[i] = (int)v;
        }while(Z[i]!=v || w!=1);}
    printf("write Q 1 to 9:\n");
    do{
        w = scanf("%f",&v);
        Q = (int)v;
        while(getchar()!='\n');
    } while(Q<1 || Q>9 || v!=Q || w!=1);
    int New[lmax];
    int l=0;
    for(int i=0; i<k; ++i){
        int digit = Z[i];
        while(digit > 10) digit/=10;
        if (digit == Q) New[l++] = Z[i];}
    int p = l;
    if(p==0) printf("New array is empty\n");
    else { printf("New array with %d elements\n", p);
              for (int i = 0; i < p; ++i)
              	printf("%5d ", New[i]);
        	    printf("\n");  }
    return 0;  
}
