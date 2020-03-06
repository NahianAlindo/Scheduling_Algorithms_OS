///SJF tt=bt+wt
///ct= at + tt
///wt = st - at
#include<iostream>
#include<algorithm>
using namespace std;
struct Process{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int service_time;
    int completion_time;
    int turn_around_time;
};


bool cmp(Process p1, Process p2){

    if(p1.burst_time<p2.burst_time) return p1.burst_time<p2.burst_time;
    else if(p1.burst_time == p2.burst_time && p1.arrival_time<p2.arrival_time)
        return p1.arrival_time<p2.arrival_time;
    else return false;
}

bool cmpArrival(Process p1, Process p2){

    if(p1.arrival_time<p2.arrival_time) return p1.arrival_time<p2.arrival_time;
    else if(p1.arrival_time == p2.arrival_time && p1.burst_time<p2.burst_time)
        return p1.burst_time<p2.burst_time;
    else return false;
}


void partSort(Process p[], int N, int a, int b)
{
    // Variables to store start and
    // end of the index range
    int l = min(a, b);
    int r = max(a, b);

    // Temporary array
    Process temp[r - l + 1];
    int j = 0;
    for (int i = l; i <= r; i++) {
        temp[j] = p[i];
        j++;
    }

    // Sort the temporary array
    sort(temp, temp + r - l + 1,cmp);

    // Modifying original array with
    // temporary array elements
    j = 0;
    for (int i = l; i <= r; i++) {
            p[i] = temp[j];
            j++;
    }



}

int main(){
Process p[4];
int arrival_time[4] = {0, 2, 2, 4};
int burst_time[4] = {3, 4, 2, 3};
    int service_t[4];
    p[0].service_time = 0;
    p[0].waiting_time = 0;
cout<<"Process ID\tArrival Time\tBurst Time\n";
for(int i = 0 ; i<4;i++){
    p[i].pid = i;
    p[i].arrival_time = arrival_time[i];
    p[i].burst_time = burst_time[i];
    cout<< p[i].pid<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<endl;
}

partSort(p, 4, 1, 3);
//for(int i=0; i<4;i++)cout<<p[i].arrival_time<<ends;
    //determine waiting time
    for(int counter = 1; counter<4; counter++){
        p[counter].service_time = p[counter-1].service_time + p[counter-1].burst_time;
        p[counter].waiting_time = p[counter].service_time - p[counter].arrival_time;
        if(p[counter].waiting_time < 0){
            p[counter].waiting_time = 0;
        }
    }

    //determine turn around time and completion time
    for(int i = 0; i<4; i++){
        p[i].turn_around_time = p[i].burst_time + p[i].waiting_time;
        p[i].completion_time = p[i].arrival_time + p[i].turn_around_time;
    }

    cout<<"Processes\tArrival Time\tBurst Time\tWaiting Time Turn Around Time Completion Time"<<endl;
    for(int i=0;i<4;i++){
        cout<< "P"<<p[i].pid <<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<< p[i].waiting_time
        << "\t\t"<<p[i].turn_around_time<<"\t\t"<<p[i].completion_time<<endl;
    }

    float avg_wt, avg_tt;
    int sum_wt=0, sum_tt =0;
    for(int i=0; i<4;i++){
        sum_wt += p[i].waiting_time;
        sum_tt += p[i].turn_around_time;
    }

    avg_wt = sum_wt/3.0;
    avg_tt = sum_tt/3.0;
    cout<< "Average Waiting Time: "<< avg_wt<<endl;
    cout<< "Average Turn Around Time: "<< avg_tt<<endl;

return 0;
}
