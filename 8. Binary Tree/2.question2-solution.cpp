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

Node* levelOrderBuildTree()
{
    int item;
    cin >> item;

    Node* root = new Node(item);

    queue<Node*> que;
    que.push(root);

    while (!que.empty()) {
        Node* n = que.front();
        que.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1) {
            n->left = new Node(c1);
            que.push(n->left);
        }
        if (c2 != -1) {
            n->right = new Node(c2);
            que.push(n->right);
        }
    }

    return root;
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

int main()
{
    Node* root = levelOrderBuildTree();
    cout << "Tree:- \n";
    levelOrderTraversal(root);

    return 0;
}