#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *newNode(int data)
{
    Node *temp = new Node(data);

    return temp;
}

bool findPair(Node *head, int k)
{
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    while (tail != head && tail->next != head)
    {
        if (tail->data + head->data == k)
            return true;
        else if (tail->data + head->data > k)
            tail = tail->prev;
        else
            head = head->next;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *head = NULL, *tail = NULL;
        int x;
        cin >> x;
        head = newNode(x);
        tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            Node *temp = newNode(x);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        int k;
        cin >> k;
        cout << findPair(head, k);
    }
    return 0;
}