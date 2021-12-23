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

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

class Solution
{
public:
    Node *moveFirstToLast(Node *head)
    {
        if (head->next == NULL)
            return head;

        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *newnode = temp->next;
        temp->next = NULL;
        newnode->next = head;
        return newnode;
    }
};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.moveFirstToLast(head);
        print(head);
        cout << endl;
    }
    return 0;
}