#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *pre = NULL;

void deleteNode(Node **head, int data);
void reverse(Node **head);

void push(struct Node **head_ref, int data)
{
    struct Node *curr = new Node(data);

    curr->next = curr;

    if (*head_ref == NULL)
    {
        *head_ref = curr;
        curr->next = *head_ref;
        pre = *head_ref;
    }
    else
    {
        curr->next = *head_ref;
        pre->next = curr;
        pre = pre->next;
    }
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    else
        cout << "empty" << endl;

    printf("\n");
}

int main()
{
    int t, a, delnode;
    cin >> t;
    while (t--)
    {
        pre = NULL;
        Node *head = NULL;

        int n;
        cin >> n;
        while (n--)
        {
            cin >> a;
            push(&head, a);
        }

        cin >> delnode;

        deleteNode(&head, delnode);

        reverse(&head);

        printList(head);
    }
    return 0;
}

void deleteNode(struct Node **head, int key)
{
    Node *temp = *head;
    do
    {
        if (temp->next->data == key)
        {
            Node *ptr = temp->next;
            temp->next = temp->next->next;
            ptr->next = NULL;

            if (ptr == *head)
                *head = temp->next;

            return;
        }
        temp = temp->next;

    } while (temp != *head);
}

void reverse(struct Node **head)
{
    Node *temp = *head, *fast = temp->next;
    Node *ptr = fast;
    while (fast != *head)
    {
        fast = fast->next;
        ptr->next = temp;
        temp = ptr;
        ptr = fast;
    }
    ptr->next = temp;
    *head = temp;
}