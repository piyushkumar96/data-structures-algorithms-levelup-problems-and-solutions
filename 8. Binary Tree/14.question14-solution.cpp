#include <algorithm>
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

void printNodeAtLevelK(Node* node, int level, vector<int>& res)
{
    if (node == NULL) {
        return;
    }
    if (level == 0) {
        res.push_back(node->data);
        return;
    }

    printNodeAtLevelK(node->left, level - 1, res);
    printNodeAtLevelK(node->right, level - 1, res);
}

int printNodesAtDistanceKUtil(Node* node, Node* target, int k, vector<int>& res)
{
    if (node == NULL)
        return -1;

    if (node == target) {
        printNodeAtLevelK(node, k, res);
        return 0;
    }

    int DL = printNodesAtDistanceKUtil(node->left, target, k, res);
    if (DL != -1) {
        if (DL + 1 == k) {
            res.push_back(node->data);
        } else {
            printNodeAtLevelK(node->right, k - DL - 2, res);
        }

        return DL + 1;
    }

    int DR = printNodesAtDistanceKUtil(node->right, target, k, res);
    if (DR != -1) {
        if (DR + 1 == k) {
            res.push_back(node->data);
        } else {
            printNodeAtLevelK(node->left, k - DR - 2, res);
        }

        return DR + 1;
    }

    return -1;
}

vector<int> printNodesAtDistanceK(Node* root, Node* target, int k)
{
    vector<int> res;
    if (root == NULL || target == NULL)
        return res;

    printNodesAtDistanceKUtil(root, target, k, res);

    sort(res.begin(), res.end());
    return res;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->left->right->right->left = new Node(9);
    root->left->right->right->right = new Node(10);

    root->right->right = new Node(6);

    Node* target = root->left->right;
    int k = 2;

    cout << "Tree:- " << endl;
    levelOrderTraversal(root);
    cout << endl;

    vector<int> res = printNodesAtDistanceK(root, target, k);
    cout << "The nodes at distance " << k << " from target node " << target->data << " are" << endl;
    for (auto ele : res) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}