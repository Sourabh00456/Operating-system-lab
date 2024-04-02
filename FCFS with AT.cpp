/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
using namespace std;

struct Process{
    string name;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

int main()
{
    int numProcesses;
    cout<<"enter the no. of processes:";
    cin>>numProcesses;
    
    vector<Process> processes(numProcesses);
    
    for(int i=0;i<numProcesses;i++){
        cout<<"enter nburst time for process:";
        cin>>processes[i].burstTime;
        processes[i].name="P"+ to_string(i+1);
        processes[i].waitingTime=0;
        processes[i].turnaroundTime=0;
    }
    for(int i=1;i<numProcesses;i++){
        processes[i].waitingTime=processes[i-1].waitingTime+processes[i-1].burstTime;
        processes[i].turnaroundTime=processes[i].waitingTime+processes[i-1].burstTime;
    }
    double avgwaitingTime=0,avgturnaroundTime=0;
    for(Process& process : processes){
        avgwaitingTime+=process.waitingTime;
        avgturnaroundTime=process.turnaroundTime;
    }
    avgwaitingTime/=numProcesses;
    avgturnaroundTime/=numProcesses;
    cout<<avgwaitingTime<<"avgwaitingTime"<<endl;
    cout<<avgturnaroundTime<<"avgturnaroundTime"<<endl;
}
   
    
    
}
