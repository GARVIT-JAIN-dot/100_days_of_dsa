/* Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer. */

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createnode(int value)
{
   struct node* newnode = (struct node*)malloc(sizeof(struct node));
   if(newnode == NULL)
   {
    printf("Memory allocation failed!\n");
    exit(1);
   }

   newnode->data = value;
   newnode->prev = NULL;
   newnode->next = NULL;
}

struct node* insertatend(struct node* head,int value)
{
    struct node* newnode = createnode(value);

    if(head == NULL)
        return newnode;

    struct node* temp = head;

    while (temp->next != NULL)
    temp = temp->next;
    
    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

void printlist(struct node* head)
{
    struct node* temp = head;
    printf("Elements of doubly linked list are:");
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp= temp->next;
    }

}

struct node* head = NULL;

int main () {
    int n,value;
    printf("Enter the number of node for doubly linked list:");
    scanf("%d",&n);

    printf("Enter the element for doubly linked list:");
    for(int i = 0;i < n;i++) {
        scanf("%d",&value);
        head = insertatend(head,value);
    }

    printlist(head);

    return 0;

}