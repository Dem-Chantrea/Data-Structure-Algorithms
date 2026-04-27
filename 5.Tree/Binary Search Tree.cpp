#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ================= NODE =================
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

// ================= TRAVERSALS =================
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// ================= SEARCH =================
bool search(Node* root, int key) {
    if (root == NULL) return false;

    if (root->data == key) return true;

    return search(root->left, key) ||
           search(root->right, key);
}

// ================= COLLECT FOR SORT =================
void collect(Node* root, vector<int>& arr) {
    if (root == NULL) return;

    arr.push_back(root->data);
    collect(root->left, arr);
    collect(root->right, arr);
}

void showSorted(Node* root) {
    vector<int> arr;
    collect(root, arr);

    sort(arr.begin(), arr.end());

    cout << "Sorted values: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ================= SIMPLE DELETE (replace with deepest idea) =================
void deleteTree(Node*& root) {
    if (root == NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
    root = NULL;
}

// ================= MAIN =================
int main() {
    // Manual tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int choice, key;

    do {
        cout << "\n===== BINARY TREE MENU =====\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Search Value\n";
        cout << "4. Show Sorted Values\n";
        cout << "5. Delete Tree\n";
        cout << "6. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;

        case 2:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> key;

            if (search(root, key))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;

        case 4:
            showSorted(root);
            break;

        case 5:
            deleteTree(root);
            cout << "Tree deleted\n";
            break;

        case 6:
            cout << "Exit...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}
