#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
    int response;
    bool started;
};

int main()
{
    int n, quantum;
    cin >> n;
    vector<Process> processes(n);
    int completed = 0;
    for (int i = 0; i < n; ++i)
    {
        processes[i].pid = i + 1;
        cin >> processes[i].arrival >> processes[i].burst;
        processes[i].remaining = processes[i].burst;
        processes[i].completion = 0;
        processes[i].waiting = 0;
        processes[i].turnaround = 0;
        processes[i].response = -1; 
        processes[i].started = false;

        if (processes[i].burst == 0)
        {
            processes[i].completion = processes[i].arrival;
            processes[i].turnaround = 0;
            processes[i].waiting = 0;
            processes[i].response = 0;
            processes[i].remaining = 0;
            processes[i].started = true;
            completed++; 
        }
    }

    cin >> quantum;

    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         { return a.arrival < b.arrival; });

    queue<int> q;
    int time = processes[0].arrival;
    double total_waiting = 0, total_turnaround = 0, total_response = 0;
    vector<bool> inQueue(n, false);

    vector<tuple<int, int, int>> gantt_chart; 

    q.push(0);
    inQueue[0] = true;

    while (completed < n)
    {
        if (q.empty())
        {
            for (int i = 0; i < n; ++i)
            {
                if (processes[i].remaining > 0)
                {
                    time = processes[i].arrival;
                    q.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
        }

        int idx = q.front();
        q.pop();

        int start_time = time;
        int exec_time = min(quantum, processes[idx].remaining);
        time += exec_time;
        int end_time = time;

      
        gantt_chart.push_back({start_time, processes[idx].pid, end_time});

      
        if (!processes[idx].started)
        {
            processes[idx].response = start_time - processes[idx].arrival;
            processes[idx].started = true;
        }

        processes[idx].remaining -= exec_time;

        
        for (int i = 0; i < n; ++i)
        {
            if (!inQueue[i] && processes[i].arrival <= time && processes[i].remaining > 0)
            {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (processes[idx].remaining == 0)
        {
            processes[idx].completion = time;
            processes[idx].turnaround = processes[idx].completion - processes[idx].arrival;
            processes[idx].waiting = processes[idx].turnaround - processes[idx].burst;
            total_waiting += processes[idx].waiting;
            total_turnaround += processes[idx].turnaround;
            total_response += processes[idx].response;
            completed++;
        }
        else
        {
            q.push(idx); 
        }
    }

   
    cout << "\nPID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\tResponse\n";
    for (const auto &p : processes)
    {
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.completion << "\t\t" << p.waiting << "\t" << p.turnaround
             << "\t\t" << p.response << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_waiting / n << endl;
    cout << "Average Turnaround Time: " << total_turnaround / n << endl;
    cout << "Average Response Time: " << total_response / n << endl;

   
    cout << "\nGantt Chart:\n";
    for (auto &entry : gantt_chart)
    {
        int start, pid, end;
        tie(start, pid, end) = entry;
        cout << "|" << start << "--P" << pid << "--" << end;
    }
    cout << "|\n";

    return 0;
}
