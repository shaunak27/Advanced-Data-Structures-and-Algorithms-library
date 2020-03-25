#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next, *prev;
}node;


typedef struct list{
        node  *front, *rear;
}list;
void linit(list*);
int lisempty(list);
void insertright(list*, int);
void printlistLR(list );
void printlistRL(list );
int length(list );
void reverse(list *l);
void insertsorted(list *,int);
void removelist(list*, int);
void freelist(list*);
void sort(list*);
int search(list l, int);
list listunion(const list, list);
int remitem(list *l);
            





