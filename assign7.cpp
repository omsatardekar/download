//fifo.cpp
#include <iostream>
using namespace std;

void pageReplacement(int frameSize, int pages[], int numPages) {
    int frames[100];
    int pageFaults = 0, pageHits = 0;
    int replaceIndex = 0; 

    // Initialize all frames as empty (-1)
    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < numPages; i++) {
        int currentPage = pages[i];
        bool found = false;

        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == currentPage) {
                pageHits++;
                found = true;
                break;
            }
        }

        // If not found, handle page fault
        if (!found) {
            pageFaults++;
            frames[replaceIndex] = currentPage;
            replaceIndex = (replaceIndex + 1) % frameSize;  // Move to next frame in FIFO order
        }

        // Display current state of frames
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] != -1)
                cout << frames[j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    // Final stats
    cout << "\nTotal Page Faults: " << pageFaults;
    cout << "\nTotal Page Hits: " << pageHits;
    cout << "\nPage Hit Ratio: " << (float)pageHits / numPages;
    cout << "\nPage Fault Ratio: " << (float)pageFaults / numPages << endl;
}

int main() {
    int frameSize, numPages;

    cout << "Enter the frame size: ";
    cin >> frameSize;

    cout << "Enter the number of pages: ";
    cin >> numPages;

    int pages[100];
    cout << "Enter the page numbers: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }

    pageReplacement(frameSize, pages, numPages);
    return 0;
}


//lru.cpp
#include <iostream>
using namespace std;

void pageReplacement(int frameSize, int pages[], int numPages) {
    int frames[100], lastUsed[100];
    int pageFaults = 0, pageHits = 0, time = 0;

    // Initialize all frames as empty (-1) and usage as 0
    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    for (int i = 0; i < numPages; i++) {
        int currentPage = pages[i];
        bool found = false;

        // Check if page is already present (Hit)
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == currentPage) {
                pageHits++;
                lastUsed[j] = time++;  // Update last used time
                found = true;
                break;
            }
        }

        // If not found (Fault)
        if (!found) {
            pageFaults++;

            int replaceIndex = -1;

            // Check for empty frame first
            for (int j = 0; j < frameSize; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // If no empty frame, find LRU page
            if (replaceIndex == -1) {
                int lruTime = time;
                for (int j = 0; j < frameSize; j++) {
                    if (lastUsed[j] < lruTime) {
                        lruTime = lastUsed[j];
                        replaceIndex = j;
                    }
                }
            }

            // Replace the page
            frames[replaceIndex] = currentPage;
            lastUsed[replaceIndex] = time++;
        }

        // Display current frame state
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] != -1)
                cout << frames[j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    // Final stats
    cout << "\nTotal Page Faults: " << pageFaults;
    cout << "\nTotal Page Hits: " << pageHits;
    cout << "\nPage Hit Ratio: " << (float)pageHits / numPages;
    cout << "\nPage Fault Ratio: " << (float)pageFaults / numPages << endl;
}

int main() {
    int frameSize, numPages;

    cout << "Enter the frame size: ";
    cin >> frameSize;

    cout << "Enter the number of pages: ";
    cin >> numPages;

    int pages[100];
    cout << "Enter the page numbers: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }

    pageReplacement(frameSize, pages, numPages);
    return 0;
}

//optimal.cpp:
#include <iostream>
using namespace std;

void pageReplacement(int frameSize, int pages[], int numPages) {
    int frames[100];
    int pageFaults = 0, pageHits = 0;

    // Initialize all frames as empty (-1)
    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < numPages; i++) {
        int currentPage = pages[i];
        bool found = false;

        // Check if the page is already in one of the frames (hit)
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == currentPage) {
                pageHits++;
                found = true;
                break;
            }
        }

        // If the page is not found (page fault)
        if (!found) {
            pageFaults++;
            int replaceIndex = -1;

            // Check for an empty frame first
            for (int j = 0; j < frameSize; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // If no empty frame, find the optimal page to replace
            if (replaceIndex == -1) {
                int farthest = -1;
                int farthestIndex = -1;

                // Find the page that will be used farthest in the future
                for (int j = 0; j < frameSize; j++) {
                    int nextUse = -1;

                    // Find the next use of the page in frames[j] after the current page request
                    for (int k = i + 1; k < numPages; k++) {
                        if (pages[k] == frames[j]) {
                            nextUse = k;
                            break;
                        }
                    }

                    // If the page is never used again, replace it
                    if (nextUse == -1) {
                        farthestIndex = j;
                        break;
                    }

                    // Find the farthest page
                    if (nextUse > farthest) {
                        farthest = nextUse;
                        farthestIndex = j;
                    }
                }

                replaceIndex = farthestIndex;
            }

            // Replace the page in the selected frame
            frames[replaceIndex] = currentPage;
        }

        // Display current state of frames
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] != -1)
                cout << frames[j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    // Final statistics
    cout << "\nTotal Page Faults: " << pageFaults;
    cout << "\nTotal Page Hits: " << pageHits;
    cout << "\nPage Hit Ratio: " << (float)pageHits / numPages;
    cout << "\nPage Fault Ratio: " << (float)pageFaults / numPages << endl;
}

int main() {
    int frameSize, numPages;

    cout << "Enter the frame size: ";
    cin >> frameSize;

    cout << "Enter the number of pages: ";
    cin >> numPages;

    int pages[100];
    cout << "Enter the page numbers: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }

    pageReplacement(frameSize, pages, numPages);
    return 0;
}
