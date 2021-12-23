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

void displayList(Node *head)
{
    while (head->next)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
}

Node *reverseDLLInGroups(Node *head, int k)
{
    // Write your code here.
    Node *ans = NULL, *tail = NULL;
    Node *swap = NULL, *candidate = head;
    Node *temp;
    int count = 0;
    while (head->next != NULL)
    {
        swap = head->next;
        head->next = head->prev;
        head->prev = swap;
        count++;
        if (count % k == 0)
        {
            if (ans == NULL)
                ans = head;
            temp = head->prev;
            head->prev = tail;
            if (tail != NULL)
            {
                tail->next = head;
            }
            tail = candidate;
            head = candidate = temp;
        }
        else
            head = head->prev;
    }
    swap = head->next;
    head->next = head->prev;
    head->prev = swap;

    if (ans == NULL)
        ans = head;
    temp = head->prev;
    head->prev = tail;
    if (tail != NULL)
    {
        tail->next = head;
    }
    candidate->next = NULL;
    return ans;
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
        head = reverseDLLInGroups(head, k);

        displayList(head);
        cout << endl;
    }
    return 0;
}