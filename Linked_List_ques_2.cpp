#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        node *ans = NULL;
        node *join1 = head;
        node *join2 = NULL;
        node *temp = NULL;
        node *ptr = head;
        int iteration = 0;
        while (ptr->next != NULL)
        {
            iteration++;
            ptr = ptr->next;
            head->next = temp;
            temp = head;
            head = ptr;

            if (iteration % k == 0)
            {
                if (join2 != NULL)
                {
                    join1->next = temp;
                    join1 = join2;
                }
                else
                {
                    ans = temp;
                }
                join2 = head;
                temp = NULL;
            }
        }
        ptr->next = temp;
        if (join2 != NULL)
        {
            join1->next = head;
        }

        return ans == NULL ? head : ans;
    }
};

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return (0);
}