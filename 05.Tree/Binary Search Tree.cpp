#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ================= NODE STRUCTURE =================
struct Node {
    int data;// - data value
    Node* left;// - pointer to left child
    Node* right;// - pointer to right child
};

//  CREATE NEW NODE (This function creates a new node and initializes it)
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//  INSERT INTO BST 
// Inserts value into BST following rules: left < root < right
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// INORDER TRAVERSAL (Left → Root → Right)
// For BST, this gives sorted output
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//  PREORDER TRAVERSAL (Root → Left → Right)
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//  SEARCH IN BST 
bool search(Node* root, int key) {
    if (root == NULL) return false;

    if (root->data == key) return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

//  DELETE ENTIRE TREE 
// Deletes all nodes using postorder traversal
void deleteTree(Node*& root) {
    if (root == NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
    root = NULL;
}

// ================= MAIN FUNCTION =================
int main() {
    Node* root = NULL;

    // Creating BST using insert function
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    int choice, key;

    do {
        // MENU DISPLAY
        cout << "\n===== BINARY SEARCH TREE MENU =====\n";
        cout << "1. Inorder Traversal (Sorted)\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Search Value\n";
        cout << "4. Delete Tree\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {

        // Display sorted BST values
        case 1:
            cout << "Inorder (Sorted): ";
            inorder(root);
            cout << endl;
            break;

        // Show preorder traversal
        case 2:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;

        // Search a value in BST
        case 3:
            cout << "Enter value to search: ";
            cin >> key;

            if (search(root, key))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;

        // Delete entire tree
        case 4:
            deleteTree(root);
            cout << "Tree deleted\n";
            break;

        // Exit program
        case 5:
            cout << "Exit...\n";
            break;

        // Invalid input handling
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
