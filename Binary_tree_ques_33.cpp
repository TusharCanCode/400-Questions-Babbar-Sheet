#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        int k, node;
        scanf("%d ", &k);
        scanf("%d ", &node);
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        cout << kthAncestor(root, k, node) << endl;
    }
    return 0;
}

int help(Node *root, int k, int node, int &ans)
{
    if (root == NULL)
        return -1;

    if (root->data == node)
        return 1;

    int left = help(root->left, k, node, ans);
    if (left != -1)
    {
        if (left == k)
            ans = root->data;
        return left + 1;
    }

    int right = help(root->right, k, node, ans);
    if (right != -1)
    {
        if (right == k)
            ans = root->data;
        return right + 1;
    }

    return -1;
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    help(root, k, node, ans);
    return ans;
}