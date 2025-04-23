#include <iostream>
using namespace std;

int main() {
    int n, m; // n = number of processes, m = number of resources
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int max[10][10], alloc[10][10], need[10][10], avail[10];
    bool finish[10] = {false};
    int safeSeq[10];

    // Input Max matrix
    cout << "\nEnter MAX matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    // Input Allocation matrix
    cout << "\nEnter ALLOCATION matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    // Input Available resources
    cout << "\nEnter AVAILABLE resources: ";
    for (int i = 0; i < m; i++) {
        cin >> avail[i];
    }

    // Calculate Need matrix = Max - Allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Safety check
    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    for (int j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            break; // No safe sequence
        }
    }

    if (count == n) {
        cout << "\nSystem is in a SAFE state.\nSafe sequence is: ";
        for (int i = 0; i < n; i++) {
            cout << "P" << safeSeq[i];
            if (i < n - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "\nSystem is NOT in a safe state (Deadlock may occur).\n";
    }

    return 0;
}
