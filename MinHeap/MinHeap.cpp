#include "MinHeap.h"
#include <iostream>
#include <stdexcept>

using namespace std;

MinHeap::MinHeap() : size{0}, capacity{1} {}

MinHeap::MinHeap(int cap) : size{0}, capacity{cap} {
    if (cap == 0)
        heap.resize(capacity);
}

int MinHeap::count() const {
    return size;
}

void MinHeap::insert(int n) {
    ++size;
    if (size == capacity) {
        capacity += (size + 1) / 2;
        heap.resize(capacity);
    }
    heap[size] = n;
    bubbleUp(size - 1);
}

int MinHeap::removeMin() {
    if (size <= 0)
        throw runtime_error("Heap is empty!");
    int root = heap[0];
    heap[0] = heap[size - 1];
    --size;
    bubbleDown(0);
    return root;
}

void MinHeap::print() const {
    int level = 0;
    int numberOfElements = 1;
    for (int i=0; i<size; ++i) {
        if (i == numberOfElements) {
            numberOfElements += (1 << level); // pow(2, level)
            ++level;
            cout << endl;
        }
        cout << heap[i] << " ";
    }
    cout << endl;
}

void MinHeap::bubbleUp(int child) {
    while (child > 0) {
        int parent = getParent(child);
        if (heap[child] < heap[parent]) {
            swap(heap[child], heap[parent]);
            child = parent;
        } else break;
    }
}

void MinHeap::bubbleDown(int child) {
    int left = getLeft(child);
    int right = getRight(child);
    int smallest = child;
    if (heap[left] < heap[smallest] && left < size)
        smallest = left;
    if (heap[right] < heap[smallest] && right < size)
        smallest = right;
    if (smallest != child) {
        swap(heap[child], heap[smallest]);
        bubbleDown(smallest);
    }
}

int MinHeap::getLeft(const int &child) const {
    return 2 * child + 1;
}

int MinHeap::getRight(const int &child) const {
    return 2 * child + 2;
}

int MinHeap::getParent(const int &child) const {
    return (child - 1) / 2;
}
