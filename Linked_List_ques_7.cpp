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
    Node *removeDuplicates(Node *head)
    {
        set<int> map;
        Node *newhead = head, *prev = head;
        while (newhead != NULL)
        {
            if (map.find(newhead->data) != map.end())
            {
                prev->next = newhead->next;
                newhead->next = NULL;
                newhead = prev->next;
            }
            else
            {
                map.insert(newhead->data);
                prev = newhead;
                newhead = newhead->next;
            }
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
        Node *result = ob.removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}