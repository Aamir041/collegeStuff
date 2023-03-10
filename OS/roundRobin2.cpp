#include <iostream>
using namespace std;

class Process {
    public:
        int arrival_time;
        int burst_time; 
        int remaining_time; 
        int completion_time; 
        int turnaround_time; 
        int waiting_time;
};

int main() {
    int time_quantum, n, i, total_burst_time = 0, time = 0, completed = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    Process p[10];

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the time quantum: ";
    cin >> time_quantum;

    for (i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i+1 << ": ";
        cin >> p[i].arrival_time >> p[i].burst_time;
        p[i].remaining_time = p[i].burst_time;
        total_burst_time += p[i].burst_time;
    }

    while (completed != n) {
        for (i = 0; i < n; i++) {
            if (p[i].remaining_time <= time_quantum && p[i].remaining_time > 0) {
                time += p[i].remaining_time;
                p[i].remaining_time = 0;
                completed++;
                p[i].completion_time = time;
                p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                avg_waiting_time += p[i].waiting_time;
                avg_turnaround_time += p[i].turnaround_time;
            } 
            else if (p[i].remaining_time > 0) {
                time += time_quantum;
                p[i].remaining_time -= time_quantum;
            }
        }
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    cout << "Process\tCompletion Time\tTurnaround Time\tWaiting Time" << endl;
    for (i = 0; i < n; i++) {
        cout << i+1 << "\t\t" << p[i].completion_time << "\t\t" << p[i].turnaround_time << "\t\t" << p[i].waiting_time << endl;
    }

    cout << "Average waiting time: " << avg_waiting_time << endl;
    cout << "Average turnaround time: " << avg_turnaround_time << endl;

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