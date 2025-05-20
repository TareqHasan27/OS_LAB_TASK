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

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; ++i) {
        p[i].pid = i + 1;
        cout << "Enter arrival time and burst time for process " << p[i].pid << ": ";
        cin >> p[i].arrival >> p[i].burst;
    }

    sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        return a.arrival < b.arrival;
    });

    int current_time = 0;
    double total_waiting = 0, total_turnaround = 0, total_response = 0;
    vector<tuple<int, int, int>> gantt_chart;

    for (int i = 0; i < n; ++i) {
        if (current_time < p[i].arrival)
            current_time = p[i].arrival;
        p[i].start = current_time;
        p[i].waiting = p[i].start - p[i].arrival;
        p[i].response = p[i].waiting;
        p[i].finish = p[i].start + p[i].burst;
        p[i].turnaround = p[i].finish - p[i].arrival;
        current_time = p[i].finish;
        gantt_chart.push_back({p[i].start, p[i].finish, p[i].pid});

        total_waiting += p[i].waiting;
        total_turnaround += p[i].turnaround;
        total_response += p[i].response;
    }

    cout << "\nPID\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\tResponse\n";
    for (const auto &proc : p) {
        cout << proc.pid << "\t" << proc.arrival << "\t" << proc.burst << "\t"
             << proc.start << "\t" << proc.finish << "\t" << proc.waiting << "\t"
             << proc.turnaround << "\t\t" << proc.response << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_waiting / n << endl;
    cout << "Average Turnaround Time: " << total_turnaround / n << endl;
    cout << "Average Response Time: " << total_response / n << endl;

    cout << "\nGantt Chart:\n";
    for (const auto &entry : gantt_chart) {
        int start, pid, end;
        tie(start,end ,pid) = entry;
        cout << "|" << start << "--P" << pid << "--" << end << "|";
    }
    return 0;
}