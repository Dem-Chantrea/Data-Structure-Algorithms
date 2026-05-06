// Binary Tree Traversals
// Preorder: Root -> Left -> Right
// Inorder: Left -> Root -> Right
// Postorder: Left -> Right -> Root
// Time Complexity: O(n)


#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//Postoder Traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Create tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

	cout << "Preorder Traversal: ";
    preorder(root);
    
    cout << "\nInorder Traversal: ";
    inorder(root);

	cout << "\n Postoder Traversal:";
	postorder(root);

    return 0;
}
