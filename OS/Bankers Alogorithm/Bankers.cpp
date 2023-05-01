#include<bits/stdc++.h>
using namespace std;

bool allNotComplete(bool complete[],int np){
    for(int i=0; i<np; i++){
        if(complete[i] == false){
            return true;
        }
    }
    return false;
}

bool canRun(vector<int>need,vector<int> available){
    for(int i=0; i<need.size(); i++){
        if(need[i] > available[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int np,nr;
    cout<<"Enter number of process: ";
    cin>>np;

    cout<<"Enter number of resources: ";
    cin>>nr;

    bool *completed = new bool[np];
    vector<int> order(np,0);
    // vector<vector<int>> allocated(np,vector<int>(nr,0));
    // vector<vector<int>> max(np,vector<int>(nr,0));
    // vector<vector<int>> need(np,vector<int>(nr,0));
    // vector<int> available(nr,0);

    vector<vector<int>> allocated { { 0, 1, 0 }, 
                        { 2, 0, 0 },
                        { 3, 0, 2 },
                        { 2, 1, 1 },
                        { 0, 0, 2 } } ;

    vector<vector<int>> max { { 7, 5, 3 }, // P0    // MAX Matrix
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } };;
    vector<vector<int>> need(np,vector<int>(nr,0));
    vector<int> available{ 3, 3, 2 };

    // for(int i=0; i<np; i++){
    //     for(int j=0; j<nr; j++){
    //         cout<<"Allocate Resource "<<j<<" for Process "<<i<<" : ";
    //         cin>>allocated[i][j];
    //     }
    //     cout<<endl;
    // }
    

    // for(int i=0; i<np; i++){
    //     for(int j=0; j<nr; j++){
    //         cout<<"Max Resource "<<j<<" for Process "<<i<<" : ";
    //         cin>>max[i][j];
    //     }
    //     cout<<endl;
    // }

    for(int i=0; i<np; i++){
        for(int j=0; j<nr; j++){
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    // for(int i=0; i<nr; i++){
    //     cout<<"Enter Available for Resource "<<i<<" : ";
    //     cin>>available[i];
    // }
    // cout<<endl;

    for(int i=0; i<np; i++){
        completed[i] = false;
    }

    int index = 0;
    int order_index = 0;

    while(allNotComplete(completed,np)){
        
        if(canRun(need[index],available) && completed[index]==false){
            
            completed[index] = true;
            order[order_index++] = index;
            for(int i=0; i<nr; i++){
                available[i] += allocated[index][i];
            }
        }
        index = (++index)%np;
    }

    for(int i=0; i<np; i++){
        cout<<order[i]<<" ";
    }
    cout<<endl;

    

}