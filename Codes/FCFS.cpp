#include<bits/stdc++.h>
using namespace std;
int main(){
    int processes[]  = {1, 2, 3, 4};
    int n = sizeof processes / sizeof processes[0];
    vector<pair<int, int> > t(4);
    cout << "Enter Arrival time and Burst time: " << endl;
    for(int i = 0; i < n; i++){
        cin >> t[i].first >> t[i].second;
    }
    cout << "Arrival time: ";
    for(int i = 0; i < 4; i++){
        cout << t[i].first << " ";
    }
    cout << endl << "Burst time: ";
    for(int i = 0; i < 4; i++){
        cout << t[i].second << " ";
    }
    cout << endl;
    sort(t.begin(), t.end());
    int CT[4], TAT[4], WT[4], avg_wt, avg_tat;
    //completion time
    CT[0] = t[0].first + t[0].second;
    
    for(int i = 1; i < 4; i++){
        CT[i] = CT[i-1] + t[i].second;
    }
    cout << "Completion time according to arrival time: ";
    for(int i = 0; i < 4; i++){
        cout << CT[i] << " ";
    }
    cout << endl;
    
    //Waiting time
    int sum = 0;
    cout << "Waiting time: ";
    for(int i = 0; i < 4; i++){
        WT[i] = CT[i] - t[i].first - t[i].second;
        cout << WT[i] << " ";
        sum += WT[i];
    }
    cout << endl;
    cout << "Average waiting time: " << sum/4 << endl;
    //TAT
    int turn = 0;
    cout << "Total turnaround time: ";
    for(int i = 0; i < 4; i++){
        TAT[i] = WT[i] + t[i].second;
        cout << TAT[i] << " "; 
        turn += TAT[i];
    }
    cout << endl << "Average turnaround time: " << turn/4 << endl;
    return 0;
}