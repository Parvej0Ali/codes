#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
};

struct PriorityComparator {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.priority > p2.priority;
    }
};

int main() {
    priority_queue<Process, vector<Process>, PriorityComparator> priority_queue;
    queue<Process> round_robin_queue;
    queue<Process> fcfs_queue;

    int time_slice;
    cout << "Enter time slice for round-robin queue: ";
    cin >> time_slice;

    int fcfs_time;
    cout << "Enter time for fcfs queue: ";
    cin >> fcfs_time;

    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Process p;
        p.pid = i + 1;
        p.arrival_time = 0;
        cout << "Enter burst time for process " << p.pid << ": ";
        cin >> p.burst_time;
        cout << "Enter priority for process " << p.pid << ": ";
        cin >> p.priority;
        p.remaining_time = p.burst_time;
        priority_queue.push(p);
    }

    int time = 0;
    while (!priority_queue.empty() || !round_robin_queue.empty() || !fcfs_queue.empty()) {
        if (!priority_queue.empty()) {
            Process p = priority_queue.top();
            priority_queue.pop();

            if (p.remaining_time <= time_slice) {
                time += p.remaining_time;
                p.remaining_time = 0;
                cout << "Process " << p.pid << " finished at time " << time << endl;
            } else {
                time += time_slice;
                p.remaining_time -= time_slice;
                round_robin_queue.push(p);
            }
        } else if (!round_robin_queue.empty()) {
            Process p = round_robin_queue.front();
            round_robin_queue.pop();

            if (p.remaining_time <= time_slice) {
                time += p.remaining_time;
                p.remaining_time = 0;
                cout << "Process " << p.pid << " finished at time " << time << endl;
            } else {
                time += time_slice;
                p.remaining_time -= time_slice;
                fcfs_queue.push(p);
            }
        } else if (!fcfs_queue.empty()) {
            Process p = fcfs_queue.front();
            fcfs_queue.pop();

            time += p.remaining_time;
            p.remaining_time = 0;
            cout << "Process " << p.pid << " finished at time " << time << endl;
        }
    }

    return 0;
}