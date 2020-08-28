
#include<bits/stdc++.h>
using namespace std;

class process
{
public:
    int ID;
    int burstTime;
    int turnAroundTime;
    int waitingTime;

};

class sudhir
{
    public:
    int numberOfProcess;
    process * p;
    sudhir(int n)
    {
        this->numberOfProcess=n;
        this->p=new process[numberOfProcess];
    }

    void initializeProcess();
    void findWaitingTime();
    void findTurnAroundTime();
    double averageWatingTime();
    double averageTurnAroundTime();
    void display();


};

bool comp(process p1,process p2)
         {

             return p1.burstTime<p2.burstTime;
         }

void sudhir::initializeProcess()
{

    for(int i=0;i<numberOfProcess;i++)
    {
        cout<<"Process Number "<<(i+1)<<endl;
        p[i].ID=i+1;
        cout<<"Enter Its Burst Time"<<endl;
        int bt;
        cin>>bt;
        p[i].burstTime=bt;
    }

    // sort process acc. to burst time;

    sort(p,p+numberOfProcess,comp);
}

void sudhir::findWaitingTime()
{
    // waiting time of first process(after sorting acc. to burst time) is zero
    p[0].waitingTime=0;

    for(int i=1;i<numberOfProcess;i++)
    {

        p[i].waitingTime=p[i-1].burstTime+p[i-1].waitingTime;
    }

}

void sudhir::findTurnAroundTime()
{

    for(int i=0;i<numberOfProcess;i++)
    {

        p[i].turnAroundTime=p[i].burstTime+p[i].waitingTime;
    }
}


double sudhir::averageTurnAroundTime()
{
    int ans=0;
    for(int i=0;i<numberOfProcess;i++)
    {

        ans=ans+p[i].turnAroundTime;
    }

    return (double)ans/(double)numberOfProcess;

}


double sudhir::averageWatingTime()
{
    int ans=0;
    for(int i=0;i<numberOfProcess;i++)
    {

        ans=ans+p[i].waitingTime;
    }

    return (double)ans/(double)numberOfProcess;

}

void sudhir::display()
{
    cout<<"PID  BT  WT TAT  "<<endl;
    for(int i=0;i<numberOfProcess;i++)
    {
        cout<<p[i].ID<<"   "<<p[i].burstTime<<"   "<<p[i].waitingTime<<"    "<<p[i].turnAroundTime<<endl;
    }
}
int main()
{
int n;
cout<<"Enter the Number Of Process"<<endl;
cin>>n;
    sudhir pal(n);
    pal.initializeProcess();
    pal.findWaitingTime();
    pal.findTurnAroundTime();
    pal.findTurnAroundTime();
    pal.display();
    cout<<pal.averageTurnAroundTime()<<endl;
    cout<<pal.averageWatingTime()<<endl;


return 0;
}
