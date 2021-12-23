#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;

    Node(char x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct Node *buildTree(string str)
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
    unordered_set<string> s;
    int count = 0;

    string help(Node *root)
    {
        if (root == NULL)
            return "N";

        string ans;
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back('N');
            ans.push_back(root->data + '0');
            ans.push_back('N');
            return ans;
        }

        string left = help(root->left);
        string right = help(root->right);
        ans = left;
        ans.push_back(root->data + '0');
        ans = ans + right;

        if (s.find(ans) != s.end())
            count++;
        else
            s.insert(ans);

        return ans;
    }

    int dupSub(Node *root)
    {
        help(root);
        return count;
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string treeString;
        getline(cin >> ws, treeString);
        struct Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.dupSub(root) << "\n";
    }
    return 0;
}