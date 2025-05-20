#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int start;
    int finish;
    int waiting;
    int turnaround;
    int response;
};

bool arrivalCmp(const Process &a, const Process &b) {
    if (a.arrival == b.arrival)
        return a.burst < b.burst;
    return a.arrival < b.arrival;
}

int main() {
    int n;
    cin >> n;
    vector<Process> proc(n);

    for (int i = 0; i < n; ++i) {
        proc[i].pid = i + 1;
        cin >> proc[i].arrival >> proc[i].burst;
        proc[i].response = -1; 
    }

    vector<bool> done(n, false);
    int completed = 0, current_time = 0;
    double total_waiting = 0, total_turnaround = 0, total_response = 0;
    sort(proc.begin(), proc.end(), arrivalCmp);
    vector<tuple<int, int, int>> gantt_chart; // (start_time, pid, end_time)
    while (completed < n) {
        int idx = -1;
        int min_burst = 1e9;
        for (int i = 0; i < n; ++i) {
            if (!done[i] && proc[i].arrival <= current_time) {
                if (proc[i].burst < min_burst) {
                    min_burst = proc[i].burst;
                    idx = i;
                }
                // If burst time is same, choose process with earlier arrival
                else if (proc[i].burst == min_burst && proc[i].arrival < proc[idx].arrival) {
                    idx = i;
                }
            }
        }
        if (idx == -1) {
            current_time++;
            continue;
        }
        proc[idx].start = current_time;
        proc[idx].waiting = current_time - proc[idx].arrival;
        proc[idx].finish = current_time + proc[idx].burst;
        proc[idx].turnaround = proc[idx].finish - proc[idx].arrival;
        current_time += proc[idx].burst;
        done[idx] = true;
        if (proc[idx].response == -1) {
            proc[idx].response = proc[idx].start - proc[idx].arrival;
        }
        completed++;
        total_waiting += proc[idx].waiting;
        total_turnaround += proc[idx].turnaround;
        total_response += proc[idx].response;
        gantt_chart.push_back({proc[idx].start, proc[idx].pid, proc[idx].finish});
    }

    cout << "\n\nPID\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\tRespose\n";
    for (const auto &p : proc) {
        cout << "P" << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t"
                  << p.start << "\t" << p.finish << "\t" << p.waiting << "\t" << p.turnaround <<"\t   " <<p.response <<"\n";
    }
    cout <<fixed<< setprecision(2);
    cout << "\nAverage Response Time: " << total_response / n;
    cout << "\nAverage Waiting Time: " << total_waiting / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << "\n";

    cout << "\nGantt Chart:\n";
    for (const auto &entry : gantt_chart) {
        int start, pid, end;
        tie(start, pid, end) = entry;
        cout << "|" << start << "--P" << pid << "--" << end;
    }
    cout << "|\n";
    return 0;
}