#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution
{
public:
    Node *startingNodeOfLoop(Node *head)
    {
        Node *fast = head, *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                fast = head;
                while (fast != slow)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        Node *res = ob.startingNodeOfLoop(head);
        if (res == NULL)
            cout << "There is no loop in the linked list";

        else
            cout << "The starting node of the loop is: " << res->data;

        return 0;
    }
}