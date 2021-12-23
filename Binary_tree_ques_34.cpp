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

void preorder(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

string help(Node *root, vector<Node *> &res, unordered_map<string, int> &s)
{
    if (root == NULL)
        return "N";
    string ans;

    string left = help(root->left, res, s);
    string right = help(root->right, res, s);
    ans = left;
    ans.push_back(root->data + '0');
    ans = ans + right;
    if (s.find(ans) != s.end())
    {
        if (s[ans] == 1)
            res.push_back(root);

        s[ans]++;
    }
    else
        s.insert({ans, 1});

    return ans;
}

vector<Node *> printAllDups(Node *root)
{
    vector<Node *> ans;
    unordered_map<string, int> s;
    help(root, ans, s);
    return ans;
}

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        vector<Node *> res = printAllDups(root);

        for (int i = 0; i < res.size(); i++)
        {
            preorder(res[i]);
            cout << endl;
        }
    }
    return 0;
}