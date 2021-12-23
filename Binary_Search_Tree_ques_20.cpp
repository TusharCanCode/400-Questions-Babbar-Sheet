#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node **tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

int getCountOfNode(Node *root, int l, int h)
{

    if (!root)
        return 0;

    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
        return 1 + getCountOfNode(root->left, l, h) +
               getCountOfNode(root->right, l, h);

    else if (root->data < l)
        return getCountOfNode(root->right, l, h);

    else
        return getCountOfNode(root->left, l, h);
}

bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root;
        Node *tmp;

        root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            insert(&root, k);
        }

        cout << isDeadEnd(root);
        cout << endl;
    }
}

bool help(Node *root, unordered_set<int>&s)
{
    if (root == NULL)
        return false;

    if (root->left == NULL && root->right == NULL)
    {
        s.insert(root->data);
        if (s.find(root->data + 1) != s.end() && s.find(root->data - 1) != s.end())
            return true;

        return false;
    }

    s.insert(root->data);
    bool left = help(root->left, s);
    bool right = help(root->right, s);

    return left || right;
}
bool isDeadEnd(Node *root)
{
    unordered_set<int> s;
    s.insert(0);
    return help(root, s);
}