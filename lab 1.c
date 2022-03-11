/*
 * 1)   Вычислить массив R[1:n] в соответствии с формулой
 * R[i]=6*cos(a*x+i*h) , где i =¯(1,n) и x, h, a – заданы.
 * Из вычисленного массива R удалить все элементы, удовлетворяющие условию │R[i]│ < 0.7;
 * В полученном массиве R[1:k], где k – число элементов,
 оставшихся после удаления, подсчитать среднее арифметическое элементов,
 расположенных до первого минимального по модулю отрицательного элемента.
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=0,lmax=10E2;
    printf("task 1\n");
    printf("write lenght of array R 1 to %d\n",lmax);
    while(n<1 || n>lmax){
        scanf("%d",&n);
    }
    float R[n+1],x,h,a;
    printf("write x, h, a\n");
    scanf("%f%f%f",&x,&h,&a);
    for(int i=1;i<=n;++i){
        R[i]=6*cos(a*x+i*h);
    }
    printf("array with %d elements:\n",n);
    for(int i=1;i<=n;++i){
        printf("%f\t",R[i]);
    }
    printf("\n");
    printf("task 2\n");
    int j=0;
    for(int i=1;i<=n;++i){
        if( fabs(R[i])>=0.7 ){
            j++;
            R[j]=R[i];
        }
    }
    int k=j;
    if(k==0) printf("array is empty\n");
    else if(k==n) printf("No deletions\n");
    else{
        for(int i=1;i<=k;++i) {
            printf("%f\t",R[i]);
        }
        printf("\n");
    }
    printf("task 3\n");
    float mid=0;
    int nmin=0;
    float min=-lmax;
    for(int i=1;i<=k;++i){
        if(R[i]<0 && R[i]>min) {
            nmin=i;
            min=R[i];
        }
    }
    if(nmin==0) printf("No negative elements or Array is empty");
    else if(nmin==1) printf("None");
    else{
        for(int i=1;i<=nmin-1;++i){
                mid+=R[i];
            }
        mid/=nmin-1;
        printf("mid = %f",mid);
    }
    return 0;
}
