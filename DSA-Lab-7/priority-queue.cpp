#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int* queue;
    int capacity;
    int size;

public:
    // Constructor
    PriorityQueue(int cap) : capacity(cap), size(0) {
        queue = new int[capacity];
    }

    // Destructor
    ~PriorityQueue() {
        delete[] queue;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Enqueue an element into the queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        queue[size++] = element;
        cout << "Enqueued: " << element << endl;
    }

    // Dequeue the minimum element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        // Find the index of the minimum element
        int minIndex = 0;
        for (int i = 1; i < size; i++) {
            if (queue[i] < queue[minIndex]) {
                minIndex = i;
            }
        }

        cout << "Dequeued: " << queue[minIndex] << endl;

        // Shift elements to the left to fill the gap
        for (int i = minIndex; i < size - 1; i++) {
            queue[i] = queue[i + 1];
        }

        size--;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the priority queue: ";
    cin >> capacity;

    PriorityQueue pq(capacity);

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(20);
    pq.display();

    pq.dequeue();
    pq.display();

    pq.enqueue(5);
    pq.display();

    pq.dequeue();
    pq.display();

    return 0;
}
