

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node *left;
    Node *right;
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

class Solution
{
public:
    int ans = -1;
    int find(Node *root, int a, int b)
    {
        if (root == NULL)
            return -1;

        int left = find(root->left, a, b);

        if (left != -1 && (root->data == a || root->data == b))
        {
            ans = left + 1;
            return ans;
        }

        int right = find(root->right, a, b);

        if (ans != -1)
            return ans;

        else if (right != -1 && (root->data == a || root->data == b))
        {
            ans = right + 1;
            return ans;
        }

        else if (left != -1 && right != -1)
        {
            ans = left + right + 2;
            return ans;
        }

        else if (left != -1)
            return left + 1;
        else if (right != -1)
            return right + 1;
        else if (root->data == a || root->data == b)
            return 0;
        return -1;
    }
    int findDist(Node *root, int a, int b)
    {
        find(root, a, b);
        return ans;
    }
};

/* Driver program to test size function*/

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s, ch;
        getline(cin, s);

        Node *root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
    }
    return 0;
}