#include<iostream>
using namespace std;

class items{
    public:
    float weight;
    float profit;
    float pftBywt;
    items(){
        this->weight = weight;
        this->profit = profit;
        this->pftBywt = pftBywt;
    }
};

void insertDetails(items objArr[],int sizeObjArr){
    cout<<endl;
    for(int i = 1; i<=sizeObjArr; i++){
        cout<<"Enter Weight: ";
        cin>>objArr[i].weight;
        cout<<"Enter Profit: ";
        cin>>objArr[i].profit;
        cout<<endl;
    }
}

void putPftByWt(items objArr[],int len){
    for(int i=1; i<=len; i++){
        objArr[i].pftBywt = objArr[i].profit/objArr[i].weight;
    }
    cout<<endl;
}

// void printPftByWt(items objArr[],int len){
//     for(int i=1; i<=len; i++){
//         cout<<objArr[i].pftBywt<<endl;
//     }
//     cout<<endl;
// }

void sortObjArr(items objArr[],int len){
    items temp;
    for(int i =1; i<len; i++){
        if(objArr[i].pftBywt > objArr[i+1].pftBywt){
            temp = objArr[i];
            objArr[i] = objArr[i+1];
            objArr[i+1] = temp;
        }
    }
}

void selObjs(items objArr[],int len,float maxWeight, int putIndexes[]){
    int j = 0;

    for(int i=1; i<=len; i++){
        putIndexes[i] = 0;
    }

    for(int i=len; i>=1; i--){
        if( maxWeight-objArr[i].weight > 0){
            maxWeight = maxWeight-objArr[i].weight;
            putIndexes[j] = i;
            j++;
        }
        else if(maxWeight-objArr[i].weight == 0){
            maxWeight = maxWeight-objArr[i].weight;
            putIndexes[j] = i;
            j++;
        }
    }
}

int main() {
    int len;
    float maxWeight;
    int *putIndexes = new int[len+1];

    cout<<"Enter Max Weight: ";
    cin>>maxWeight;

    cout<<"Enter number of Objects: ";
    cin>>len;

    items *objArr = new items[len+1];

    insertDetails(objArr,len);
    
    putPftByWt(objArr,len);

    sortObjArr(objArr,len);


    selObjs(objArr,len,maxWeight,putIndexes);

    int i=0;
    while(putIndexes[i]!=0){
        cout<<"Weight: "<<objArr[putIndexes[i]].weight<<" Profit: "<<objArr[putIndexes[i]].profit<<endl;;
        i++;
    }
    cout<<endl;

}