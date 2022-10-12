#include<iostream>
using namespace std;

void swap(int i, int j, int arr[]){
    int temp;
    temp = arr[j];
    arr[j]=arr[i];
    arr[i]=temp;
}

int partition(int low, int high, int arr[]){
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i < j){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--; // imp see da sign bruh
        }
        if(i<j){
            swap(i,j,arr);
        }
    }
    swap(j,low,arr);
    return j;
}

void quickSort(int low, int high, int arr[]){

    if(high > low){
        int p = partition(low, high, arr);
        quickSort(low,p-1,arr);
        quickSort(p+1,high,arr);
    }
}

void dispArray(int lenArr, int arr[]){
    for(int i=1; i<=lenArr; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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

    quickSort(0,lenArr,arr);

    cout<<"Array After: ";
    dispArray(lenArr,arr);
}