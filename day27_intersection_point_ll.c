/* Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection. */
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

struct node* insertatend(struct node* head,int value){
    struct node* newnode = createnode(value);

    if (head == NULL)
    return newnode;

    struct node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

int length(struct node* head) {
    int count = 0;

    while (head != NULL){
        count++;
        head= head->next;
    }

    return count;
}

struct node* intersection(struct node* l1,struct node* l2) {
    int len1 = length(l1);
    int len2 = length(l2);

    int diff;

    struct node* temp1 = l1;
    struct node* temp2 = l2;

    if(len1>len2) {
        diff = len1-len2;

        for(int i=0;i<diff;i++)
            temp1 = temp1->next;

    } else {
        diff = len2-len1;

        for(int i=0;i<diff;i++)
            temp2 = temp2->next;
        
    }

    while (temp1 != NULL && temp2 !=NULL) {
        if (temp1 == temp2) 
            return temp1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;

}

int main () {
     struct node* l1 = NULL;
    struct node* l2 = NULL;

    struct node* common = createnode(30);
    common->next = createnode(40);
    common->next->prev = common;

    l1 = insertatend(l1,10);
    l1 = insertatend(l1,20);
    l1 = insertatend(l1,30);

    struct node* temp = l1;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = common;
    common->prev = temp;

    l2 = insertatend(l2,15);
    l2 = insertatend(l2,25);

    temp = l2;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = common;
    common->prev = temp;

    struct node* result = intersection(l1,l2);

    if(result == NULL)
        printf("No Intersection\n");
    else
        printf("Intersection node value: %d\n",result->data);

    return 0;
}