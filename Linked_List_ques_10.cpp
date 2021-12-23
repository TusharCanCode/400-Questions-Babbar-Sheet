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

struct Node *buildList(int size)
{
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

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
public:
    struct Node *reverse(struct Node *head)
    {
        Node *temp = NULL;
        Node *ptr = head->next;
        while (ptr != NULL)
        {
            head->next = temp;
            temp = head;
            head = ptr;
            ptr = ptr->next;
        }
        head->next = temp;
        return head;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        first = reverse(first);
        second = reverse(second);
        Node *res = NULL;
        int carry = 0, sum = 0;
        while (first != NULL || second != NULL)
        {
            if (first == NULL)
            {
                sum = second->data + carry;
                second = second->next;
            }
            else if (second == NULL)
            {
                sum = first->data + carry;
                first = first->next;
            }
            else
            {
                sum = first->data + second->data + carry;
                first = first->next;
                second = second->next;
            }

            Node *newnode = new Node(sum % 10);
            if (res == NULL)
                res = newnode;
            else
            {
                newnode->next = res;
                res = newnode;
            }
            carry = sum / 10;
            sum = 0;
        }
        if (carry != 0)
        {
            Node *newnode = new Node(carry);
            newnode->next = res;
            res = newnode;
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}