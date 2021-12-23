#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

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
    Node *compute(Node *head)
    {
        // your code goes here
        Node *temp = head, *prev = NULL;
        Node *ptr;
        while (temp->next != NULL)
        {
            if (temp->next->data > temp->data)
            {
                if (head->data < temp->next->data)
                {
                    head = temp->next;
                    temp->next = NULL;
                    temp = head;
                }
                else
                {
                    ptr = head;
                    while (ptr->next->data >= temp->next->data)
                        ptr = ptr->next;

                    ptr->next = temp->next;
                    temp->next = NULL;
                    temp = ptr->next;
                }
            }

            else
                temp = temp->next;
        }
        return head;
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
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}