#include <iostream>
using namespace std;

// Cau truc cua cay nhi phan
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Ham duyet truoc (Pre-order Traversal)
void duyetTruoc(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " "; // In gia tri cua node
    duyetTruoc(root->left);  // Duyet cay con trai
    duyetTruoc(root->right); // Duyet cay con phai
}

// Ham duyet giua (In-order Traversal)
void duyetGiua(Node* root) {
    if (root == nullptr) return;
    duyetGiua(root->left);   // Duyet cay con trai
    cout << root->data << " "; // In gia tri cua node
    duyetGiua(root->right);  // Duyet cay con phai
}

// Ham duyet sau (Post-order Traversal)
void duyetSau(Node* root) {
    if (root == nullptr) return;
    duyetSau(root->left);   // Duyet cay con trai
    duyetSau(root->right);  // Duyet cay con phai
    cout << root->data << " "; // In gia tri cua node
}

int main() {
    // Tao cay nhi phan
    Node* root = new Node(2);
    root->left = new Node(0);
    root->right = new Node(0);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(0);
    root->left->left->left = new Node(2);

    // Duyet cay theo cac thu tu khac nhau
    cout << "Duyet truoc: ";
    duyetTruoc(root);
    cout << endl;

    cout << "Duyet giua: ";
    duyetGiua(root);
    cout << endl;

    cout << "Duyet sau: ";
    duyetSau(root);
    cout << endl;

    return 0;
}

