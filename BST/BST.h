#ifndef BST_BST_H
#define BST_BST_H

class BST {
    struct Node {
        int val;
        Node *left;
        Node *right;

        Node() : val(0), left(nullptr), right(nullptr) {}

        Node(int n) : val(n), left(nullptr), right(nullptr) {}

        Node(int n, Node *l, Node *r) : val(n), left(l), right(r) {}
    };

    Node *root;
public:
    BST();

    ~BST();

    void insertIterative(const int &insertNum);

    bool searchIterative(const int &searchNum) const;

    void insert(const int &insertNum);

    bool search(const int &searchNum) const;

    void deleteNode(const int &deleteNum);

    bool isEmpty() const;

    void inorderTraversal() const;

    void preorderTraversal() const;

    void postorderTraversal() const;

    void destroy(Node *&p);

private:
    void insertRecursive(Node *&node, const int &insertNum);

    bool searchRecursive(Node *node, const int &searchNum) const;

    Node *minValNode(Node *root) const;

    void deleteNodeRecursive(Node *&root, const int &deleteNum);

    void inorder(Node *p) const;

    void preorder(Node *p) const;

    void postorder(Node *p) const;

};


#endif //BST_BST_H
