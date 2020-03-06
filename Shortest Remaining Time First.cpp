#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

struct process {

    int process_id ;
    int burst_time ;
    int waiting_time ;
    int arrival_time ;
    int remain_time ;
    int completion_time;

}arr[4];

int process_finish[100];

void waiting_time(struct process a[] , int n){

int remain=0,sum_wait=0,sum_turnaround=0,endTime,smallest;
cout<<"\n\nProcess\tArrival Time\tBurst Time\tWaiting Time Turnaround Time\tCompletion Time\n\n";
int process_f = 0 ;

for(int time=0;remain!=n;time++){

    smallest=99;

    for(int i=0;i<n;i++){

    if( (a[i].arrival_time <= time ) && (a[i].remain_time < a[smallest].remain_time) && (a[i].remain_time > 0) ){

        smallest=i;

        }
    }

a[smallest].remain_time--;

if(a[smallest].remain_time==0){

    process_finish[process_f] = smallest + 1; //to assign a process id to which finished the total job
    process_f++;
    a[smallest].process_id= smallest + 1;
    int tt ;
    remain++;
    endTime = time + 1; //Total completion
    a[smallest].completion_time = endTime;
    tt=endTime-a[smallest].arrival_time;//Calculate the turnaround TIME (completion Time - arrival Time )
    a[smallest].waiting_time=tt-a[smallest].burst_time; //Calculate the Waiting Time

    cout<<"P"<<smallest+1<<"  \t\t"<<a[smallest].arrival_time<<"\t\t"<<a[smallest].burst_time<<"\t\t"<<a[smallest].waiting_time<<"\t"<<tt<<"\t\t"<<a[smallest].completion_time<<endl;

    sum_wait += tt-a[smallest].burst_time; // Sum of Waiting Time
    sum_turnaround +=tt;
}

}

cout<<"\n\nAverage waiting time: "<<sum_wait*1.0/n<<ends<<"ms \nAverage Turn Around Time "<<sum_turnaround*1.0/n<<" ms\n";

}

int main(){

arr[99].remain_time =9999;
int n=4 ; //No of process
int arrival_time[4] = {0, 2, 2, 4};
int burst_time[4] = {3, 4, 2, 3};

cout<<"Process\tArrival Time\t Burst Time\n";

    for (int i=0; i<n ; i++){
        arr[i].process_id=i+1;
        arr[i].burst_time=burst_time[i];
        arr[i].remain_time = arr[i].burst_time;
        arr[i].arrival_time=arrival_time[i];
        cout<< arr[i].process_id<<"\t\t" << arr[i].arrival_time<< "\t\t"<< arr[i].burst_time<<endl;
    }

waiting_time(arr,n);



return 0;

}


