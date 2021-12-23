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
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

class Solution
{
public:
    int utility(Node *head)
    {
        if (head->next == NULL)
        {
            int val = head->data;
            head->data = (head->data + 1) % 10;
            return (val + 1) / 10;
        }

        int val = utility(head->next), data = head->data;
        head->data = (head->data + val) % 10;
        return (data + val) / 10;
    }
    Node *addOne(Node *head)
    {
        if (utility(head) == 0)
            return head;

        Node *newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < (int)s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}