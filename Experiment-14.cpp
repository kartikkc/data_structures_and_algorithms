#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Que
{
    int front;
    int rear;
    int *q;
    int size;
};

struct node
{
    int element;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void createArr(struct Que *arr, int size)
{
    arr->size = size;
    arr->front = arr->rear = 0;
    arr->q = (int *)malloc(sizeof(int) * arr->size);
}

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
        printf("The Queue is EMPTY!!");
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
    if ((front == NULL) && (rear == NULL))
    {
        printf("The Queue is EMPTY!!");
    }
    else
    {
        temp = front;
        while (rear != front)
        {
            printf("%d\n", temp->element);
            temp = temp -> next;
        }
        printf("%d\n", temp->element);
    }
}

void enqueArr(struct Que *arr, int item)
{
    if ((arr->front == 0 && arr->rear == arr->size) || (arr->rear == (arr->front - 1) % (arr->size - 1)))
    {
        printf("\nThe Queue is FULL!!\n");
    }
    else if (arr->front == -1)
    {
        arr->front = arr->rear = 0;
        arr->q[arr->rear] = item;
    }
    else if (arr->rear == arr->size - 1 && arr->front != 0)
    {
        arr->rear = 0;
        arr->q[arr->rear] = item;
    }
    else
    {
        arr->rear++;
        arr->q[arr->rear] = item;
    }
}

void dequeArr(struct Que *arr)
{
    if (arr->front == -1)
    {
        printf("\nThe Queue is EMPTY!!\n");
    }
    else if (arr->front == arr->rear)
    {
        arr->front = arr->rear = -1;
    }
    else
    {
        arr->front++;
        arr->q[arr->front] = -1;
    }
}

void displayQueueArr(struct Que *arr)
{
    if (arr->front == arr->rear)
    {
        printf("\nThe Queue is EMPTY!!\n");
    }
    else
    {
        int i = arr->front + 1;
        do
        {
            printf("%d\n", arr->q[i]);
            i = (i + 1) % arr->size;
        } while (i != (arr->rear + 1) % arr->size);
    }
}

int main()
{
    struct Que queue;
    struct node queLL;
    int size;
    int choice;
    int choice1;
    int element;
flag3:
    printf("-------------------QUEUE PROGRAM-----------------");
    printf("\n");
    printf("\n");
    printf("THIS PROGRAM SHOWS THE IMPLEMENTATION OF CIRCULAR-QUEUES USING ARRAYS AND LINKED-LISTS!!\n");
    printf("This program has an EASTER EGG XD\n");
    printf("By Which Data Stucture you want to perform operations?\n");
    printf("{\n1.ARRAYS\n2.LINKED-LISTS\n}\n");
    printf("Enter your Chioice : \n> ");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:
        printf("-------------------CIRCULAR QUEUE PROGRAM(Arrays)-----------------");
        printf("\nEnter the size of the queue : \n> ");
        scanf("%d", &size);
        createArr(&queue, size);
    flag1:
        printf("\n{\n1-Insert the element, \n2-Delete the element, \n3-View Queue, \n00-exit\n}\nEnter your choice : \n> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the ELEMENT you want to ENQUEUE : \n>");
            scanf("%d", &element);
            enqueArr(&queue, element);
            break;

        case 2:
            dequeArr(&queue);
            break;

        case 3:
            displayQueueArr(&queue);
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
        goto flag1;
        break;
    case 2:
    flag4:
        printf("-------------------CIRCULAR QUEUE PROGRAM(Linked-List)-----------------");
        printf("\n{\n1-Insert the element, \n2-Delete the element, \n3-View top, \n00-exit\n}\nEnter your choice : \n> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the ELEMENT you want to ENQUEUE : \n>");
            scanf("%d", &element);
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
        goto flag4;
        break;

    case 3:
        goto flag3;
        break;

    default:
        break;
    }

flag2:
    return 0;
}