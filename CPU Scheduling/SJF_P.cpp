// Shortest Job First (SJF) Scheduling Algorithm
/*
Sample Input:
4
0 8
1 4
2 0
3 2

Sample Output:
PID	Arrival	Burst	Completion	Waiting	Turnaround	Response
1	0	8	12	4	12	0
2	1	4	5	0	4	0
3	2	0	2	0	0	0
4	3	2	7	2	4	0

Average Waiting Time: 1.50
Average Turnaround Time: 5.00
Average Response Time: 0.00
*/
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
};

int main()
{
    int n;
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].arrival >> p[i].burst;
        p[i].pid = i + 1;
        p[i].remaining = p[i].burst;
        p[i].completion = 0;
        p[i].response = -1; 
    }

    int completed = 0, time = 0;
    double total_waiting = 0, total_turnaround = 0, total_response = 0;
    vector<bool> is_completed(n, false);

    sort(p.begin(), p.end(), [](const Process &a, const Process &b)
         {
        if (a.arrival == b.arrival)
            return a.burst < b.burst;
        return a.arrival < b.arrival; });

    vector<tuple<int, int, int>> gantt_chart; 

    while (completed != n)
    {
        int idx = -1;
        int mn = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (p[i].arrival <= time && !is_completed[i] && p[i].remaining > 0)
            {
                if (p[i].remaining < mn)
                {
                    mn = p[i].remaining;
                    idx = i;
                }
            }
        }

        if (idx != -1)
        {
            if (p[idx].response == -1)
            {
                p[idx].response = time - p[idx].arrival;
                total_response += p[idx].response;
            }

            p[idx].remaining--;
            time++;
            gantt_chart.push_back({time - 1, p[idx].pid, time});

            if (p[idx].remaining == 0)
            {
                p[idx].completion = time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
                is_completed[idx] = true;
                total_waiting += p[idx].waiting;
                total_turnaround += p[idx].turnaround;
                completed++;
            }
        }
        else
        {
            bool found_zero = false;
            for (int i = 0; i < n; ++i)
            {
                if (p[i].arrival <= time && !is_completed[i] && p[i].remaining == 0)
                {
                    p[i].completion = time;
                    p[i].turnaround = p[i].completion - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    is_completed[i] = true;
                    total_waiting += p[i].waiting;
                    total_turnaround += p[i].turnaround;
                    completed++;
                    found_zero = true;
                    break;
                }
            }
            if (!found_zero)
                time++;
        }
    }
    
    cout << "\nPID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\tResponse\n";
    for (const auto &proc : p)
    {
        cout << proc.pid << "\t" << proc.arrival << "\t" << proc.burst << "\t"
             << proc.completion << "\t\t" << proc.waiting << "\t" << proc.turnaround
             << "\t\t" << proc.response << "\n";
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