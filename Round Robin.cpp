#include<iostream>
#include<conio.h>
using namespace std;


int arrival_time[5], burst_time[5], completion_time[5]={0}, time_quant, rqi[5]={0}, c=0, st, flg=0, tm=0, j=0, pnt=0, btm[5]={0}, turn_around_time, waiting_time;
float avg_turnaround_time, avg_waiting_time;

void SearchStack01(int pnt,int tm){
    for(int i=pnt+1;i<5;i++){
        if(arrival_time[i]<=tm){
            rqi[j]=i+1;
            j++;
            }
    }
}
void SearchStack02(int pnt, int tm){
    for(int i=pnt+1;i<5;i++){
    ///Check Queue
        int fl=0;
        for(int y=0;y<j;y++){
            if(rqi[y]==i+1){
            fl++;
            }
        }
        if(arrival_time[i]<=tm && fl==0 && btm[i]!=0){
            rqi[j]=i+1;
            j++;
        }
    }
}
void AddQue(int pnt){
    rqi[j]=pnt+1;
    j++;
}

int main()
{

int arrival_time[5] = {0,1,2,3,4};
int burst_time[5] = {10,4,5,3,3};
for(int i=0;i<5;i++){
    btm[i]=burst_time[i];
}


    time_quant=2;
    cout<< "Time Quant: "<<time_quant<<endl;


do{
    if(flg==0){
        st=arrival_time[0];
        ///Reduce Burst Time
        if(btm[0]<=time_quant){
            tm=st+btm[0];
            btm[0]=0;
            SearchStack01(pnt,tm);
        }
        else{
            btm[0]=btm[0]-time_quant;
            tm=st+time_quant;
            SearchStack01(pnt,tm);
            AddQue(pnt);
        }
    }
    else{
        pnt=rqi[0]-1;
        st=tm;    ///Delete Queue

    for(int i=0;i<j && j!=1;i++){
        rqi[i]=rqi[i+1];
    }
    j--;///Reduce Burst Time

    if(btm[pnt]<=time_quant){
        tm=st+btm[pnt];
        btm[pnt]=0;
        SearchStack02(pnt, tm);
    }
    else{
        btm[pnt]=btm[pnt]-time_quant;
        tm=st+time_quant;
        SearchStack02(pnt, tm);
        AddQue(pnt);
        }
    }

    //Calculate Completion Time
    if(btm[pnt]==0){
        completion_time[pnt]=tm;
    }
    flg++;
cout<<"-P"<<pnt+1;
}while(j!=0);


cout<<"\n\nProcess\t Arrival Time\t Burst Time\t Completion Time  Turnaround Time\t Waiting Time\n";
for(int i=0;i<5;i++){
    turn_around_time=completion_time[i]-arrival_time[i];
    waiting_time=turn_around_time-burst_time[i];
    cout<<"P"<<i+1<<" \t\t"<<arrival_time[i]<<" \t\t"<<burst_time[i]<<" \t\t"<<completion_time[i]<<" \t\t"<<turn_around_time<<" \t\t"<<waiting_time<<"\n";
    avg_waiting_time=avg_waiting_time+waiting_time;
    avg_turnaround_time=avg_turnaround_time+turn_around_time;
}
cout<<"\nAverage Turnaround Time: "<<avg_turnaround_time/5<<"\nAverage Waiting Time: "<<avg_waiting_time/5;
return 0;
}

