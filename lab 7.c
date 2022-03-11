/*
 * 1.   Создать связанный список для хранения целых чисел.
 * Число записей неизвестно, но можно ввести число (у меня 0),
 * являющееся признаком окончания ввода данных.
 * Для четных номеров вариантов организовать очередь, а для нечетных – стек.
 * 2.    Для исходного списка решить следующую задачу:
 * удалить из списка элементы, большие среднего арифметического.
 * 3.   Для полученного списка решить следующую задачу:
 * выбрать из списка все четные элементы и сформировать из них новую очередь.
 */

#include <stdio.h>
#include <malloc.h>
#define lmax 30


struct node{
    int info; struct node* next;
};


struct node* queue(FILE* f1){
    struct node *last,*curr,*first;
    last=first=NULL;
    int f=1;
    while(f){
        int d;
        fscanf(f1,"%d",&d);
        if(d==0){f=0; continue;}
        curr = (struct node*) malloc(sizeof(struct node));
        curr->info=d;
        if(first==NULL) first = curr;
        else last->next = curr;
        last = curr;
    }
    if(first) last -> next = NULL;
    return first;
}


void print(struct node* lst, FILE* f2){
    while(lst){
        fprintf(f2,"%3d ",lst->info);
        lst = lst->next;
    }
    fprintf(f2,"\n");
}


struct node* task_two(struct node* lst){
    int sum=0, num=0; struct node *p,*prev;
    p = lst;
    double middle;
    while(p){
        sum += p->info;
        ++num;
        p = p->next;
    }
    middle = (double)sum / num; p = prev = lst;
    while(p){
        int at_start = prev==p;
        if(p->info > middle){
            prev -> next = p -> next;
            if(at_start){
                lst = lst -> next;
                prev = prev -> next;
            }
            free(p);
            p = at_start ? prev : prev->next;
        }
        else{
            if(!at_start) prev = prev -> next;
            p = p->next;
        }
    }
    return lst;
}


struct node* task_three(struct node* lst){
    struct node *new_lst,*curr,*last;
    new_lst=last=NULL;
    while(lst){
        if(!(lst->info % 2)){
            curr = (struct node*) malloc(sizeof(struct node));
            curr->info = lst->info;
            if(new_lst==NULL) new_lst = curr;
            else last->next = curr;
            last = curr;
        }
        lst = lst -> next;
    }
    if(new_lst) last->next = NULL;
    return new_lst;
}


void del(struct node* q){
    struct node* temp;
    while(q){
        temp=q;
        q = q -> next;
        free(temp);
    }
}


int main(){
    puts("write names of input and output files:");
    char s1[lmax],s2[lmax];
    scanf("%s %s",s1,s2);
    FILE *f1, *f2;
    if( !(f1=fopen(s1, "r+")) ){
        puts("File no found");
        exit(1);
    }
    f2 = fopen(s2,"w+");
    struct node* q = queue(f1);
    if(q){
        fputs("task 1, My queue:\n",f2);
        print(q,f2);
        task_two(q);
        fputs("task 2, changed queue:\n",f2);
        print(q,f2);
        struct node* q2 = task_three(q);
        if(q2){
            fputs("task 3, new queue:\n",f2);
            print(q2,f2);
            del(q2);
        } else fputs("New queue is empty:\n",f2);
    } else fputs("Queue is empty",f2);
    del(q);
    return 0;
}
