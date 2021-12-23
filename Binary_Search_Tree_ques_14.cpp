

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

class Solution
{
public:
    unordered_set<int> s;
    void createSet(Node *root)
    {
        if (root == NULL)
            return;

        createSet(root->left);
        s.insert(root->data);
        createSet(root->right);
    }

    int count(Node *root, int x)
    {
        if (root == NULL)
            return 0;

        int ans = count(root->left, x);
        if (s.find(x - (root->data)) != s.end())
            ans++;

        ans += count(root->right, x);
        return ans;
    }
    int countPairs(Node *root1, Node *root2, int x)
    {
        createSet(root1);
        return count(root2, x);
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node *root1 = buildTree(tree1);
        Node *root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}