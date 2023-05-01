#include<bits/stdc++.h>
using namespace std;

bool pageIsNotPresent(int frames[],int n,int pageNum){
    for(int i=0; i<n; i++){
        if(frames[i] == pageNum){
            return false;
        }
    }
    return true;
}

void printFrame(int frames[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << frames[i] << " ";
    }
    cout << endl;
}



int main(){
    int pageFault = 0,pageHit = 0;
    int n;
    cout<<"\nEnter number of frames: ";
    cin>>n;

    int *frames = new int[n];
    for(int i=0; i<n; i++){
        frames[i] = -1;
    }

    int strLen;
    cout<<"\nEnter string length: ";
    cin>>strLen;

    int *pages = new int[strLen];

    for(int i=0; i<strLen; i++){
        cout<<"Enter Page number: ";
        cin>>pages[i];
    }
    // int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    // strLen = sizeof(pages)/sizeof(pages[0]);

    int top = 0;
    for(int i=0; i<strLen; i++){
        if(top > n-1){

            if(pageIsNotPresent(frames,n,pages[i])){

                // creating dynamic 2d array
                int **tempSet = new int*[n];
                
                for(int j= 0; j<n; j++){
                    tempSet[j] = new int[3];
                }

                // intializing array
                for(int j=0; j<n; j++){
                    tempSet[j][0] = frames[j];
                    tempSet[j][1] = j;
                    tempSet[j][2] = INT_MAX;
                }

                // Mapping index number
                for(int k = 0; k<n; k++){
                    for(int j = i+1; j<strLen; j++){
                        if(tempSet[k][0] == pages[j]){
                            tempSet[k][2] = j;
                        }
                    }        
                }

                // sorting tempset
                for(int j = 0; j<n; j++){
                    for(int k = j+1; k<n; k++){
                        if(tempSet[j][2] > tempSet[k][2]){
                            int tempPageNum = tempSet[j][0];
                            int tempFrameIndex = tempSet[j][1];
                            int tempRefIndex = tempSet[j][2];

                            tempSet[j][0] = tempSet[k][0] ;
                            tempSet[j][1] = tempSet[k][1] ;
                            tempSet[j][2] = tempSet[k][2] ;

                            tempSet[k][0] = tempPageNum ;
                            tempSet[k][1] = tempFrameIndex;
                            tempSet[k][2] = tempRefIndex;

                        }
                    }
                }

                int index = tempSet[n-1][1];
                frames[index] = pages[i];
                pageFault++;

            }
            else{
                pageHit++;
            }
            

        }
        else{
            if(pageIsNotPresent(frames,n,pages[i])){
                frames[top++] = pages[i];
                pageFault++;
            }
            else{
                pageHit++;
            }
            
        }
        printFrame(frames,n);
    }
    cout<<"Page Fault: "<<pageFault<<endl;
    cout<<"Page Hit: "<<pageHit<<endl;
}