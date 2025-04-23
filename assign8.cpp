//fcfs.cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int totalTracks;
    cout << "Enter total number of tracks: ";
    cin >> totalTracks;

    int queueSize;
    cout << "Enter the number of tracks in queue: ";
    cin >> queueSize;

    int startTrack;
    cout << "Enter starting track: ";
    cin >> startTrack;

    int trackQueue[100]; // Static array to store track numbers
    cout << "Enter tracks in the queue:\n";
    for (int i = 0; i < queueSize; ++i) {
        cin >> trackQueue[i];
    }

    int totalCost = 0;
    int currentTrack = startTrack;
    cout << "\nSequence of tracks visited: " << currentTrack;
    
    // FCFS algorithm
    for (int i = 0; i < queueSize; ++i) {
        totalCost += abs(trackQueue[i] - currentTrack); // Calculate the cost (distance)
        currentTrack = trackQueue[i]; // Move to the next track
        cout << " -> " << currentTrack;
    }
    
    cout << "\nTotal cost: " << totalCost << endl; // Total movement cost
    return 0;
}

//sstf.cpp:
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int totalTracks;
    cout << "Enter total number of tracks: ";
    cin >> totalTracks;

    int queueSize;
    cout << "Enter the number of tracks in queue: ";
    cin >> queueSize;

    int startTrack;
    cout << "Enter starting track: ";
    cin >> startTrack;

    int trackQueue[100]; // Static array to store track numbers
    cout << "Enter tracks in the queue:\n";
    for (int i = 0; i < queueSize; ++i) {
        cin >> trackQueue[i];
    }

    int totalCost = 0;
    int currentTrack = startTrack;
    bool visited[100] = {false}; // Array to track visited tracks

    cout << "\nSequence of tracks visited: " << currentTrack;
    
    for (int i = 0; i < queueSize; ++i) {
        int minDistance = 10000; // Initialize with a large value
        int nextTrack = -1;
        
        // Find the nearest unvisited track
        for (int j = 0; j < queueSize; ++j) {
            if (!visited[j]) {
                int distance = abs(trackQueue[j] - currentTrack);
                if (distance < minDistance) {
                    minDistance = distance;
                    nextTrack = j;
                }
            }
        }

        // Visit the nearest track
        visited[nextTrack] = true;
        totalCost += minDistance;
        currentTrack = trackQueue[nextTrack];
        cout << " -> " << currentTrack;
    }

    cout << "\nTotal cost: " << totalCost << endl; // Total movement cost
    return 0;
}

//scan.cpp:

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int totalTracks;
    cout << "Enter total number of tracks: ";
    cin >> totalTracks;

    int queueSize;
    cout << "Enter the number of tracks in queue: ";
    cin >> queueSize;

    int startTrack;
    cout << "Enter starting track: ";
    cin >> startTrack;

    int direction;
    cout << "Enter direction (0 for left, 1 for right): ";
    cin >> direction;

    int trackQueue[100];
    cout << "Enter tracks in the queue:\n";
    for (int i = 0; i < queueSize; ++i) {
        cin >> trackQueue[i];
    }

    // Add starting position and boundary (0 or max track) to the queue
    trackQueue[queueSize++] = startTrack;

    if (direction == 0)
        trackQueue[queueSize++] = 0;  // If going left, include 0
    else
        trackQueue[queueSize++] = totalTracks - 1;  // If going right, include last track

    // Sort the track queue
    sort(trackQueue, trackQueue + queueSize);

    // Find the index of the starting track in sorted array
    int index = 0;
    for (int i = 0; i < queueSize; ++i) {
        if (trackQueue[i] == startTrack) {
            index = i;
            break;
        }
    }

    int totalCost = 0;
    int currentTrack = startTrack;
    cout << "\nSequence of tracks visited: " << currentTrack;

    if (direction == 1) { // Right
        for (int i = index + 1; i < queueSize; ++i) {
            totalCost += abs(trackQueue[i] - currentTrack);
            currentTrack = trackQueue[i];
            cout << " -> " << currentTrack;
        }
        for (int i = index - 1; i >= 0; --i) {
            totalCost += abs(trackQueue[i] - currentTrack);
            currentTrack = trackQueue[i];
            cout << " -> " << currentTrack;
        }
    } else { // Left
        for (int i = index - 1; i >= 0; --i) {
            totalCost += abs(trackQueue[i] - currentTrack);
            currentTrack = trackQueue[i];
            cout << " -> " << currentTrack;
        }
        for (int i = index + 1; i < queueSize; ++i) {
            totalCost += abs(trackQueue[i] - currentTrack);
            currentTrack = trackQueue[i];
            cout << " -> " << currentTrack;
        }
    }

    cout << "\nTotal cost: " << totalCost << endl;
    return 0;
}


//cscan.cpp:
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int totalTracks;
    cout << "Enter total number of tracks: ";
    cin >> totalTracks;

    int queueSize;
    cout << "Enter the number of tracks in queue: ";
    cin >> queueSize;

    int startTrack;
    cout << "Enter starting track: ";
    cin >> startTrack;

    int direction;
    cout << "Enter direction (0 for left, 1 for right): ";
    cin >> direction;

    int trackQueue[100];
    cout << "Enter tracks in the queue:\n";
    for (int i = 0; i < queueSize; ++i) {
        cin >> trackQueue[i];
    }

    // Add starting position and boundary to simulate full sweep
    trackQueue[queueSize++] = startTrack;

    if (direction == 0)
        trackQueue[queueSize++] = 0;  // If left, end at 0
    else
        trackQueue[queueSize++] = totalTracks - 1;  // If right, end at max track

    // Sort the queue
    sort(trackQueue, trackQueue + queueSize);

    // Find index of the start track
    int index = 0;
    for (int i = 0; i < queueSize; ++i) {
        if (trackQueue[i] == startTrack) {
            index = i;
            break;
        }
    }

    int totalCost = 0;
    int currentTrack = startTrack;
    cout << "\nSequence of tracks visited: " << currentTrack;

    if (direction == 1) { // Moving right
        for (int i = index + 1; i < queueSize; ++i) {
            totalCost += abs(trackQueue[i] - currentTrack);
            currentTrack = trackQueue[i];
            cout << " -> " << currentTrack;
        }

        // Wrap around to beginning (track 0)
        if (currentTrack != 0) {
            totalCost += abs((totalTracks - 1) - 0); // Jump from end to start (circular)
            currentTrack = 0;
        }

        for (int i = 0; i < index; ++i) {
            totalCost += abs(trackQueue[i] - currentTrack);
            currentTrack = trackQueue[i];
            cout << " -> " << currentTrack;
        }
    } else { // Moving left
        for (int i = index - 1; i >= 0; --i) {
            totalCost += abs(trackQueue[i] - currentTrack);
            currentTrack = trackQueue[i];
            cout << " -> " << currentTrack;
        }

        // Wrap around to end (totalTracks - 1)
        if (currentTrack != totalTracks - 1) {
            totalCost += abs(0 - (totalTracks - 1));
            currentTrack = totalTracks - 1;
        }

        for (int i = queueSize - 1; i > index; --i) {
            totalCost += abs(trackQueue[i] - currentTrack);
            currentTrack = trackQueue[i];
            cout << " -> " << currentTrack;
        }
    }

    cout << "\nTotal cost: " << totalCost << endl;
    return 0;
}


