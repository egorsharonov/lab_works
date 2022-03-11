/*
 *Оформить в виде функции общую часть в предложенных формулах
 * x = c/a - (b*(f - c*d/a)) / (a*(e - b*d/a))
 * y = (f - d*c/a)/(e - b*d/a)
 */

#include <stdio.h>
float Frakt(float a, float b,float c,float d){
    return a - (b*c)/d;
}
int main() {
    float a=0, b, c, d, e, f, x, y;
    int k=0;
    printf("write a!=0, b, c, d, e, f; e - db/a != 0\n");
    while(a==0 || Frakt(e,d,b,a)==0 || k!=6){
        k=scanf("%f %f %f %f %f %f",&a,&b,&c,&d,&e,&f);
        while (getchar()!='\n');
    }

    x = Frakt(c/a, b, Frakt(f,d,c,a), a*Frakt(e,d,b,a));
    y = Frakt(f,d,c,a) / Frakt(e,d,b,a);
    printf("x = %f \ny = %f",x,y);
    return 0;
}
