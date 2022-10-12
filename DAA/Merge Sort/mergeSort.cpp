#include<iostream>
using namespace std;

void dispArray(int lenArr, int arr[]){
    for(int i=1; i<=lenArr; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int left,int mid,int right,int arr[]){
    int lenSubArr1 = mid -left + 1;
    int lenSubArr2 = right - mid;

    int *subArr1 = new int[lenSubArr1];
    int *subArr2 = new int[lenSubArr2];

    for(int i =0; i<lenSubArr1; i++){
        subArr1[i] = arr[left+i];
    }

    for(int j =0; j<lenSubArr2; j++){
        subArr2[j] = arr[mid+j+1];
    } 

    int index1=0;
    int index2=0;
    int mainIndex = left;

    while(index1 < lenSubArr1 && index2<lenSubArr2){
        if(subArr1[index1] < subArr2[index2]){
            arr[mainIndex] = subArr1[index1];
            index1++;
        }
        else{
            arr[mainIndex] = subArr2[index2];
            index2++;     
        }
        mainIndex++;
    }

    while(index1 < lenSubArr1){
        arr[mainIndex] = subArr1[index1];
        index1++;
        mainIndex++;
    }

    while(index2 < lenSubArr2){
        arr[mainIndex] = subArr2[index2];
        index2++;
        mainIndex++;
    }
}

void sort(int left,int right,int arr[]){
    if(left < right){
        int mid = (left + right)/2;
        sort(left,mid,arr);
        sort(mid+1,right,arr);
        merge(left,mid,right,arr);
    }
}



int main(){
    int lenArr;
    cout<<"Enter Array Length: ";
    cin>>lenArr;

    int *arr = new int[lenArr+1];

    
    for(int i=1; i<=lenArr; i++){
        cout<<"Enter values: ";
        cin>>arr[i];
    }

    cout<<endl;
    cout<<"Array Before: ";
    dispArray(lenArr,arr);

    sort(1,lenArr,arr);

    cout<<"Array After: ";
    dispArray(lenArr,arr);

}