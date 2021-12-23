#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

class Solution
{
public:
    // Iterative Solution:
    struct Node *reverseList(struct Node *head)
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

    // Recursive Solution:
    // Node *ans = NULL;
    // struct Node *reverse(struct Node *head)
    // {
    //     if (head->next == NULL || head == NULL)
    //     {
    //         ans = head;
    //         return head;
    //     }

    //     reverse(head->next)->next = head;
    //     return head;
    // }

    // struct Node *reverseList(struct Node *head)
    // {
    //     reverse(head)->next = NULL;
    //     return ans;
    // }
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int T, n, l, firstdata;
    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;

        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;

        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob.reverseList(head);

        printList(head);
        cout << endl;
    }
    return 0;
}