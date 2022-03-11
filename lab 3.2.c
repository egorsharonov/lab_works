/*
 * вычислить значения по формуле
 * v = min{i=1,n}( max{j=1,m-1}( |c[i][j]-c[i][j+1]| ) )
 */
#include <stdio.h>
#include <math.h>
#define lmax 20

void input_matrix(int n, int m, float (*a)[lmax]){
    printf("write matrix with %d lines and %d columns:\n", n, m);
    for (float (*pa)[lmax]=a; pa<a+n;++pa)
        for (float *ppa=*pa; ppa<*pa+m; ++ppa){
            scanf("%f",ppa);
        }

}

float max_delta(float *a, int m){
    float max=0, curr;
    for(float *pa=a; pa<a+m-1; ++pa){
        curr = fabs(*pa - *(pa+1));
        max = (curr > max) ? curr : max;
    }
    return max;
}

float min(int n, int m, float (*a)[lmax]){
    float min=max_delta(*a, m), curr;
    for(float (*pa)[lmax]=a+1; pa<a+n; ++pa){
        curr = max_delta(*pa, m);
        min = (curr < min) ? curr : min;
    }
    return min;
}

int main() {
    float C[lmax][lmax];
    int n=0,m=0,k=0;
    float p,l,v;
    printf("write n, m 1 to %d:\n", lmax);
    while (n<=0 || n>lmax || m<=0 || m>lmax || k!=2 || n != p || m != l){
        k = scanf("%f %f", &p, &l);
        n = (int)p;
        m = (int)l;
        while(getchar()!='\n');
    }

    input_matrix(n, m, C);
    if(m==1){
        printf("only 1 element in lines");
    }
    else{
        v = min(n, m, C);
        printf("v = %f", v);
    }
    return 0;
}
