#include <iostream> 
#define MAX 10 
using namespace std; 
 
struct Queue { 
    int data[MAX]; 
    int front, rear; 
}; 
 
class QueueOperations { 
private: 
    Queue q; 
 
public: 
    QueueOperations() { 
        q.front = q.rear = -1; 
    } 
 
    bool isEmpty() { 
        return q.front == q.rear; 
    } 
 
    bool isFull() { 
        return q.rear == MAX - 1; 
    } 
 
    void enqueue(int x) { 
        if (!isFull()) { 
            q.data[++q.rear] = x; 
            cout << "Job inserted: " << x << endl; 
        } else { 
            cout << "Queue Overflow! Cannot insert job." << endl; 
        } 
    } 
 
    void dequeue() { 
        if (!isEmpty()) { 
            cout << "Deleted Job: " << q.data[++q.front] << endl; 
        } else { 
            cout << "Queue Underflow! No job to delete." << endl; 
        } 
    } 
 
    void display() { 
        if (!isEmpty()) { 
            cout << "Jobs in Queue: "; 
            for (int i = q.front + 1; i <= q.rear; i++) { 
                cout << q.data[i] << " "; 
            } 
            cout << endl; 
        } else { 
            cout << "Queue is empty!" << endl; 
        } 
    } 
}; 
 
int main() { 
    QueueOperations queue; 
    int choice, job; 
 
    do { 
        cout << "\nMenu:\n" 
             << "1. Insert Job\n" 
             << "2. Delete Job\n" 
             << "3. Display Jobs\n" 
             << "4. Exit\n" 
             << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                cout << "Enter job data: "; 
                cin >> job; 
                queue.enqueue(job); 
                break; 
            case 2: 
                queue.dequeue(); 
                break; 
            case 3: 
                queue.display(); 
                break; 
            case 4: 
                cout << "Exiting Program..." << endl; 
                break; 
            default: 
                cout << "Invalid choice! Please try again." << endl; 
        } 
    } while (choice != 4); 
 
    return 0; 
}