#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int item)
    {
        data = item;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree()
{
    int item;
    cin >> item;

    if (item == -1) {
        return NULL;
    }

    Node* node = new Node(item);
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty()) {
        Node* n = que.front();

        if (n == NULL) {
            que.pop();
            cout << endl;
            if (!que.empty())
                que.push(NULL);
        } else {
            cout << n->data << " ";
            que.pop();
            if (n->left) {
                que.push(n->left);
            }
            if (n->right) {
                que.push(n->right);
            }
        }
    }
}

class HBPair {
public:
    int inc;
    int exc;
};

HBPair maxSubSetSum(Node* root, int &maxSum)
{
    HBPair p;
    if (root == NULL) {
        p.inc = 0;
        p.exc = 0;
        return p;
    }

    HBPair Left = maxSubSetSum(root->left, maxSum);
    HBPair Right = maxSubSetSum(root->right, maxSum);

    p.inc = root->data + Left.exc + Right.exc;
    p.exc = max(Left.inc, Left.exc) + max(Right.inc, Right.exc);

    maxSum = max(p.inc, p.exc);

    return p;
}

int main()
{
    Node* root = buildTree();
    cout << "Tree:- " << endl;
    levelOrderTraversal(root);
    cout << endl;
    int maxSum = 0;
    maxSubSetSum(root, maxSum);
    cout << "The max sub set sum for given tree is " << maxSum<< endl;

    return 0;
}