#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>

using namespace std;

class Trie {
private:
    struct Node {
        unordered_map<char, Node*> children;
        bool endOfWord = false;
    };
    Node *root;
public:
    Trie();

    ~Trie();

    bool insert(const string &word);

    bool search(const string &word);

    bool remove(const string &word);

private:
    bool removeRecursive(Node* node, const string& word, int index);

};

#endif
