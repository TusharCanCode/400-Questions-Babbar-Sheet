#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} * start;

void insert();

int getNthFromLast(struct Node *head, int n)
{
    int l = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }

    if (l < n)
        return -1;

    temp = head;
    l = l - n;
    while (l--)
    {
        temp = temp->next;
    }
    return temp->data;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        start = NULL;
        int n, k;
        scanf("%d", &n);
        scanf("%d", &k);
        insert(n);
        int res = getNthFromLast(start, k);
        printf("%d\n", res);
    }
    return 0;
}

void insert(int n)
{
    int value, i;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (i == 0)
        {
            start = (struct Node *)malloc(sizeof(struct Node));
            start->data = value;
            start->next = NULL;
            temp = start;
            continue;
        }
        else
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
}