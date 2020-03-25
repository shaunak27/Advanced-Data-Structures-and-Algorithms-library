#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
int main() {
        int val, ch;
        while (1) {
                printf("1. Insertion\t2. Deletion\n");
                printf("3. Searching\t4. Traversal\n");
                printf("5. Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter your input:");
                                scanf("%d", &val);
                                insertion(val);
                                break;
                        case 2:
                                printf("Enter the element to delete:");
                                scanf("%d", &val);
                                deletion(val, root);
                                break;
                        case 3:
                                printf("Enter the element to search:");
                                scanf("%d", &val);
                                searching(val, &ch, root);
                                break;
                        case 4:
                                traversal(root);
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("U have entered wrong option!!\n");
                                break;
                }
                printf("\n");
        }
  }

