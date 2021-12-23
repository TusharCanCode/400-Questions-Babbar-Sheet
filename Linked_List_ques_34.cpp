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
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        // code here
        Node *front = NULL;
        Node *tail = NULL;
        Node *temp = head;
        Node *ptr;

        while (temp->next != NULL)
        {
            if (temp->next->data % 2 == 0)
            {
                ptr = temp->next;
                temp->next = temp->next->next;
                ptr->next = NULL;
                if (front == NULL)
                    front = tail = ptr;
                else
                {
                    tail->next = ptr;
                    tail = ptr;
                }
            }
            else
                temp = temp->next;
        }

        if (head != NULL && head->data % 2 == 0)
        {
            temp = head;
            head = head->next;
            temp->next = front;
            front = temp;
            if (tail == NULL)
                tail = front;
        }

        if (front == NULL)
            return head;
        tail->next = head;
        return front;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}