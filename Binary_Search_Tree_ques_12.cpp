#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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
    int kthLargest(Node *root, int &K)
    {
        if (root == NULL)
            return -1;

        int right = kthLargest(root->right, K);
        if (right != -1)
            return right;

        if (--K == 0)
            return root->data;

        int left = kthLargest(root->left, K);
        if (left != -1)
            return left;

        return -1;
    }
};

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);

        int k;
        cin >> k;
        getchar();

        Solution ob;
        cout << ob.kthLargest(head, k) << endl;
    }
    return 1;
}