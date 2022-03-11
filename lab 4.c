/*
 * Дано k символьных строк.
 * Каждая строка содержит латинские и русские буквы, цифры, а также все возможные разделители.
 * Требуется:
 *  I.      Выделить из каждой строки и напечатать подстроки,
 *  ограниченные с обеих сторон одной или несколькими русскими буквами
 *  II.	    Среди выделенных подстрок найти подстроку,
 *  начинающуюся с четного (но не нулевого) числа цифр
 *  (если таких подстрок несколько, выбирается первая из них)
 *  III.	Преобразовать исходную строку, которой принадлежит найденная подстрока, следующим образом:
 *  удалить путем сдвига все латинские буквы;
 */
#include <stdio.h>
#include <ctype.h>
#define lmax 50


int isAl(char c){
    int f;
    f = ((c >= -128 && c <= -81)||(c >= -32 && c <= -15));
    return f;
}


int main() {
    //ввод
    char Lines[lmax+1][lmax+1];
    char SubLines[lmax*lmax][lmax+1];
    int LineNum[lmax*lmax];
    printf("write k 1 to %d:\n",lmax);
    int k=0, flag=0;
    while (!flag){
        int n=0; float p;
        n = scanf("%f",&p);
        k = (int)p;
        while(getchar()!='\n');
        flag = n==1 && k==p && k>0 && k<=lmax;
    }
    printf("write %d lines with length no more %d\n",k,lmax);
    for(int i=0; i<k; ++i){
        gets(Lines[i]);
    }
    //обход строк
    int kol = 0; // количество подстрок
    for(int i=0; i<k; ++i){
        int len = 0; // длина текущей подстроки
        for(char* c=Lines[i]; *c!='\0'; ++c){ // цикл по строке
            if(!isAl(*c) && ( len==0 && isAl(*(c-1)) || len>0 )){ // текущая подстрока
                SubLines[kol][len++]=*c;
            }
            else if( len>0 && isAl(*c) ){ //конец текущей подстроки
                LineNum[kol]=i;
                SubLines[kol++][len]='\0';
                len=0;
            }
        }
    }
    if(kol==0){
        printf("No SubLines");
    }
    else{
        printf("SubLines:\n");
        for(int i=0; i<kol; ++i){
            printf("%s\n",SubLines[i]);
        }
    }
    //выбор подстроки
    flag=0;
    int index=lmax;
    for(int i=0; i<kol && !flag; ++i){
        int count=0;
        for(char* c=SubLines[i]; *c!='\0' && isdigit(*c); ++count,++c ){}
        if(count%2==0 && count!=0){
            index=LineNum[i];
            printf("Correct SubLine:\n%s\n",SubLines[i]);
            flag = 1;
        }
    }
    if(!flag && kol>0){
        printf("Correct SubLine is absent");
    }
    //изменение строки выбранной подстроки
    if(flag){
        int newlen=0;
        for(char* c=Lines[index]; *c!='\0'; ++c){
            if(!isalpha(*c)) Lines[index][newlen++]=*c;
        }
        Lines[index][newlen]='\0';
        printf("Changed Line:\n%s",Lines[index]);
    }
    return 0;
}
