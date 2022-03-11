/*
 * II.	Создать текстовый файл средствами редактора (т.е. в «Блокноте»).
 * Прочитать этот файл построчно и произвести в каждой строке следующие действия:
 * заменить каждую цифру соответствующей ей латинской буквой (‘0’ на ‘A’, ‘1’ на ‘B’ и т.д.).
 * Записать каждую полученную строку в новый текстовый файл и
 * вывести полученные строки из файла на экран.
 * Имена входного и выходного файла задаются пользователем.
 */

#include <stdio.h>
#include <ctype.h>
#define lmax 30


int main() {
    char name[20]; char name2[20];
    printf("write names of input and output files\n");
    scanf("%s %s",name,name2);
    FILE* f = fopen(name,"r");
    FILE* f2 = fopen(name2,"w+");
    char line[lmax];
    while(!feof(f)){
        fgets(line, lmax, f);
        for(char* c=line; *c!='\0'; ++c){
            if(isdigit(*c)) *c+='A'-'0';
        }
        fprintf(f2,"%s",line);
    }
    fclose(f2);
    f2 = fopen(name2,"r");
    while(!feof(f2)){
        fgets(line,lmax,f2);
        printf("%s",line);
    }
    fclose(f);
    fclose(f2);
    return 0;
}
