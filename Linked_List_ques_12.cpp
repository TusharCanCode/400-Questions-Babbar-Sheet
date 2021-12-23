#include <iostream>
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

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int intersectPoint(Node *first, Node *second)
{
    int length1 = 0, length2 = 0;
    Node *head1 = first, *head2 = second;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            length1++;
            head1 = head1->next;
        }

        if (head2 != NULL)
        {
            length2++;
            head2 = head2->next;
        }
    }

    while (length1 > length2)
    {
        first = first->next;
        length1--;
    }
    while (length2 > length1)
    {
        second = second->next;
        length2--;
    }

    while (first != NULL && second != NULL)
    {
        if (first == second)
            return first->data;

        first = first->next;
        second = second->next;
    }

    return -1;
}