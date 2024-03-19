/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
struct Process{
    string name;
    int burstTime;
    int WaitingTime;
    int turnaroundTime;
};
int main(){
    int numProcesses;
    cout<<"Enter the number of process:";
    cin>>numProcesses;
    
    vector<Process>processes(numProcesses);
    
    for(int i=0;i<numProcesses;i++){
        cout<<"Enter burst time for process"<<(i+1)<<":";
        cin>>processes[i].burstTime;
        processes[i].name="P"+to_string(i+1);
          processes[i].WaitingTime=0;
            processes[i].turnaroundTime=0;
            
    }
    for(int i=1;i<numProcesses;i++){
          processes[i].WaitingTime=  processes[i-1].WaitingTime+  processes[i-1].burstTime;
           processes[i].turnaroundTime=  processes[i].WaitingTime+  processes[i-1].burstTime;
    }
   double avgwaitingTime=0,avgturnaroundTime=0;
   for(Process&process:processes){
       avgwaitingTime+=process.WaitingTime;
       avgturnaroundTime+=process.turnaroundTime;
      
   }
   avgwaitingTime/=numProcesses;
   avgturnaroundTime/=numProcesses;
   cout<<avgwaitingTime<<"avgwaitngTime"<<endl;
     cout<<avgturnaroundTime<<"avgturnaroundTime"<<endl;
}

