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

Node* createMinHeightBST(vector<int> v, int start, int end)
{

    if (start > end)
        return NULL;
    int mid = (start + end) / 2;

    Node* root = new Node(v[mid]);

    root->left = createMinHeightBST(v, start, mid - 1);
    root->right = createMinHeightBST(v, mid + 1, end);

    return root;
}

int main()
{
    vector<int> v { 1, 2, 3, 4, 5, 6, 7 };

    int k = 16;
    Node* root = createMinHeightBST(v, 0, v.size() - 1);
    cout << "Tree:- " << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}