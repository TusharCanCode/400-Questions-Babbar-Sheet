#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str)
{

    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = newNode(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {

            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    vector<int> res;
    vector<int> boundary(Node *root)
    {
        if (root->left == NULL && root->right == NULL)
            return {root->data};

        int flag_left = 0;
        stack<Node *> store;
        store.push(root);
        Node *ptr;
        if (root->left == NULL)
        {
            res.push_back(root->data);
            flag_left = 1;
        }

        while (!flag_left)
        {
            ptr = store.top();
            res.push_back(ptr->data);
            if (ptr->left)
                store.push(ptr->left);
            else if (ptr->right)
            {
                store.pop();
                store.push(ptr->right);
            }
            else
            {
                res.pop_back();
                flag_left = 1;
            }
        }

        while (!store.empty())
        {
            ptr = store.top();
            if (ptr->left == NULL && ptr->right == NULL)
            {
                res.push_back(ptr->data);
                flag_left = 1;
                store.pop();
            }

            else if (ptr->left && !flag_left)
                store.push(ptr->left);

            else if (ptr->right)
            {
                store.pop();
                flag_left = 0;
                store.push(ptr->right);
            }

            else
                store.pop();
        }

        if (root->right == NULL)
            return res;

        store.push(root->right);

        while (true)
        {
            ptr = store.top();
            if (ptr->right)
                store.push(ptr->right);
            else if (ptr->left)
                store.push(ptr->left);
            else
            {
                store.pop();
                break;
            }
        }

        while (!store.empty())
        {
            ptr = store.top();
            res.push_back(ptr->data);
            store.pop();
        }
        return res;
    }
};

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundary(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}