#include<algorithm>
#include<iostream>
using namespace std;

int intialP = 1;

class fcfs{
public: 
    int pn;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    fcfs(){
        this->pn = intialP;
        intialP++;
    }

};

bool comp(const fcfs o1 , const fcfs o2){
    if(o1.at == o2.at){
        return o1.bt <o2.bt;
    }
    return o1.at < o2.at;
}

void calculate(fcfs processes[]){
    int prev;
    if(processes[0].at != 0){
        prev =  processes[0].at; 
    }
    else{
        prev = 0; 
    }
    
    
    for(int i=0; i<4; i++){
        processes[i].ct = processes[i].bt + prev;
        prev = processes[i].ct;
    }

    for(int i = 0; i<4; i++){
        processes[i].tat = processes[i].ct - processes[i].at;
    }

    for(int i = 0; i<4; i++){
        processes[i].wt = processes[i].tat - processes[i].bt;
    }

}


int main(){
    
    fcfs processes[4];
    for(int i=0; i<4; i++){
        cout<<"Enter Process "<<i+1<<" AT: ";
        cin>>processes[i].at;

        cout<<"Enter Process "<<i+1<<" BT: ";
        cin>>processes[i].bt;
        cout<<endl;
    }
    
    cout<<endl;
   
    for(int i=0; i<4; i++){
        cout<<processes[i].pn<<"  "<<processes[i].at<<"  "<<processes[i].bt<<endl;
    }

    sort(begin(processes), end(processes), comp);

    calculate(processes);

    cout<<endl;

    for(int i=0; i<4; i++){
        cout<<"pn: "<<processes[i].pn<<" at: "<<"  "<<processes[i].at<<"  "<<" bt: "<<processes[i].bt<<"  "<<" ct: "<<processes[i].ct<<"  "<<" tat: "<<processes[i].tat<<"  "<<" wt: "<<processes[i].wt<<endl;
    }

}
