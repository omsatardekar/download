//fcfs.cpp

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[100], at[100], bt[100], ct[100], wt[100], tat[100];
    float totalWT = 0, totalTAT = 0;

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time for Process " << pid[i] << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for Process " << pid[i] << ": ";
        cin >> bt[i];
    }

    // Sort processes by Arrival Time (Simple Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                swap(at[j], at[j + 1]);
                swap(bt[j], bt[j + 1]);
                swap(pid[j], pid[j + 1]);
            }
        }
    }

    // Completion time
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    // Turnaround time and Waiting time
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    // Output
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i]
             << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << endl;

    return 0;
}

//sjf.cpp:
#include <iostream>
using namespace std;

int main() {
    int n, choice;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[100], at[100], bt[100], remainingBT[100];
    int ct[100], wt[100], tat[100];
    bool completed[100] = {false};

    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Process " << pid[i] << " Arrival Time: ";
        cin >> at[i];
        cout << "Process " << pid[i] << " Burst Time: ";
        cin >> bt[i];
        remainingBT[i] = bt[i]; // for preemptive version
    }

    cout << "\nChoose Scheduling Algorithm:\n";
    cout << "1. SJF Non-Preemptive\n";
    cout << "2. SJF Preemptive\n";
    cout << "Enter choice: ";
    cin >> choice;

    float totalWT = 0, totalTAT = 0;

    if (choice == 1) {
        // SJF Non-Preemptive
        int time = 0, completedCount = 0;
        while (completedCount < n) {
            int idx = -1, minBT = 1e9;
            for (int i = 0; i < n; i++) {
                if (!completed[i] && at[i] <= time && bt[i] < minBT) {
                    minBT = bt[i];
                    idx = i;
                }
            }

            if (idx != -1) {
                time += bt[idx];
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];

                totalTAT += tat[idx];
                totalWT += wt[idx];

                completed[idx] = true;
                completedCount++;
            } else {
                time++;
            }
        }
    }

    else if (choice == 2) {
        // SJF Preemptive (Shortest Remaining Time First)
        int time = 0, completedCount = 0;
        while (completedCount < n) {
            int idx = -1, minRT = 1e9;
            for (int i = 0; i < n; i++) {
                if (!completed[i] && at[i] <= time && remainingBT[i] < minRT && remainingBT[i] > 0) {
                    minRT = remainingBT[i];
                    idx = i;
                }
            }

            if (idx != -1) {
                remainingBT[idx]--;
                time++;

                if (remainingBT[idx] == 0) {
                    ct[idx] = time;
                    tat[idx] = ct[idx] - at[idx];
                    wt[idx] = tat[idx] - bt[idx];
                    totalTAT += tat[idx];
                    totalWT += wt[idx];
                    completed[idx] = true;
                    completedCount++;
                }
            } else {
                time++;
            }
        }
    }

    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    // Output
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i]
             << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << endl;

    return 0;
}

//roundrobin.cpp
#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[100], at[100], bt[100], ct[100], tat[100], wt[100];
    int remainingBT[100];
    bool completed[100] = {false};
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time for Process " << pid[i] << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for Process " << pid[i] << ": ";
        cin >> bt[i];
        remainingBT[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0, completedCount = 0;

    while (completedCount < n) {
        bool doneInThisCycle = false;

        for (int i = 0; i < n; i++) {
            if (remainingBT[i] > 0 && at[i] <= time) {
                doneInThisCycle = true;

                if (remainingBT[i] > tq) {
                    time += tq;
                    remainingBT[i] -= tq;
                } else {
                    time += remainingBT[i];
                    remainingBT[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    totalTAT += tat[i];
                    totalWT += wt[i];
                    completed[i] = true;
                    completedCount++;
                }
            }
        }

        // If no process was ready in this cycle, just move time forward
        if (!doneInThisCycle)
            time++;
    }

    // Output Table
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i]
             << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << endl;

    return 0;
}

//priority.cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[100], at[100], bt[100], pr[100];
    int ct[100], tat[100], wt[100];
    int remainingBT[100];
    bool completed[100] = {false};
    float totalTAT = 0, totalWT = 0;

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time for Process " << pid[i] << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for Process " << pid[i] << ": ";
        cin >> bt[i];
        cout << "Enter Priority for Process " << pid[i] << " (Lower = Higher priority): ";
        cin >> pr[i];
        remainingBT[i] = bt[i]; // For preemptive
    }

    int choice;
    cout << "\nSelect Scheduling Type:\n";
    cout << "1. Priority Scheduling (Non-Preemptive)\n";
    cout << "2. Priority Scheduling (Preemptive)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int time = 0, completedCount = 0;

    if (choice == 1) {
        // Priority Non-Preemptive
        while (completedCount < n) {
            int idx = -1, highestPriority = 1e9;

            for (int i = 0; i < n; i++) {
                if (!completed[i] && at[i] <= time && pr[i] < highestPriority) {
                    highestPriority = pr[i];
                    idx = i;
                }
            }

            if (idx != -1) {
                time += bt[idx];
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                totalTAT += tat[idx];
                totalWT += wt[idx];
                completed[idx] = true;
                completedCount++;
            } 
            else {
                time++;
            }
        }

    } else if (choice == 2) {
        // Priority Preemptive
        while (completedCount < n) {
            int idx = -1, highestPriority = 1e9;

            for (int i = 0; i < n; i++) {
                if (!completed[i] && at[i] <= time && pr[i] < highestPriority && remainingBT[i] > 0) {
                    highestPriority = pr[i];
                    idx = i;
                }
            }

            if (idx != -1) {
                remainingBT[idx]--;
                time++;

                if (remainingBT[idx] == 0) {
                    ct[idx] = time;
                    tat[idx] = ct[idx] - at[idx];
                    wt[idx] = tat[idx] - bt[idx];
                    totalTAT += tat[idx];
                    totalWT += wt[idx];
                    completed[idx] = true;
                    completedCount++;
                }
            } else {
                time++;
            }
        }
    } else {
        cout << "Invalid choice.\n";
        return 0;
    }

    // Output
    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << pr[i]
             << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "\nAverage Turnaround Time: " << totalTAT / n;
    cout << "Average Waiting Time: " << totalWT / n << endl;

    return 0;
}
