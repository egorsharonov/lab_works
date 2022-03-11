/*
 *В заданной целочисленной прямоугольной матрице поменять местами следующие два элемента:
 * два наибольших по абсолютной величине.
 */

#include <iostream>
#include <iomanip>
using namespace std;
#define lmax 5


void read(int &n, int &m, int a[lmax][lmax]){
    cout << "write number lines and columns of matrix a\n";
    while(n<1 || n>lmax || m<1 || m>lmax)
        cin >> n >> m;
    cout << "write matrix a with " << n << " lines and " << m << " columns\n";
    for( int (*p)[lmax]=a; p < a + n; ++p)
        for( int *pp=*p; pp < *p + m; ++pp){
            cin >> *pp;
        }
}


bool task(int &n, int &m, int a[lmax][lmax]){
    int *max1=NULL,*max2=NULL;
    for( int (*p)[lmax]=a; p < a + n; ++p)
        for( int *pp=*p; pp < *p + m; ++pp){
            if(max1==NULL) max1=pp;
            else if( abs(*max1)>=abs(*pp) && (max2==NULL || abs(*max2) < abs(*pp))) max2=pp;
            else if (abs(*max1)<abs(*pp)) {max2=max1;max1=pp;}
        }
    swap(*max1,*max2);
    return *max1!=*max2;
}


void print(int &n, int &m, int a[lmax][lmax]){
    cout << "matrix a:\n";
    for( int (*p)[lmax]=a; p < a + n; ++p){
        for( int *pp=*p; pp < *p + m; ++pp){
            cout << setw(4) << *pp << " ";
        }
        cout << "\n";
    }


}


int main() {
    int a[lmax][lmax],n=0,m=0;
    read(n,m,a);
    cout << "At the begin ";
    print(n,m,a);
    bool f = false;
    if(n*m>1) f = task(n,m,a);
    if(f){
        cout << "At the end ";
        print(n,m,a);
    }
    else{
        cout << "Matrix didn't change\n";
    }
    return 0;
}
