#include <iostream>
#include <queue>
#include <stack>

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
    int height;
    bool isBalanced;
};

HBPair isBalanced(Node* root)
{
    HBPair p;
    if (root == NULL) {
        p.height = 0;
        p.isBalanced = true;
        return p;
    }

    HBPair Left = isBalanced(root->left);
    HBPair Right = isBalanced(root->right);

    p.height = max(Left.height, Right.height) + 1;

    if (abs(Left.height - Right.height) <= 1 && Left.isBalanced && Right.isBalanced) {
        p.isBalanced = true;
        return p;
    }
    p.isBalanced = false;

    return p;
}

int main()
{
    Node* root = buildTree();
    cout << "Tree:- " << endl;
    levelOrderTraversal(root);
    cout << endl;

    HBPair p = isBalanced(root);
    if (p.isBalanced)
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is not Balanced" << endl;

    return 0;
}