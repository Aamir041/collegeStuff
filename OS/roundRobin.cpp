#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define a class to represent a process
class Process {
public:
    int pid;           // Process ID
    int arrivalTime;   // Arrival time of the process
    int burstTime;     // Burst time of the process
    int remainingTime; // Remaining burst time of the process
};

// Define the main function
int main() {
    // Define the number of processes and time quantum
    const int n = 5;
    const int quantum = 2;

    // Define the processes
    Process processes[n] = {
        {1, 0, 6, 6},
        {2, 1, 4, 4},
        {3, 2, 2, 2},
        {4, 3, 8, 8},
        {5, 4, 3, 3}
    };

    // Define a queue to hold the processes
    queue<Process> processQueue;

    // Initialize the waiting and turnaround times to 0 for all processes
    int waitingTimes[n] = {0};
    int turnaroundTimes[n] = {0};

    // Initialize the current time to the arrival time of the first process
    int currentTime = processes[0].arrivalTime;

    // Add all the processes to the queue
    for (int i = 0; i < n; i++) {
        processQueue.push(processes[i]);
    }

    // Run the CPU scheduling algorithm
    while (!processQueue.empty()) {
        // Get the next process from the queue
        Process currentProcess = processQueue.front();
        processQueue.pop();

        // Run the process for the time quantum or until it completes
        int runTime = min(quantum, currentProcess.remainingTime);
        currentProcess.remainingTime -= runTime;
        currentTime += runTime;

        // Check if the process is complete
        if (currentProcess.remainingTime == 0) {
            // Calculate the waiting and turnaround times for the process
            int waitingTime = currentTime - currentProcess.arrivalTime - currentProcess.burstTime;
            int turnaroundTime = currentTime - currentProcess.arrivalTime;

            // Add the waiting and turnaround times to the total
            waitingTimes[currentProcess.pid - 1] = waitingTime;
            turnaroundTimes[currentProcess.pid - 1] = turnaroundTime;
        } else {
            // Add the process back to the queue
            processQueue.push(currentProcess);
        }
    }

    // Print the waiting and turnaround times for each process
    cout << "Process\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << i+1 << "\t" << waitingTimes[i] << "\t\t" << turnaroundTimes[i] << endl;
    }

    return 0;
}

/*
Here's a brief explanation of the code:

A Process class is defined to hold the arrival time, burst time, remaining time, completion time, turnaround time, and waiting time of each process.

The program prompts the user to enter the number of processes and the time quantum.

The arrival time and burst time for each process are entered by the user and stored in the p array of Process objects. The remaining time and total burst time are also calculated and stored.

The program uses a while loop to simulate the round robin scheduling algorithm. The loop runs until all processes have been completed.

For each iteration of the loop, the program checks each process to see if its remaining time is less than or equal to the time quantum. If it is, the process is completed, and its completion time, turnaround time, and waiting time are calculated and stored. The program also updates the total waiting time and total turnaround time.

If a process's remaining time is greater than the time quantum, the program subtracts the time quantum from its
*/