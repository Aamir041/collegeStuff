#include<bits/stdc++.h>
using namespace std;

void printMem(int mem[], int n,int top){
    for(int i=0; i<n; i++){
        if(i == top+1){
            cout<<"->"<<mem[i]<<" ";    
        }
        else{
            cout<<mem[i]<<" ";
        }
    }
    cout<<endl;
}

bool isPagePresent(int pageNum, int mem[], int n){
    for(int i = 0; i<n; i++){
        if(mem[i] == pageNum){
            return true;
        }
    }

    return false;
}

int main(){
    int pageFault=0;
    int pageHit=0;
    int n;
    cout<<"\nEnter page frame: ";
    cin>>n;

    int *mem = new int[n];

    for(int i=0; i<n; i++){
        mem[i] = -1;
    }

    int strLen;
    cout<<"\nEnter String Length: ";
    cin>>strLen;
    cout<<endl;

    int *pages = new int[strLen]; 
    for(int i=0; i<strLen; i++){
        cout<<"Enter page number: ";
        cin>>pages[i];
    }
    cout<<endl;

    int top = 0;

    for(int i=0; i<strLen; i++){
        if(!isPagePresent(pages[i],mem,n)){
            pageFault++;
            mem[top] = pages[i];
            printMem(mem,n,top);
            top = (++top)%n;
        }
        else{
            pageHit++;
            cout<<"Page Hit: ";
            printMem(mem,n,top);
        }
    }
    cout<<"\nPage Falut: "<<pageFault<<"\nPage Hit: "<<pageHit<<endl;

}