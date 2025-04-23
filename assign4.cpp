#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>

using namespace std;
sem_t x, y;
int readerCount = 0;

void reader(int id) {
    sem_wait(&x);
    readerCount++;
    if (readerCount == 1) {
        sem_wait(&y); // First reader locks writers
    }
    sem_post(&x);

    cout << "Reader " << id << " is reading.\n";
    usleep(3000000); // Simulate reading

    sem_wait(&x);
    readerCount--;
    if (readerCount == 0) {
        sem_post(&y); // Last reader unlocks writers
    }
    sem_post(&x);

    cout << "Reader " << id << " has finished reading.\n";
}

void writer(int id) {
    cout << "Writer " << id << " is trying to write.\n";
    sem_wait(&y); // Writer gets exclusive access
    cout << "Writer " << id << " is writing.\n";
    usleep(3000000); // Simulate writing
    cout << "Writer " << id << " has finished writing.\n";
    sem_post(&y);
}

int main() {
    int n_readers, n_writers;

    cout << "Enter number of readers: ";
    cin >> n_readers;
    cout << "Enter number of writers: ";
    cin >> n_writers;

    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);

    thread readerThreads[100], writerThreads[100];

    for (int i = 0; i < n_readers; i++) {
        readerThreads[i] = thread(reader, i + 1);
    }

    for (int i = 0; i < n_writers; i++) {
        writerThreads[i] = thread(writer, i + 1);
    }

    for (int i = 0; i < n_readers; i++) {
        readerThreads[i].join();
    }

    // Join all writer threads
    for (int i = 0; i < n_writers; i++) {
        writerThreads[i].join();
    }

    sem_destroy(&x);
    sem_destroy(&y);

    return 0;
}
