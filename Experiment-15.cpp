#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int element;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

typedef struct StackLLnode
{
    int data;
    struct StackLLnode *next;
} StackLLnode;

typedef struct Stacknode
{
    StackLLnode *top;
} Stacknode;

void enqueLL(struct node *p, int element)
{
    if (front == rear == NULL)
    {
        printf("The Queue is EMPTY!!");
    }
    else
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->element = element;
        p->next = NULL;
        if ((front == NULL) && (rear == NULL))
        {
            front = rear = p;
        }
        else
        {
            rear->next = p;
            rear = p;
            p->next = front;
        }
    }
}
void dequeueLL(struct node *p)
{
    p = front;
    if ((front == NULL) && (rear == NULL))
    {
        printf("The Queue is EMPTY!!\n");
    }
    else if (front == rear)
    {
        front = rear = NULL;
        free(p);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(p);
    }
}

void displayQueueLL(struct node p)
{
    struct node *temp;
    temp = front;
    if ((front == NULL) && (rear == NULL))
    {
        printf("The Queue is EMPTY!!\n");
    }
    else
    {
        while (temp->next != front)
        {
            printf("%d\n", temp->element);
            temp = temp->next;
        }
        printf("%d\n", temp->element);
    }
}

bool isEmpty(Stacknode *st)
{
    if (st->top == NULL)
    {
        return true;
    }

    return false;
}

int atTop(Stacknode *st)
{
    if (isEmpty(st))
    {
        printf("Stack is empty\n");
        return -1;
    }

    return st->top->data;
}

void push(Stacknode *st, int x)
{
    StackLLnode *newTop = (StackLLnode *)malloc(sizeof(StackLLnode));
    newTop->next = NULL;
    newTop->data = x;

    if (newTop == NULL)
    {
        printf("Heap is full\n");
        return;
    }

    newTop->next = st->top;
    st->top = newTop;
    return;
}

void pop(Stacknode *st)
{
    if (isEmpty(st))
    {
        printf("Already empty \n");
        return;
    }

    StackLLnode *temp = st->top;
    st->top = st->top->next;
    free(temp);
    return;
}

int main()
{
    struct node queLL;
    struct node stackLL;
    int choice;
    int choice1;
    int element;
    Stacknode st;
    st.top = NULL;
flag3:
    printf("-------------------LINKED LIST PROGRAM FOR IMPLEMENTATION OF STACK AND QUEUE-----------------");
    printf("\n");
    printf("\n");
    printf("THIS PROGRAM SHOWS THE IMPLEMENTATION OF QUEUES AND STACK USING LINKED-LISTS!!\n");
    printf("This program has an EASTER EGG XD\n");
    printf("On Which Data Stucture you want to perform operations?\n");
    printf("{\n1.Queues\n2.Stack\n}\n");
    printf("Enter your Chioice : \n> ");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:
        printf("-------------------LINKED LIST PROGRAM( Queues )-----------------");
        printf("\n{\n1-Insert the element, \n2-Delete the element, \n3-View Queue, \n00-exit\n}\nEnter your choice : \n> ");
        scanf("%d", &choice);
        switch (choice)
        {
        flag5:
        case 1:
            printf("Enter the ELEMENT you want to ENQUEUE : \n>");
            scanf("%d", &element);
            printf("%d", element);
           enqueLL(&queLL, element);
            break;

        case 2:
            dequeueLL(&queLL);
            break;

        case 3:
            displayQueueLL(queLL);
            break;

        case 4:
            goto flag3;
            break;

        case 00:
            goto flag2;
            break;

        default:
            printf("\nPlease enter a VALID option !!\n");
            break;
        }
            goto flag5;
            break;
    case 2:
    flag4:
        printf("-------------------LINKED LIST PROGRAM( Stacks )-----------------");
        printf("\n{\n1-Insert the element, \n2-Delete the element, \n00-exit\n}\nEnter your choice : \n> ");
        scanf("%d", &choice);
        printf("%d", choice);
        switch (choice)
        {
        case 1:
            printf("Enter the ELEMENT you want to ENQUEUE : \n>");
            scanf("%d", &element);
            push(&st, element);
            break;

        case 2:
            pop(&st);
            break;

        case 3:
            goto flag3;
            break;

        case 00:
            goto flag2;
            break;

        default:
            printf("\nPlease enter a VALID option !!\n");
            break;
        }
    default:
        printf("\nPlease enter a VALID option !!\n");
        break;
    }
        goto flag4;
flag2:
    return 0;
}