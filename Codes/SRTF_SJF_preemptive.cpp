#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, at[10], bt[10], ct[10], wt[10], temp[10], tat[10], p[10];
    cout << "Enter the number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the at and bt for the process " << i + 1 << ": " << endl;
        cin >> at[i] >> bt[i];
        temp[i] = bt[i];
    }
    int smallest, count = 0, time;
    double avg = 0, tt = 0, end = 0;
    bt[9] = 9999;
    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
            {
                smallest = i;
            }
        }
        bt[smallest]--;
        if (bt[smallest] == 0)
        {
            count++;
            end = time + 1;
            ct[smallest] = end;
            wt[smallest] = end - at[smallest] - temp[smallest];
            tat[smallest] = end - at[smallest];
        }
    }
    printf("at\tbt\tct\ttat\twt\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", at[i], temp[i], ct[i], tat[i], wt[i]);
        tt += tat[i];
        avg += wt[i];
    }
    cout << "The Average Turn Around Time is: " << tt / n << endl;
    cout << "The Average Waiting time is: " << avg / n << endl;
    return 0;
}