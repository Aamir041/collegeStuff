#include<iostream>
using namespace std;

// int min;
// int max;

void minMax(int left, int right, int arr[], int &max, int &min){
    int min1, max1;
    if(left == right){
        max = arr[left];
    }
    else if(left == right -1){
        if(arr[left] < arr[right]){
            min = arr[left];
            max = arr[right];
        }
        else{
            min = arr[right];
            max = arr[left];  
        }
    }
    else{
        int mid = (left+right)/2;
        minMax(left,mid,arr,max,min);
        max1 = max, min1 = min;
        minMax(mid+1,right,arr,max,min);
        if(max1 > max){
            max = max1;
        }
        if(min1 < min){
            min=min1;
        }
    }
}

int main()
{
    cout<<"Enter array length: ";
    int lenArr; cin>>lenArr;
    int *arr = new int[lenArr];
    int min,max;
    for(int i=1; i<=lenArr; i++){
        cout<<"Enter number: "; cin>>arr[i];
    }
    minMax(1,lenArr,arr,max,min);
    cout<<"Maximum: "<<max<<" Minimum: "<<min<<endl;

}