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

void printNodesInVerticalOrder(Node* root)
{
    unordered_map<int, vector<int>> mp;

    queue<pair<Node*, int>> q;

    int max = INT_MIN, min = INT_MAX;

    q.push({ root, 0 });
    while (!q.empty()) {
        pair<Node*, int> pa = q.front();
        q.pop();
        int hd = pa.second;
        mp[hd].push_back(pa.first->data);

        if (hd > max)
            max = hd;
        if (hd < min)
            min = hd;

        if (pa.first->left)
            q.push({ pa.first->left, hd - 1 });
        if (pa.first->right)
            q.push({ pa.first->right, hd + 1 });
    }

    for (auto i = min; i <= max; i++) {
        for (auto j = 0; j < mp[i].size(); j++)
            cout << mp[i][j] << " ";
        cout << endl;
    }
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

    cout << "The vertical order tree is " << endl;
    printNodesInVerticalOrder(root);
    cout << endl;

    return 0;
}