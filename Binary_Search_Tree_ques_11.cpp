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
    void inorder(Node *root, vector<int> &x)
    {
        if (root == NULL)
            return;

        inorder(root->left, x);
        x.push_back(root->data);
        inorder(root->right, x);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> a, b, ans;
        inorder(root1, a);
        inorder(root2, b);

        int i, j;
        for (i = 0, j = 0; i < a.size() && j < b.size();)
        {
            if (a[i] < b[j])
            {
                ans.push_back(a[i]);
                i++;
            }
            else
            {
                ans.push_back(b[j]);
                j++;
            }
        }

        while (i < a.size())
        {
            ans.push_back(a[i]);
            i++;
        }

        while (j < b.size())
        {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
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
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);

        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    return 0;
}