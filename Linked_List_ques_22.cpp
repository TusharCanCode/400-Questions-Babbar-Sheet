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

int pairs(Node *start, Node *end, int x)
{
    int count = 0;
    while (start != end && start->prev != end)
    {
        if (start->data + end->data == x)
        {
            count++;
            start = start->next;
            end = end->prev;
        }
        else if (start->data + end->data < x)
            start = start->next;
        else
            end = end->prev;
    }
    return count;
}

int countTriplets(Node *head, int x)
{
    int ans = 0;
    Node *end = head;
    while ((end->next) != NULL)
        end = end->next;

    Node *start;
    while (head != NULL && head->next != end)
    {
        start = head->next;
        ans += pairs(start, end, x - (head->data));
        head = head->next;
    }
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
        cout << countTriplets(head, k);
    }
    return 0;
}