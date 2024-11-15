#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Vector {
    friend ostream &operator<<(ostream &, const Vector &);

private:
    int size;
    int capacity;
    T *elements;

    void resize(int newCapacity);

public:
    Vector();
    ~Vector();

    void push_back(const T &element);

    T &operator[](int index);
    T &operator[](int index) const;

    void remove(int index);

    bool isEmpty() const;

    int getSize() const;

    int getCapacity() const;

    T *getElements() const;
};

// Implementation of methods within the header file

template<typename T>
Vector<T>::Vector() : size(0), capacity(10) {
    elements = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] elements;
}

template<typename T>
bool Vector<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
void Vector<T>::resize(int newCapacity) {
    if (newCapacity > capacity) {
        T *newElements = new T[newCapacity];
        copy(elements, elements + size, newElements);
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }
}

template<typename T>
void Vector<T>::push_back(const T &element) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    elements[size++] = element;
}

template<typename T>
T &Vector<T>::operator[](int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    return elements[index];
}

template<typename T>
T &Vector<T>::operator[](int index) const {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    return elements[index];
}

template<typename T>
void Vector<T>::remove(int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    for (int i = index; i < size - 1; ++i)
        elements[i] = elements[i + 1];
    --size;
}

template<typename T>
int Vector<T>::getSize() const {
    return size;
}

template<typename T>
int Vector<T>::getCapacity() const {
    return capacity;
}

template<typename T>
T *Vector<T>::getElements() const {
    return elements;
}

template<typename T>
ostream &operator<<(ostream &os, const Vector<T> &vec) {
    for (int i = 0; i < vec.getSize(); ++i)
        os << vec.getElements()[i] << " ";
    return os;
}

#endif // VECTOR_VECTOR_H
