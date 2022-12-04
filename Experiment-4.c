#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *first = NULL;

void Insert(int position, int x)
{
    struct Node *p = first;
    struct Node *t;
    int i;

    if (position < 0 || position > count(p))
    {
        printf("INVALID position");
        return;
    }

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    for (i = 0; i < position - 1; i++)
    {
        p = p->next;
    }

    t->next = p->next;
    t->prev = p;
    p->next = t;
}

void Insert_at_end(int x)
{
    struct Node *p = first;
    struct Node *t;
    int i;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    int position = count(first);

    for (i = 0; i < position - 1; i++)
    {
        p = p->next;
    }

    t->next = p->next;
    t->prev = p;
    p->next = t;
}

void Insert_at_front(int x)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = NULL;

    t->next = first;
    first = t;
}

int count(struct Node *first)
{
    int c = 0;

    while (first != NULL)
    {
        c++;
        first = first->next;
    }

    return c;
}

void Display(struct Node *p)
{
    if (p == NULL)
    {
        printf("The list ie empty");
        return;
    }

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}



int Delete(struct Node *p, int position)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (position < 1 || position > count(p))
    {
        printf("Invalid position\n");
        return -1;
    }

    if (position == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < position - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}



void inp_insert()
{
    int nxt, idx;
    printf("Enter the element you want to insert : ");
    scanf("%d", &nxt);

    if (count(first) <= 0)
    {
        printf("The list is empty, the insertion can be done only in front\n");
        Insert_at_front(nxt);
    }
    else
    {
        int input;
        printf("Enter 1 for insertion at front\n");
        printf("Enter 2 for insertion at the end\n");
        printf("Enter 3 for insertion at position\n");

        scanf("%d", &input);
        switch (input)
        {
        case 1:
        Insert_at_front(nxt);
            break;

        case 2:
            Insert_at_end(nxt);
            break;
        case 3:
            printf("Enter the position where you want to insert : ");
            scanf("%d", &idx);
            Insert(idx,nxt);
        default:
            break;
        }
    }

    Display(first);
};

void inp_del()
{
    int ids;
    printf("Enter the position of the element you want to delete : ");
    scanf("%d", &ids);
    Delete(first, ids + 1);
    Display(first);
}

int main()
{
    bool infinite = true;
    printf("Welcome to doubble linked list program EXP 4\n");

    while (infinite == true)
    {
        int in;
        int len;
        printf("Enter your choice \n1 for insert\n2 for delete\n3 for display\n4 for exit\n");
        scanf("%d", &in);

        switch (in)
        {
        case 1:
            inp_insert();
            break;

        case 2:
            inp_del();
            break;
        case 3:
            Display(first);
            break;
        case 4:
            infinite = false;
            break;
        default:
            break;
        }
    }

    return 0;
}