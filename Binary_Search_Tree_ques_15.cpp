#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

float findMedian(struct Node *node);

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

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        cout << findMedian(root) << endl;
    }
    return 0;
}

int findelements(Node *root)
{
    if (root == NULL)
        return 0;

    return findelements(root->left) + findelements(root->right) + 1;
}

float help(Node *root, bool flag, int &k)
{
    if (root == NULL)
        return 0;

    float res = help(root->left, flag, k);

    if (!flag && k == 0)
        res += root->data;
    else if (flag && (k == 0 || k == 1))
        res += root->data;

    k--;
    res += help(root->right, flag, k);
    return res;
}

float findMedian(struct Node *root)
{

    int n = findelements(root);
    int k = n / 2;
    if (n % 2 != 0)
        return help(root, false, k);

    return help(root, true, k) / 2.0;
}