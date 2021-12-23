#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void print(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    print(node->left);
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

Node *Inorder(Node *root)
{
    if (root->left == NULL)
        return root;
    Inorder(root->left);
}

class Solution
{
public:
    void help(Node *root, Node **next)
    {
        if (root == NULL)
            return;

        help(root->right, next);

        Node *temp = new Node(root->data);
        temp->left = *next;
        *next = temp;

        help(root->left, next);
    }
    Node *flatten(Node *root)
    {
        Node *ans = NULL;
        help(root, &ans);
        return ans;
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        Node *ans = obj.flatten(root);
        print(ans);
        cout << endl;
    }
    return 0;
}