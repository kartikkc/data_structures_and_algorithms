#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;

} *first = NULL;

int count_Node(struct Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int c = 1;
    head = head->next;

    while (head != NULL && head != first)
    {
        c++;
        head = head->next;
    }

    return c;
}

int Delete(struct Node *p, int position)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (position < 1 || position > count_Node(p))
    {
        printf("Invalid position\n");
        return -1;
    }

    if (position == 1)
    {
        q = first;
        x = first->data;

        struct Node *temp = first;
        while (temp->next != first)
        {
            temp = temp->next;
        }

        temp->next = first->next;
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


void insert_node(int position, int x)
{
    struct Node *p = first;
    struct Node *t;
    int i;

    if (position < 0 || position > count_Node(p))
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
void display_Nodes(struct Node *p)
{
    if (p == NULL)
    {
        printf("The list ie empty");
        return;
    }

    printf("%d ", p->data);

    while (p->next != first)
    {
        p = p->next;
        printf("%d ", p->data);
    }

    printf("\n");
}

void insert_node_at_end(int x)
{
    struct Node *p = first;
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    while (p->next != first)
    {
        p = p->next;
    }

    p->next = t;
    t->next = first;

}

void insert_node_at_front(int x)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = first;

    if (first == NULL)
    {
        t->next = t;
    }
    else
    {
        // updating next of last node
        struct Node *temp = first;
        while (temp->next != first)
        {
            temp = temp->next;
        }
        temp->next = t;
    }

    first = t;
}


void inp_insert_node()
{
    int nxt, idx;
    printf("Enter the element you want to insert_node : ");
    scanf("%d", &nxt);

    if (count_Node(first) <= 0)
    {
        printf("The list is empty, the insert_nodeion can be done only in front\n");
        insert_node_at_front(nxt);
    }
    else
    {
        int input;
        printf("Enter 1 for insert_nodeion at front\n");
        printf("Enter 2 for insert_nodeion at the end\n");
        printf("Enter 3 for insert_nodeion at position\n");

        scanf("%d", &input);
        switch (input)
        {
        case 1:
            insert_node_at_front(nxt);
            break;

        case 2:
            insert_node_at_end(nxt);
            break;
        case 3:
            printf("Enter the position where you want to insert_node : ");
            scanf("%d", &idx);
            insert_node(idx, nxt);
        default:
            break;
        }
    }

    display_Nodes(first);
};

void inp_del()
{
    int ids;
    printf("Enter the position of the element you want to delete : ");
    scanf("%d", &ids);
    Delete(first, ids + 1);
    display_Nodes(first);
}

int main()
{
    bool infinite = true;
    printf("Welcome to circular single linked list program EXP 3\n");


    while (infinite == true)
    {
        int in;
        int len;
        printf("Enter your choice \n1 for insert_node\n2 for delete\n3 for display_Nodes\n4 for exit\n");
        scanf("%d", &in);

        switch (in)
        {
        case 1:
            inp_insert_node();
            break;

        case 2:
            inp_del();
            break;
        case 3:
            display_Nodes(first);
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