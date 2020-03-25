#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
typedef struct stack{
	int a[MAX];
	int i;;
}stack;
void init(stack *s);
void push(stack *s, int no);
int pop(stack *s);
int isempty(stack *s); 
int isfull(stack *s);

