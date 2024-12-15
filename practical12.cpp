#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void addFront(int item) {
        if (isFull()) {
            cout << "Deque is full. Cannot add " << item << " at front." << endl;
            return;
        }
        front = (front + 1) % capacity;
        arr[front] = item;
        size++;
        if (rear == 0) {
            rear = front;
        }
    }

    void addRear(int item) {
        if (isFull()) {
            cout << "Deque is full. Cannot add " << item << " at rear." << endl;
            return;
        }
        rear = (rear - 1 + capacity) % capacity;
        arr[rear] = item;
        size++;
        if (front == -1) {
            front = rear;
        }
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return;
        }
        cout << "Deleted from front: " << arr[front] << endl;
        front = (front - 1 + capacity) % capacity;
        size--;
        if (size == 0) {
            front = -1;
            rear = 0;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << endl;
        rear = (rear + 1) % capacity;
        size--;
        if (size == 0) {
            front = -1;
            rear = 0;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(rear + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque deque(5);

    deque.addRear(10);
    deque.addRear(20);
    deque.addFront(5);
    deque.display();

    deque.deleteFront();
    deque.display();

    deque.addFront(1);
    deque.addRear(30);
    deque.display();

    deque.deleteRear();
    deque.display();

    return 0;
}