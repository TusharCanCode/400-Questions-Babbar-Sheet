#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Node
    {
        char val;
        Node *next;
        Node() {}
        Node(char character)
        {
            val = character;
            next = NULL;
        }
    };

    bool isPresent(Node *head, char value)
    {
        while (head != NULL)
        {
            if (head->val == value)
                return true;

            head = head->next;
        }

        return false;
    }

    void create(Node **head, char value)
    {
        Node *newnode = new Node(value);
        if (*head == NULL)
        {
            *head = newnode;
            return;
        }

        newnode->next = *head;
        *head = newnode;
    }

    bool checker(Node **head, char value)
    {
        Node *temp = *head;
        if (temp == NULL)
        {
            Node *newnode = new Node(value);
            *head = newnode;
            return false;
        }

        else if (temp->val == value)
        {
            *head = temp->next;
            temp->next = NULL;
            delete (temp);
            return true;
        }

        while (temp->next != NULL)
        {
            if (temp->next->val == value)
            {
                Node *del = temp->next;
                temp->next = temp->next->next;
                del->next = NULL;
                delete (del);
                return true;
            }
            temp = temp->next;
        }

        Node *newnode = new Node(value);
        temp->next = newnode;
        return false;
    }

    string FirstNonRepeating(string A)
    {
        string ans;
        Node *repeating = NULL;
        Node *nonRepeating = NULL;
        for (char i : A)
        {
            if (isPresent(repeating, i))
            {
                nonRepeating == NULL ? ans.push_back('#') : ans.push_back(nonRepeating->val);
            }

            else
            {
                if (checker(&nonRepeating, i))
                    create(&repeating, i);

                nonRepeating == NULL ? ans.push_back('#') : ans.push_back(nonRepeating->val);
            }
        }
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}