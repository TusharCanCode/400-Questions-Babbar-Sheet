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

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

class Solution
{
public:
    int index = -1;
    Node *helper(int in[], int pre[], int start, int end, int n)
    {
        if (start > end || start < 0 || end >= n || index >= n)
            return NULL;

        int i;
        index++;
        for (i = start; i <= end; i++)
        {
            if (in[i] == pre[index])
                break;
        }

        Node *node = new Node(pre[index]);
        node->left = helper(in, pre, start, i - 1, n);
        node->right = helper(in, pre, i + 1, end, n);
        return node;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        Node *head = helper(in, pre, 0, n - 1, n);
        return head;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}