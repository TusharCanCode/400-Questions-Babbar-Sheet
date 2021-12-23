#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

class Solution
{
public:
    Node *merge(Node *head1, Node *head2)
    {
        Node *head = NULL;
        Node *tail = NULL;
        int val;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data > head2->data)
            {
                val = head2->data;
                head2 = head2->next;
            }
            else
            {
                val = head1->data;
                head1 = head1->next;
            }

            Node *newnode = new Node(val);
            if (head == NULL)
                head = tail = newnode;
            else
            {
                tail->next = newnode;
                tail = newnode;
            }
        }

        while (head1 != NULL)
        {
            Node *newnode = new Node(head1->data);
            if (head == NULL)
                head = tail = newnode;
            else
            {
                tail->next = newnode;
                tail = newnode;
            }
            head1 = head1->next;
        }

        while (head2 != NULL)
        {
            Node *newnode = new Node(head2->data);
            if (head == NULL)
                head = tail = newnode;
            else
            {
                tail->next = newnode;
                tail = newnode;
            }
            head2 = head2->next;
        }
        return head;
    }

    Node *mergeSort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *fast = head, *slow = head;
        Node *prev = slow;
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        prev->next = NULL;
        Node *res = merge(mergeSort(head), mergeSort(slow));
        return res;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}