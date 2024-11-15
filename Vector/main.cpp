#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
    // Create a Vector of integers
    Vector<int> intVector;

    // Add some elements to the Vector
    intVector.push_back(10);
    intVector.push_back(20);
    intVector.push_back(30);

    cout << "Initial Vector: " << intVector << endl;

    // Access elements using the overloaded [] operator
    cout << "Element at index 0: " << intVector[0] << endl;
    cout << "Element at index 1: " << intVector[1] << endl;
    cout << "Element at index 2: " << intVector[2] << endl;

    // Modify an element using the [] operator
    intVector[1] = 25;
    cout << "After modifying index 1: " << intVector << endl;

    // Remove an element
    intVector.remove(1);
    cout << "After removing index 1: " << intVector << endl;

    // Check if the Vector is empty
    cout << "Is the Vector empty? " << (intVector.isEmpty() ? "Yes" : "No") << endl;

    // Display size and capacity
    cout << "Size of Vector: " << intVector.getSize() << endl;
    cout << "Capacity of Vector: " << intVector.getCapacity() << endl;

    // Add more elements to see resizing
    for (int i = 40; i <= 100; i += 10) {
        intVector.push_back(i);
    }
    cout << "After adding more elements: " << intVector << endl;

    cout << "Final size: " << intVector.getSize() << ", Capacity: " << intVector.getCapacity() << endl;

    return 0;
}
