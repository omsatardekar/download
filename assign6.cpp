//firstfit.cpp
#include <iostream>
using namespace std;

int main() {
    int numBlocks, numProcesses;

    // Input number of blocks
    cout << "Enter the number of memory blocks: ";
    cin >> numBlocks;

    int blockSize[100];           // assuming max 100 blocks
    bool blockAllocated[100] = {}; // initialized to false

    cout << "Enter the size of each memory block:\n";
    for (int i = 0; i < numBlocks; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    // Input number of processes
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    int processSize[100];        // assuming max 100 processes
    int allocation[100];         // -1 means not allocated

    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1; // initialize
    }

    cout << "Enter the size of each process:\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processSize[i];
    }

    int totalInternalFragmentation = 0;

    // Allocation logic
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numBlocks; j++) {
            if (!blockAllocated[j] && blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockAllocated[j] = true;
                totalInternalFragmentation += blockSize[j] - processSize[i];
                break;
            }
        }
    }

    // Display Allocation Table
    cout << "\nProcess No.\tProcess Size\tBlock Allocated\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }

    // Calculate external fragmentation
    int totalExternalFragmentation = 0;
    for (int i = 0; i < numBlocks; i++) {
        if (!blockAllocated[i]) {
            totalExternalFragmentation += blockSize[i];
        }
    }
    // Final output
    cout << "\nTotal Internal Fragmentation: " << totalInternalFragmentation << " units";
    cout << "\nTotal External Fragmentation: " << totalExternalFragmentation << " units\n";

    return 0;
}

//nextfit.cpp
#include <iostream>
using namespace std;

int main() {
    int numBlocks, numProcesses;

    // Input number of blocks
    cout << "Enter the number of memory blocks: ";
    cin >> numBlocks;

    int blockSize[100];            // assuming max 100 blocks
    bool blockAllocated[100] = {}; // initialized to false

    cout << "Enter the size of each memory block:\n";
    for (int i = 0; i < numBlocks; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    // Input number of processes
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    int processSize[100]; // assuming max 100 processes
    int allocation[100];  // -1 means not allocated

    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1;
    }

    cout << "Enter the size of each process:\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processSize[i];
    }

    int totalInternalFragmentation = 0;
    int lastAllocatedIndex = 0; // Keeps track of where the last allocation ended

    // Next Fit Allocation logic
    for (int i = 0; i < numProcesses; i++) {
        int j = lastAllocatedIndex;
        bool allocated = false;

        for (int k = 0; k < numBlocks; k++) {
            int index = (j + k) % numBlocks;
            if (!blockAllocated[index] && blockSize[index] >= processSize[i]) {
                allocation[i] = index;
                blockAllocated[index] = true;
                totalInternalFragmentation += blockSize[index] - processSize[i];
                lastAllocatedIndex = (index + 1) % numBlocks;
                allocated = true;
                break;
            }
        }

        if (!allocated) {
            allocation[i] = -1; // Not Allocated
        }
    }

    // Display Allocation Table
    cout << "\nProcess No.\tProcess Size\tBlock Allocated\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }

    // Calculate external fragmentation
    int totalExternalFragmentation = 0;
    for (int i = 0; i < numBlocks; i++) {
        if (!blockAllocated[i]) {
            totalExternalFragmentation += blockSize[i];
        }
    }

    // Final output
    cout << "\nTotal Internal Fragmentation: " << totalInternalFragmentation << " units";
    cout << "\nTotal External Fragmentation: " << totalExternalFragmentation << " units\n";

    return 0;
}

//bestfit.cpp
#include <iostream>
using namespace std;

int main() {
    int numBlocks, numProcesses;

    // Input number of blocks
    cout << "Enter the number of memory blocks: ";
    cin >> numBlocks;

    int blockSize[100];             // assuming max 100 blocks
    bool blockAllocated[100] = {};  // initialized to false

    cout << "Enter the size of each memory block:\n";
    for (int i = 0; i < numBlocks; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    // Input number of processes
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    int processSize[100];   // assuming max 100 processes
    int allocation[100];    // -1 means not allocated

    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1;
    }

    cout << "Enter the size of each process:\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processSize[i];
    }

    int totalInternalFragmentation = 0;

    // Best Fit Allocation Logic
    for (int i = 0; i < numProcesses; i++) {
        int bestIndex = -1;
        int minDiff = INT_MAX;

        for (int j = 0; j < numBlocks; j++) {
            if (!blockAllocated[j] && blockSize[j] >= processSize[i]) {
                int diff = blockSize[j] - processSize[i];
                if (diff < minDiff) {
                    minDiff = diff;
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockAllocated[bestIndex] = true;
            totalInternalFragmentation += blockSize[bestIndex] - processSize[i];
        }
    }

    // Display Allocation Table
    cout << "\nProcess No.\tProcess Size\tBlock Allocated\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }

    // Calculate external fragmentation
    int totalExternalFragmentation = 0;
    for (int i = 0; i < numBlocks; i++) {
        if (!blockAllocated[i]) {
            totalExternalFragmentation += blockSize[i];
        }
    }

    // Final output
    cout << "\nTotal Internal Fragmentation: " << totalInternalFragmentation << " units";
    cout << "\nTotal External Fragmentation: " << totalExternalFragmentation << " units\n";

    return 0;
}

//worstfit.cpp
#include <iostream>
using namespace std;

int main() {
    int numBlocks, numProcesses;

    // Input number of blocks
    cout << "Enter the number of memory blocks: ";
    cin >> numBlocks;

    int blockSize[100];             // assuming max 100 blocks
    bool blockAllocated[100] = {};  // initialized to false

    cout << "Enter the size of each memory block:\n";
    for (int i = 0; i < numBlocks; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    // Input number of processes
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    int processSize[100];   // assuming max 100 processes
    int allocation[100];    // -1 means not allocated

    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1;
    }

    cout << "Enter the size of each process:\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processSize[i];
    }

    int totalInternalFragmentation = 0;

    // Worst Fit Allocation Logic
    for (int i = 0; i < numProcesses; i++) {
        int worstIndex = -1;
        int maxDiff = -1;

        for (int j = 0; j < numBlocks; j++) {
            if (!blockAllocated[j] && blockSize[j] >= processSize[i]) {
                int diff = blockSize[j] - processSize[i];
                if (diff > maxDiff) {
                    maxDiff = diff;
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1) {
            allocation[i] = worstIndex;
            blockAllocated[worstIndex] = true;
            totalInternalFragmentation += blockSize[worstIndex] - processSize[i];
        }
    }

    // Display Allocation Table
    cout << "\nProcess No.\tProcess Size\tBlock Allocated\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }

    // Calculate external fragmentation
    int totalExternalFragmentation = 0;
    for (int i = 0; i < numBlocks; i++) {
        if (!blockAllocated[i]) {
            totalExternalFragmentation += blockSize[i];
        }
    }

    // Final output
    cout << "\nTotal Internal Fragmentation: " << totalInternalFragmentation << " units";
    cout << "\nTotal External Fragmentation: " << totalExternalFragmentation << " units\n";

    return 0;
}
