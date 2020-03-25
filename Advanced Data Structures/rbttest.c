#include<stdio.h>
#include<stdlib.h>
#include "rbt.h"

int main()
{

int choice,val,data,var,fl=0;

while(1)
{          
printf("\nEnter your choice :1:Insert  2:Delete  3:Search  4:Traversal  5:Exit\n");

scanf("%d",&choice);

switch(choice)

{          case 1:printf("Enter the integer you want to add : ");

scanf("%d",&val);

insert(val);break;

case 2:printf("Enter the integer you want to delete : ");

scanf("%d",&var);

rdelete(var);break;

case 3:printf("Enter search element \n");

scanf("%d",&val);

search(val);break;

case 4:traversal(root);break;

case 5:fl=1;break;

default:printf("\nInvalid Choice\n");

}

if(fl==1)

{          break;}

}return 0;

}
