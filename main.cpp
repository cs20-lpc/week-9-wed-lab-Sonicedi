#include "ArrayQueue.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    // create a queue of 10 integers
    ArrayQueue<int> queueA(10);

    // attempt to display the front and back
    try {
        cout << queueA.front() << endl;
    } catch (string& e) {
        cout << e << endl;
    }
    try {
        cout << queueA.back() << endl;
    } catch (string& e) {
        cout << e << endl;
    }

    // insert just one element to queue A
    queueA.enqueue(-5);

    // display its length, front, and back
    cout << "queue A length: " << queueA.getLength() << endl;
    cout << "queue A front: "  << queueA.front()     << endl;
    cout << "queue A back: "   << queueA.back()      << endl;

    // now remove the single element from queue A
    queueA.dequeue();

    // display its length, front, and back
    cout << "queue A length: " << queueA.getLength() << endl;
    try {
        cout << queueA.front() << endl;
    } catch (string& e) {
        cout << e << endl;
    }
    try {
        cout << queueA.back() << endl;
    } catch (string& e) {
        cout << e << endl;
    }

    // --- the rest of your original tests, but with line breaks ---

    // populate queue A by enqueueing random values
    srand(time(0));
    for (int i = 0; i < queueA.getMaxSize(); i++) {
        queueA.enqueue(rand() % 500);
    }

    // ensure that queue A is now full
    if (queueA.isFull()) {
        cout << "queue A is full!" << endl;
    }
    else {
        cout << "queue A is not full [ERROR]" << endl;
    }

    // display its length, front, and back
    cout << "queue A length: " << queueA.getLength() << endl;
    cout << "queue A front: "  << queueA.front()     << endl;
    cout << "queue A back: "   << queueA.back()      << endl;

    // make a copy of queue A
    ArrayQueue<int> queueB = queueA;

    // loop to dequeue and print
    cout << "queue A contains: ";
    for (int i = 0; i < queueA.getMaxSize(); i++) {
        cout << queueA.front() << ' ';
        queueA.dequeue();
    }
    cout << endl;

    // queue A should now be empty
    if (queueA.isEmpty()) {
        cout << "queue A is now empty" << endl;
    }
    else {
        cout << "queue A is not empty [ERROR]" << endl;
    }

    // display queue B length, front, and back
    cout << "queue B length: " << queueB.getLength() << endl;
    cout << "queue B front: "  << queueB.front()     << endl;
    cout << "queue B back: "   << queueB.back()      << endl;

    // make a copy of queue B
    ArrayQueue<int> queueC;
    queueC = queueB;

    // clear out queue B
    queueB.clear();

    // queue B should now be empty
    if (queueB.isEmpty()) {
        cout << "queue B is now empty" << endl;
    }
    else {
        cout << "queue B is not empty [ERROR]" << endl;
    }

    // display queue C length, front, and back
    cout << "queue C length: " << queueC.getLength() << endl;
    cout << "queue C front: "  << queueC.front()     << endl;
    cout << "queue C back: "   << queueC.back()      << endl;

    // terminate
    return 0;
}
