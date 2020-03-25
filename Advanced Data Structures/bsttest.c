#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
int main()
{
	bst b;
	init(&b);
	int val, var, choice;
	/*
	insert(&b1,15);
	insert(&b1,6);
	insert(&b1,18);
	insert(&b1,3);
	insert(&b1,2);
	insert(&b1,4);
	insert(&b1,7);
	insert(&b1,13);
	insert(&b1,9);
	insert(&b1,17);
	insert(&b1,20);
	inordertraversal(&b1);
	printf("%d\n", minelement(&b1));
	printf("%d\n", maxelement(&b1));
	printf("%d\n", successor(&b1, 13));
	printf("%d\n", predecessor(&b1, 15));
	deletenode(&b1, 7);
	inordertraversal(&b1);*/
	while(1)
{          
printf("\nEnter your choice :1:Insert  2:Delete  3:Search  4:Inorder-Traversal 5:Preorder-Traversal "); 
printf("6:Postorder-Traversal 7:Successor 8:Predecessor 9:Exit\n");

scanf("%d",&choice);

switch(choice)

{          case 1:printf("Enter the integer you want to add : ");

scanf("%d",&val);

insert(&b, val);break;

case 2:printf("Enter the integer you want to delete : ");

scanf("%d",&var);

deletenode(&b, var);break;

case 3:printf("Enter search element \n");

scanf("%d",&val);

if(search(&b,val) == NULL)
{
	printf("Not Found\n");
}
else
	printf("Found");
break;

case 4:inordertraversal(&b);break;
case 5:preordertraversal(&b);break;
case 6:postordertraversal(&b);break;

case 7:
scanf("%d",&val);
printf("%d",successor(&b,val));
break;
case 8:
scanf("%d",&val);
printf("%d",predecessor(&b,val));
break;
case 9:
exit(0);
default:printf("\nInvalid Choice\n");

}
	
}
}
