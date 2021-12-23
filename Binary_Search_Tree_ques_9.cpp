

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

Node *buildTree(string str)
{

    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

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

            currNode->left = new Node(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = new Node(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution
{
public:
    vector<int> inorder;
    int index = 0;
    void inorderTraversal(Node *node)
    {
        if (node == NULL)
            return;

        inorderTraversal(node->left);
        inorder.push_back(node->data);
        inorderTraversal(node->right);
    }

    void create(Node *node)
    {
        if (node == NULL)
            return;

        create(node->left);
        node->data = inorder[index++];
        create(node->right);
    }

    Node *binaryTreeToBST(Node *root)
    {
        inorderTraversal(root);
        sort(inorder.begin(), inorder.end());
        create(root);
        return root;
    }
};

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution obj;
        Node *res = obj.binaryTreeToBST(root);
        printInorder(res);
        cout << endl;
    }
    return 0;
}