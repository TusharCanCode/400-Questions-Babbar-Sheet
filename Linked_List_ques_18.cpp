#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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
    Node *reverse(Node *head)
    {
        if (head == NULL)
            return NULL;

        Node *temp = NULL, *ptr = head->next;
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

    bool isPalindrome(Node *head)
    {
        Node *fast = head, *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        Node *newhead = reverse(slow);
        while (newhead != NULL && head != NULL)
        {
            if (newhead->data != head->data)
                return false;
            newhead = newhead->next;
            head = head->next;
        }
        return true;
    }
};

int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}