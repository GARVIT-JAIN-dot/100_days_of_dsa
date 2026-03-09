/* Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged. */

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createnode(int value)
{
 struct node* newnode =(struct node*)malloc(sizeof(struct node));
 newnode->data= value;
 newnode->next= NULL;
 return newnode;
}

struct node* insertend(struct node* head,int value)
{
    struct node* newnode = createnode(value);

    if(head == NULL)
    return newnode;

    struct node* temp = head;

    while(temp->next != NULL)
        temp=temp->next;

    temp->next = newnode;

    return head;
}

struct node* mergelists(struct node* l1,struct node* l2) 
{
    struct node dummy;
    struct node* tail = &dummy;

    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) 
    {
        if(l1->data <= l2->data) 
        {
            tail->next = l1;
            l1 =l1->next;
        }
        else 
        {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    if (l1 != NULL) 
        tail->next = l1;
    else 
        tail->next = l2;

    return dummy.next;
} 

void printlist (struct node* head)
{
    struct node* temp = head;

    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main () {
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    struct node* merged = NULL;

    int n1,n2,value;

    printf("Enter the number of nodes for list1:");
    scanf("%d",&n1);
    printf("Enter sorted element for list1:");
    for (int i = 0; i < n1; i++) {
        scanf("%d",&value);
        list1 = insertend(list1,value);
    }

    printf("Enter the number of nodes for list2:");
    scanf("%d",&n2);
    printf("Enter sorted element for list1:");
    for (int i = 0; i < n2; i++) {
        scanf("%d",&value);
        list2 = insertend(list2,value);
    }

    merged = mergelists(list1,list2);

    printf("Merged sorted list:\n");
    printlist(merged);

    return 0;
}
