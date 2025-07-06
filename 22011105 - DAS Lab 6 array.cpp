#include <iostream>
using namespace std;

class CircularQueue {
private:
    string* arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap = 5) {
        capacity = cap;
        arr = new string[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue '" << name << "'." << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = name;
        size++;

        cout << "Enqueued: " << name << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            cout << arr[index] << " -> ";
        }
        cout << arr[front] << endl; 
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue queue(5); 

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alice");

    cout << "Initial circular queue:\n";
    queue.display();

    queue.dequeue();

    cout << "After one dequeue:\n";
    queue.display();

    return 0;
}

