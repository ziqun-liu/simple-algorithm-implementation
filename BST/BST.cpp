#include <iostream>
#include "BST.h"

using namespace std;

BST::BST() {
    root = nullptr;
}

void BST::insertIterative(const int &insertNum) {
    Node *curr, *trailCurr, *newNode = new Node(insertNum);
    if (!root) root = newNode;
    else {
        curr = root;
        while (curr != nullptr) {
            trailCurr = curr;
            if (insertNum == curr->val) return;
            else if (insertNum < curr->val) curr = curr->left;
            else curr = curr->right;
        } // end while loop
        // final comparison
        if (insertNum < trailCurr->val)
            trailCurr->left = newNode;
        else
            trailCurr->right = newNode;
    }
    delete newNode;
}

void BST::insert(const int &insertNum) {
    insertRecursive(root, insertNum);
}

void BST::insertRecursive(Node *&root, const int &insertNum) {
    if (!root) root = new Node(insertNum);
    else if (insertNum < root->val)
        insertRecursive(root->left, insertNum);
    else if (insertNum > root->val)
        insertRecursive(root->right, insertNum);
    else return;
}

bool BST::searchIterative(const int &searchNum) const {
    // Iterative implementation
    Node *curr;
    bool found = false;
    if (root == nullptr) return found;
    curr = root;
    while (curr != nullptr && !found) {
        if (searchNum == curr->val)
            found = true;
        else if (searchNum < curr->val)
            curr = curr->left;
        else curr = curr->right;
    }
    return found;
}

bool BST::search(const int &searchNum) const {
    return searchRecursive(root, searchNum);
}

bool BST::searchRecursive(Node *root, const int &searchNum) const {
    if (!root) return false;
    else if (searchNum == root->val) return true;
    else if (searchNum < root->val)
        return searchRecursive(root->left, searchNum);
    else
        return searchRecursive(root->right, searchNum);
}

void BST::deleteNode(const int &deleteNum) {
    deleteNodeRecursive(root, deleteNum);
}

void BST::deleteNodeRecursive(Node *&root, const int &deleteNum) {
    Node* tmp;
    if (!root) return;
    else if (deleteNum < root->val)
        deleteNodeRecursive(root->left, deleteNum);
    else if (deleteNum > root->val)
        deleteNodeRecursive(root->right, deleteNum);
    else { // root->val == deleteNum
        if (!root->left) { // only has right subtree
            tmp = root;
            root = root->right;
            delete tmp;
        } else if (!root->right) { // only has left subtree
            tmp = root;
            root = root->left;
            delete tmp;
        } else {
            tmp = minValNode(root->right);
            root->val = tmp->val; // copy val, don't worry about left and right
            deleteNodeRecursive(root->right, tmp->val); // Since the value is copied to current root, need to delete
        }
    }
}

Node* BST::minValNode(Node *root) const {
    while (root->left)
        root = root->left;
    return root;
}

bool BST::isEmpty() const {
    return (root == nullptr);
}

void BST::preorderTraversal() const {
    preorder(root);
}

void BST::inorderTraversal() const {
    inorder(root);
}

void BST::postorderTraversal() const {
    postorder(root);
}

void BST::preorder(Node *p) const {
    if (p != nullptr) {
        cout << p->val << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void BST::inorder(Node *p) const {
    if (p != nullptr) {
        inorder(p->left);
        cout << p->val << " ";
        inorder(p->right);
    }
}

void BST::postorder(Node *p) const {
    if (p != nullptr) {
        postorder(p->left);
        postorder(p->right);
        cout << p->val << " ";
    }
}

void BST::destroy(Node *&p) {
    if (p != nullptr) {
        destroy(p->left);
        destroy(p->right);
        delete p;
        p = nullptr;
    }
}

BST::~BST() {
    destroy(root);
}
