#include <iostream>
using namespace std;

class LinearQueue {
private:
    int *queue;
    int front;
    int rear;
    int capacity;

public:
    // Constructor
    LinearQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~LinearQueue() {
        delete[] queue;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == capacity - 1;
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

        rear++;
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
            front++;
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
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    LinearQueue queue(size);

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
