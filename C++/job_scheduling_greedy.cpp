#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int JobNo;
    int profit;
    int deadline;
};

bool compareJob(Job j1, Job j2)
{
    if (j1.profit > j2.profit)
        return true;
    return false;
}

int maxDeadline(int n, Job jobs[])
{
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++)
    {
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    }
    return max;
}

struct ans
{
    int totalProfit;
    vector<int> sequence;
};

ans jobScheduling(int n, Job jobs[])
{
    int maxDL = maxDeadline(n, jobs);
    int totalProfit = 0;
    vector<int> jobNo(maxDL+1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline; j > 0; j--)
        {
            if (jobNo[j] == 0)
            {
                jobNo[j] = jobs[i].JobNo;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    ans a;
    a.sequence = jobNo;
    a.totalProfit = totalProfit;
    return a;
}

int main()
{
    int n;
    cout << "Enter No. Jobs : ";
    cin >> n;
    Job jobs[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter deadline and profit for job " << i + 1 << " : ";
        cin >> jobs[i].deadline >> jobs[i].profit;
        jobs[i].JobNo = i + 1;
    }
    
    sort(jobs, jobs + n, compareJob);
    
    ans an = jobScheduling(n, jobs);
    cout << "Total Profit : " << an.totalProfit;
    cout << "\nJob Sequence : ";
    for (int i = 1; i < an.sequence.size(); i++)
    {
        cout << an.sequence[i] << " ";
    }
    cout << "\n";
    return 0;
}
