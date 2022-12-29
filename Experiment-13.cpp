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

void createArr(struct Que *arr, int size)
{
    arr->size = size;
    arr->front = arr->rear = -1;
    arr->q = (int *)malloc(sizeof(int) * size);
}

void enque(struct Que *arr, int item)
{
    if (arr->rear == arr->size-1)
    {
        printf("\nThe Queue is FULL!!\n");
    }
    else
    {
        arr->rear++;
        arr->q[arr->rear] = item;
    }
}

void deque(struct Que *arr)
{
    if (arr->front==arr->rear)
    {
        printf("\nThe Queue is EMPTY!!\n");
    }
    else
    {
        arr->front++;
        arr->q[arr->front] = -1;
        if(arr->front==arr->rear){
            arr->front= 0;
            arr->rear = 0;
        }
    }
}

void displayQueue(struct Que *arr)
{
    if (arr->front==arr->rear)
    {
        printf("\nThe Queue is EMPTY!!\n");
    }
    else
    {
        for (int i = 0; i < arr->rear+1; i++)
        {
            printf("%d\n", arr->q[i]);
        }
    }
}


int main()
{
    struct Que queue;
    int size;
    int choice;
    int element;
flag3:
    printf("-------------------QUEUE PROGRAM-----------------");
    printf("\n");
    printf("\n");
    printf("THIS PROGRAM SHOWS THE IMPLEMENTATION OF QUEUES USING ARRAYS!!\n");
    printf("This program has an EASTER EGG XD");
    printf("\nEnter the size of the queue : \n> ");
    scanf("%d", &size);
    createArr(&queue, size);
flag1:
    printf("\n{\n1-Insert the element, \n2-Delete the element, \n3-View top, \n00-exit\n}\nEnter your choice : \n> ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the ELEMENT you want to ENQUEUE : \n>");
        scanf("%d", &element);
        enque(&queue,element);
        break;

    case 2:
        deque(&queue);
        break;

    case 3:
        displayQueue(&queue);
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
flag2:
    return 0;
}
