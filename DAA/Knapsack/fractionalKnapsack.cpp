#include <bits/stdc++.h>
using namespace std;

class Item {
   public: 
	int value, weight;
};

bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int N)
{
	sort(arr, arr + N, cmp);

	double finalvalue = 0.0;

	for (int i = 0; i < N; i++) {

		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].value;
		}

		else {
			finalvalue
				+= arr[i].value
				* ((double)W / (double)arr[i].weight);
			break;
		}
	}

	return finalvalue;
}

int main()
{
    int W,N;
    cout<<"Enter Maximum Weight: ";
    cin>>W;
	cout<<endl;
    cout<<"Enter Number of Objects: ";
    cin>>N;
	cout<<endl;
   Item *arr = new Item[N];
   for(int i=0; i<N; i++){
	cout<<"Enter Weight of object "<<i+1<<" : ";
	cin>>arr[i].weight;
	cout<<"Enter Value of object "<<i+1<<" : ";
	cin>>arr[i].value;
	cout<<endl;
   }

	cout << fractionalKnapsack(W, arr, N);
	return 0;
}
