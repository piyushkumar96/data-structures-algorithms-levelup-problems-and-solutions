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

    cout << endl;
}

void printPostOrder(Node* root)
{
    if (root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = buildTree();
    cout << "Tree:- " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Post Order Traversal Tree:- " << endl;
    printPostOrder(root);
    cout << endl;

    return 0;
}