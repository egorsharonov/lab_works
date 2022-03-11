/*
 * Даны два одномерных массива целых чисел A и В.
 * Вычислить одномерный массив С, который содержит:
 * положительные элементы массива A,
 * присутствующие в массиве B несколько раз.
 */

#include <iostream>
#define lmax 30
using namespace std;

void read(int &n, int* a,char c){
    cout << "write len of array " << c <<":\n";
    while(n<1 || n>lmax)
        cin >> n;
    cout << "write array " << c <<"\n";
    for(int i=0; i<n; ++i, ++a){
        cin >> *a;
    }
}


bool inB(int x, int nb, int* b){
    int count=0;
    for(int i=0;i<nb;++i, ++b){
        count += (*b==x);
        if(count>1) return true;
    }
    return false;
}


int task(int na,int* a,int nb,int* b,int* c){
    int nc=0;
    for(int i=0; i<na; ++i, ++a){
        if(*a>0 && inB(*a, nb,b) ){
            *(c++)=*a;
            ++nc;
        }
    }
    return nc;
}


void print(int n, int* c, char s){
    cout << "Array " << s <<":\n";
    for(int i=0; i<n; ++i,++c)
        cout << *c << " ";
    cout << "\n";
}


int main() {
    int a[lmax],b[lmax],c[2*lmax], na=0, nb=0, nc=0;
    read(na,a, 'a');
    read(nb,b,'b');
    nc = task(na,a,nb,b,c);
    print(na,a,'a');
    print(nb,b,'b');
    if(nc>0)
        print(nc,c, 'c');
    else cout << "Array c is empty";
    return 0;
}
