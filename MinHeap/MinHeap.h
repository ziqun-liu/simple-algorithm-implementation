#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>

using namespace std;

/*
 * What is a min heap?
 * A min heap is a type of binary tree data structure where the root node contains the smallest element.
 * Each parent node's value is less than or equal to its children.
 * Min heaps are complete binary trees so all levels of a min heap are fully filled
 * except the last level is filled from left to right.
 * Insertion and deletion are logarithmic in complexity
 */

class MinHeap {
private:
    int size;
    int capacity;
    vector<int> heap;

public:
    MinHeap();

    MinHeap(int capacity);

    int count() const;

    void insert(int n);

    int removeMin();

    void print() const;

private:
    void bubbleUp(int child);

    void bubbleDown(int child);

    int getLeft(const int &child) const;

    int getRight(const int &child) const;

    int getParent(const int &child) const;

};


#endif
