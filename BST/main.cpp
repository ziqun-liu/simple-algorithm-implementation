#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
using namespace std;

int main()
{
    int num;
    bool ans;

    BST Btree;
    Btree.insert(10);
    Btree.insert(2);
    Btree.insert(4);
    Btree.insert(100);
    Btree.insert(28);

    cout << "inorder" << endl;
    Btree.inorderTraversal();
    cout << endl;

    cout << "preorder" << endl;
    Btree.preorderTraversal();
    cout << endl;

    cout << "postorder" << endl;
    Btree.postorderTraversal();
    cout << endl;

    cout << "enter an number to search: ";
    cin >> num;
    ans=Btree.search(num);
    if(ans){
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
