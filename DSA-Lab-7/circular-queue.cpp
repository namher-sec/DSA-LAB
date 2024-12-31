#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int front;
    int rear;
    int capacity;

public:
    // Constructor
    CircularQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~CircularQueue() {
        delete[] queue;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Enqueue an element into the queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        queue[rear] = element;
        cout << "Enqueued: " << element << endl;
    }

    // Dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << queue[front] << endl;

        if (front == rear) {
            // Queue becomes empty after dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    // Get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1; // Return an invalid value
        }

        return queue[front];
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    CircularQueue queue(size);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    cout << "Front element: " << queue.getFront() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    return 0;
}
