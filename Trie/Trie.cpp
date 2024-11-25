#include "Trie.h"
#include <iostream>

using namespace std;

Trie::Trie() {
    root = new Node();
}

Trie::~Trie() {
    delete root;
}

bool Trie::insert(const string &word) {
    Node *curr = root;
    for (const char &c: word) {
        if (!curr->children.contains(c))
            curr->children[c] = new Node(); // Create new node
        curr = curr->children[c]; // Iterate
    }
    if (curr->endOfWord) return false;
    curr->endOfWord = true;
    return true;
}

bool Trie::search(const string &word) {
    Node *curr = root;
    for (const char&c: word) {
        if (!curr->children.contains(c))
            return false;
        curr = curr->children[c];
    }
    return curr->endOfWord;
}

bool Trie::remove(const string &word) {
    return removeRecursive(root, word, 0);
}

bool Trie::removeRecursive(Trie::Node *node, const string &word, int index) {
    if (index == word.length()) {
        if (!node->endOfWord) return false;
        node->endOfWord = false;
        return node->children.empty();
    }

    char c = word[index];
    if (!node->children.contains(c)) return false;
    bool shouldDeleteCurrentNode = removeRecursive(node->children[c], word, index + 1);

    if (shouldDeleteCurrentNode) {
        delete node->children[c];
        node->children.erase(c);
        return node->children.empty() && !node->endOfWord;
    }

    return false;
}
