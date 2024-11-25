#include "Trie.h"
#include <iostream>

using namespace std;

int main() {
    Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("app");

    // Search for words
    cout << "Search 'apple': " << trie.search("apple") << endl; // 1
    cout << "Search 'app': " << trie.search("app") << endl; // 1
    cout << "Search 'appl': " << trie.search("appl") << endl; // 0

    // Remove a word
    trie.remove("app");

    // Search again after removal
    cout << "Search 'apple': " << trie.search("apple") << endl; // 1
    cout << "Search 'app': " << trie.search("app") << endl; // 0

    return 0;
}
