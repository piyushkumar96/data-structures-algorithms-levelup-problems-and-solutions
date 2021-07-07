#include <climits>
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

int closestNodeToK(Node* root, int k)
{
    if (root == NULL) {
        return -1;
    }

    Node* temp = root;

    int min_diff = INT_MAX;
    int num = -1;

    while (temp != NULL) {
        int curr_diff = abs(temp->data - k);

        if (curr_diff == 0) {
            return temp->data;
        }
        if (min_diff > curr_diff) {
            min_diff = curr_diff;
            num = temp->data;
        }

        if (temp->data > k) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    return num;
}

int main()
{
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    cout << "Tree:- " << endl;
    levelOrderTraversal(root);
    cout << endl;

    int k = 16;
    int res = closestNodeToK(root, k);
    cout << "The closest node to " << k << " is " << res << endl;

    return 0;
}