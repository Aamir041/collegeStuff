#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a class to represent a process
class Process {
public:
    string name;    // Name of the process
    int arrival;    // Arrival time of the process
    int burst;      // Burst time of the process
    int priority;   // Priority of the process
    int waiting;    // Waiting time of the process
    int turnaround; // Turnaround time of the process
};

// Define a function to compare processes based on their arrival times
bool compareArrival(const Process& p1, const Process& p2) {
    return p1.arrival < p2.arrival;
}

// Define a function to compare processes based on their priorities
bool comparePriority(const Process& p1, const Process& p2) {
    return p1.priority < p2.priority;
}

// Define a function to simulate the priority scheduling algorithm
void priorityScheduling(Process processes[], int n) {
    // Sort the processes based on their arrival times
    sort(processes, processes+n, compareArrival);

    // Initialize the waiting and turnaround times to 0 for all processes
    for (int i = 0; i < n; i++) {
        processes[i].waiting = 0;
        processes[i].turnaround = 0;
    }

    // Initialize the current time and the completed processes
    int currentTime = 0;
    int completed = 0;

    // Loop until all processes have been completed
    while (completed < n) {
        // Find the process with the highest priority that has arrived
        int highestPriorityIndex = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= currentTime && (highestPriorityIndex == -1 || comparePriority(processes[i], processes[highestPriorityIndex]))) {
                highestPriorityIndex = i;
            }
        }

        // Update the waiting and turnaround times for the selected process
        if (highestPriorityIndex != -1) {
            Process& currentProcess = processes[highestPriorityIndex];
            currentProcess.waiting = currentTime - currentProcess.arrival;
            currentProcess.turnaround = currentProcess.waiting + currentProcess.burst;

            // Update the current time and mark the process as completed
            currentTime += currentProcess.burst;
            completed++;
        }
        else {
            // If no process has arrived yet, increment the current time
            currentTime++;
        }
    }

    // Print the waiting and turnaround times for each process
    cout << "Process\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        Process& currentProcess = processes[i];
        cout << currentProcess.name << "\t" << currentProcess.waiting << "\t\t" << currentProcess.turnaround << endl;
    }
}

// Define the main function
int main() {
    // Define the number of processes
    const int n = 4;

    // Define the processes
    Process processes[n] = {
        {"P1", 0, 8, 3},
        {"P2", 1, 4, 1},
        {"P3", 2, 9, 4},
        {"P4", 3, 5, 2}
    };

    // Run the priority scheduling algorithm
    priorityScheduling(processes, n);

    return 0;
}
