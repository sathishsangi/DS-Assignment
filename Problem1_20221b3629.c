#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10
 
/* Function declarations */
void create();
void insert();
void deletion();
void search();
void display();
 
/* Global variables */
int b[MAX];
int n = 0;  // To keep track of the number of elements in the list
 
void main() {
    int ch;
    char g = 'y';
 
    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display \n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
 
        /* The following switch will call the appropriate choice provided by the user */
        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }
 
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g);
 
    } while(g == 'y' || g == 'Y');
}
 
void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
 
    if(n > MAX) {
        printf("Number of nodes exceeds the maximum limit of %d.\n", MAX);
        n = 0;
        return;
    }
 
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}
 
void deletion() {
    int pos;
 
    if(n == 0) {
        printf("\nList is empty.\n");
        return;
    }
 
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);
 
    if(pos >= n || pos < 0) {
        printf("\nInvalid position.\n");
        return;
    }
 
    for(int i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;
 
    printf("\nThe elements after deletion are: ");
    display();
}
 
void search() {
    int e, found = 0;
 
    if(n == 0) {
        printf("\nList is empty.\n");
        return;
    }
 
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);
 
    for(int i = 0; i < n; i++) {
        if(b[i] == e) {
            printf("Value is at position %d\n", i);
            found = 1;
            break;
        }
    }
 
    if(!found) {
        printf("Value %d is not in the list.\n", e);
    }
}
 
void insert() {
    int pos, p;
 
    if(n == MAX) {
        printf("\nList is full.\n");
        return;
    }
 
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);
 
    if(pos > n || pos < 0) {
        printf("\nInvalid position.\n");
        return;
    }
 
    for(int i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }
 
    printf("\nEnter the element to insert: ");
    scanf("%d", &p);
 
    b[pos] = p;
    n++;
 
    printf("\nThe list after insertion is: ");
    display();
}
 
void display() {
    if(n == 0) {
        printf("\nList is empty.\n");
        return;
    }
 
    printf("\nThe elements of the list ADT are: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
