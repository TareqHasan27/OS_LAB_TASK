#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
    int response;
    bool started;
};

int main() {
    int n;
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i].arrival >> p[i].burst >> p[i].priority;
        p[i].pid = i + 1;
        p[i].remaining = p[i].burst;
        p[i].completion = 0;
        p[i].response = -1;
        p[i].started = false;
    }

    int time = 0, completed = 0;
    double total_waiting = 0, total_turnaround = 0, total_response = 0;
    vector<tuple<int, int, int>> ganttChart; 

    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (p[i].arrival <= time && p[i].remaining > 0) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
                else if (p[i].priority == highest_priority) {
                    if (p[i].arrival < p[idx].arrival) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            if (!p[idx].started) {
                p[idx].response = time - p[idx].arrival;
                p[idx].started = true;
                total_response += p[idx].response;
            }

            p[idx].remaining--;
            ganttChart.push_back({time, p[idx].pid, time + 1});
            time++;

            if (p[idx].remaining == 0) {
                p[idx].completion = time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;

                total_turnaround += p[idx].turnaround;
                total_waiting += p[idx].waiting;
                completed++;
            }
        } else {
            time++;
        }
    }

 


    cout << "\nPID\tArrival\tBurst\tPriority\tCompletion\tWaiting\tTurnaround\tResponse\n";
    for (const auto &proc : p) {
        cout << proc.pid << "\t" << proc.arrival << "\t" << proc.burst << "\t" << proc.priority
             << "\t\t" << proc.completion << "\t\t" << proc.waiting << "\t" << proc.turnaround
             << "\t\t" << proc.response << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_waiting / n << endl;
    cout << "Average Turnaround Time: " << total_turnaround / n << endl;
    cout << "Average Response Time: " << total_response / n << endl;

   
    cout << "\nGantt Chart:\n";
    for (auto &entry : ganttChart)
    {
        int start, pid, end;
        tie(start, pid, end) = entry;
        cout << "|" << start << "--P" << pid << "--" << end;
    }
    cout << "|\n";

    return 0;
}
