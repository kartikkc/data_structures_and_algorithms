#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;


int countNodes(struct Node *first)
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

void Insert(int position, int x)
{
    struct Node *p = first;
    struct Node *t;
    int i;

    if (position < 0 || position > countNodes(p))
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
    p->next = t;
}

void insertAtEnd(int x)
{
    struct Node *p = first;
    struct Node *t;
    int i;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    int position = countNodes(first);

    for (i = 0; i < position - 1; i++)
    {
        p = p->next;
    }

    t->next = p->next;
    p->next = t;
}

void insertAtBegin(int x)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    t->next = first;
    first = t;
}

int Delete(struct Node *p, int position)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (position < 1 || position > countNodes(p))
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

void reverse()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (first->next == NULL)
    {
        return;
    }
    struct Node *curr = first;
    struct Node *prev = NULL;

    while (curr != NULL)
    {
        struct Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    first = prev;
    Display(first);

}

void inputControl_insert()
{
    int nxt, idx;
    printf("Enter the element you want to insert : ");
    scanf("%d", &nxt);

    if (countNodes(first) <= 0)
    {
        printf("The list is empty, the insertion can be done only in front\n");
        insertAtBegin(nxt);
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
        insertAtBegin(nxt);
            break;

        case 2:
            insertAtEnd(nxt);
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

void inputControl_delete()
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
    printf("Welcome to single linked list program EXP 2 and 6\n");

    while (infinite == true)
    {
        int in;
        int len;
        printf("Enter your choice \n1 for insert\n2 for delete\n3 for display\n4 for length\n5 for reversing the list\n6 for exit\n");
        scanf("%d", &in);

        switch (in)
        {
        case 1:
            inputControl_insert();
            break;

        case 2:
            inputControl_delete();
            break;
        case 3:
            Display(first);
            break;
        case 4:
            len = countNodes(first);
            printf("Lenght is %d\n", len);
            break;
        case 5:
            reverse();
            break;
        case 6:
            infinite = false;
            break;
        default:
            break;
        }
    }

    return 0;
}