
/*

First in, first out (FIFO),
also known as first come, first served (FCFS),
is the simplest scheduling algorithm.

Completion Time: Time at which process completes its execution.
=Turn_Around_Time+Arrival_time

Turn Around Time: Time Difference between completion time and arrival time.
Turn Around Time = Completion Time – Arrival Time

Waiting Time(W.T): Time Difference between turn around time and burst time.
Waiting Time = (Turn Around Time – Burst Time)

Burst Time: Time required by a process for CPU execution.

Note:All process have different arrival time.



Service Time : Service time means amount of time after
 which a process can start execution


*/
#include<bits/stdc++.h>

using namespace std;

class process
{
    public:
    int process_number;
    int waiting_time;
    int burst_time;
    int turn_around_time;
    int arrival_time;
    int completion_time;

};

class fcfs
{
    public:
    int number_of_process;
    process* p;
    fcfs(int n)
    {

        number_of_process=n;
       this->p=new process[number_of_process];
    }
    void initilize();
    void find_waiting_time();
    void find_turn_aroundtime();
    double find_average_waiting_time();
    double find_average_turn_around_time();
    void display();


};

void fcfs::initilize()
{
    for(int i=0;i<number_of_process;i++)
    {


        p[i].process_number=i+1;
        cout<<"Enter "<<(i+1)<<" process 's Burst Time "<<endl;
        int bt;
        cin>>bt;
        p[i].burst_time=bt;
        cout<<"Enter "<<(i+1)<<" process 's Arrival Time "<<endl;
        int At;
        cin>>At;
        p[i].arrival_time=At;


    }

}

void fcfs::find_waiting_time()
{
    int service_time[number_of_process];
     service_time[0]=0;

    p[0].waiting_time=0;
    // Waiting time for first process is 0;

    for(int i=1;i<number_of_process;i++)
    {

    service_time[i]=service_time[i-1]+p[i-1].burst_time;
    p[i].waiting_time=service_time[i]-p[i].arrival_time;

        // If waiting time for a process is in negative
        // that means it is already in the ready queue
        // before CPU becomes idle so its waiting time is 0
        if (p[i].waiting_time<0)
            p[i].waiting_time=0;

    }
}

void fcfs::find_turn_aroundtime()
{

    for(int i=0;i<number_of_process;i++)
    {
        p[i].turn_around_time=p[i].burst_time+p[i].waiting_time;
        p[i].completion_time=p[i].turn_around_time+p[i].arrival_time;
    }
}

double fcfs::find_average_waiting_time()
{
    int total=0;
    for(int i=0;i<number_of_process;i++)
    {

        total+=p[i].waiting_time;

    }

    return (double)total/(double)(number_of_process);
}

double fcfs::find_average_turn_around_time()
{
    int total=0;
    for(int i=0;i<number_of_process;i++)
    {

        total+=p[i].turn_around_time;
    }

    return (double)total/(double)(number_of_process);

}

void fcfs::display()
{
    cout<<"Process NO."<<" Burst Time"<<" Waiting Time"<<" Turn Around Time "<<" Completion time"<<endl;
    for(int i=0;i<number_of_process;i++)
    {

        cout<<p[i].process_number<<"              ";
        cout<<p[i].burst_time<<"               ";
        cout<<p[i].waiting_time<<"              ";
        cout<<p[i].turn_around_time<<"         ";
        cout<<p[i].completion_time<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter The Number Of process"<<endl;
    cin>>n;

fcfs pal(n);
pal.initilize();
pal.find_waiting_time();
pal.find_turn_aroundtime();
pal.display();
cout<<"Average waiting time = ";
cout<<pal.find_average_waiting_time()<<endl;
cout<<"Average turn around time = ";
cout<<pal.find_average_turn_around_time()<<endl;




}



