#include<iostream>
using namespace std;

struct Process{
    int arrival_time;
    int burst_time;
    int waiting_time;
    int service_time;
    int completion_time;
    int turn_around_time;
};

int main(){
    struct Process p[3];
    int arrival_t[3] = {0, 3, 6};
    int service_t[3];
    p[0].service_time = 0;
    p[0].waiting_time = 0;
    int burst_t[3] = {5, 9, 6};

    for(int iter = 0; iter<3; iter++){
        p[iter].arrival_time = arrival_t[iter];
        p[iter].burst_time = burst_t[iter];
    }

    //determine waiting time
    for(int counter = 1; counter<3; counter++){
        p[counter].service_time = p[counter-1].service_time + p[counter-1].burst_time;
        p[counter].waiting_time = p[counter].service_time - p[counter].arrival_time;
        if(p[counter].waiting_time < 0){
            p[counter].waiting_time = 0;
        }
    }

    //determine turn around time and completion time
    for(int i = 0; i<3; i++){
        p[i].turn_around_time = p[i].burst_time + p[i].waiting_time;
        p[i].completion_time = p[i].arrival_time + p[i].turn_around_time;
    }

    cout<<"Processes\tArrival Time\tBurst Time\tWaiting Time Turn Around Time Completion Time"<<endl;
    for(int i=0;i<3;i++){
        cout<< "P"<<i <<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<< p[i].waiting_time
        << "\t\t"<<p[i].turn_around_time<<"\t\t"<<p[i].completion_time<<endl;
    }

    float avg_wt, avg_tt;
    int sum_wt=0, sum_tt =0;
    for(int i=0; i<3;i++){
        sum_wt += p[i].waiting_time;
        sum_tt += p[i].turn_around_time;
    }

    avg_wt = sum_wt/3.0;
    avg_tt = sum_tt/3.0;
    cout<< "Average Waiting Time: "<< avg_wt<<endl;
    cout<< "Average Turn Around Time: "<< avg_tt<<endl;

return 0;
}
