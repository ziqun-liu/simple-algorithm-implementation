#include "MinHeap.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    MinHeap heap;

    for (int i=0; i<15; ++i) {
        cout << "Insert element " << i + 1 << endl;
        heap.insert(rand() % 100);
        heap.print();
        cout << endl;
    }


    return 0;
}
