
#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

int key = 0;

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key);

void insert(struct Node *root, int n1, int n2, char lr)
{
    if (root == NULL)
        return;
    if (root->key == n1)
    {
        switch (lr)
        {
        case 'L':
            root->left = new Node(n2);
            break;
        case 'R':
            root->right = new Node(n2);
            break;
        }
    }
    else
    {
        insert(root->left, n1, n2, lr);
        insert(root->right, n1, n2, lr);
    }
}

int main()
{
    /* Let us construct the tree shown in above diagram */
    int t, k;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        struct Node *root = NULL;
        Node *pre = NULL;
        Node *suc = NULL;
        while (n--)
        {
            char lr;
            int n1, n2;
            cin >> n1 >> n2;
            cin >> lr;
            if (root == NULL)
            {
                root = new Node(n1);
                switch (lr)
                {
                case 'L':
                    root->left = new Node(n2);
                    break;
                case 'R':
                    root->right = new Node(n2);
                    break;
                }
            }
            else
            {
                insert(root, n1, n2, lr);
            }
        }

        cin >> key;
        findPreSuc(root, pre, suc, key);
        if (pre != NULL)
            cout << pre->key;
        else
            cout << "-1";

        if (suc != NULL)
            cout << " " << suc->key << endl;
        else
            cout << " "
                 << "-1" << endl;
    }
    return 0;
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;

    findPreSuc(root->left, pre, suc, key);
    if (root->key < key)
        pre = root;
    else if (suc == NULL && root->key > key)
    {
        suc = root;
        return;
    }

    findPreSuc(root->right, pre, suc, key);
}