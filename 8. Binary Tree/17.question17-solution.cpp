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

bool equal(Node* root1, Node* root2)
{
    if (root1 == root2)
        return true;

    return ((root1 && root2) && (root1->data == root2->data) && ((equal(root1->left, root2->left) && equal(root1->right, root2->right)) || (equal(root1->left, root2->right) && equal(root1->right, root2->left))));
}

int main()
{
    Node* root1 = new Node(6);
    root1->left = new Node(3);
    root1->right = new Node(8);
    root1->left->left = new Node(1);
    root1->left->right = new Node(7);

    root1->right->left = new Node(4);
    root1->right->right = new Node(2);
    root1->right->left->left = new Node(7);
    root1->right->left->right = new Node(1);

    root1->right->right->right = new Node(3);

    Node* root2 = new Node(6);
    root2->left = new Node(8);
    root2->right = new Node(3);

    root2->left->left = new Node(2);
    root2->left->right = new Node(4);
    root2->left->right->left = new Node(1);
    root2->left->right->right = new Node(7);

    root2->left->left->left = new Node(3);

    root2->right->left = new Node(7);
    root2->right->right = new Node(1);

    cout << "Tree1:- " << endl;
    levelOrderTraversal(root1);
    cout << endl;

    cout << "Tree2:- " << endl;
    levelOrderTraversal(root2);
    cout << endl;

    bool res = equal(root1, root2);
    if (res) {
        cout << "Tree are inter convertible by sibling swapping" << endl;
    } else {
        cout << "Tree are not inter convertible by sibling swapping" << endl;
    }
    cout << endl;

    return 0;
}