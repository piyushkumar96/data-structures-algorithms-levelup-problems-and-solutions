#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

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

void leftViewUtil(Node* root, int level, int* max_level, vector<int>& res)
{
    if (root == NULL) {
        return;
    }

    if (level > *max_level) {
        res.push_back(root->data);
        *max_level = level;
    }

    leftViewUtil(root->left, level + 1, max_level, res);
    leftViewUtil(root->right, level + 1, max_level, res);
}

vector<int> leftView(Node* root)
{
    vector<int> res;

    if (root == NULL)
        return res;

    int max_level = 0;
    leftViewUtil(root, 1, &max_level, res);

    return res;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    cout << "Tree:- " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "The left view of tree is " << endl;
    vector<int> res = leftView(root);
    for (auto ele : res) {
        cout << ele << endl;
    }
    cout << endl;

    return 0;
}