#include<iostream>
#include<algorithm>
using namespace std;


class Edge {
    public:
    int source;
    int weight;
    int dest;

};


bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}


int findParent(int v, int *parent){
    if(parent[v] == v){
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskals(Edge *input, int n,int E){
    sort(input, input + E, compare); 
    Edge *output = new Edge[n-1];


    int *parent = new int[n];
    for(int i {0} ; i < n ; i++){
        parent[i] = i;
    }

    int count{},i{};
    while(count != n-1){
        Edge currentEdge = input[i];
        int sourceparent = findParent(currentEdge.source,parent);
        int destinationParent = findParent(currentEdge.dest,parent);

        if(sourceparent != destinationParent){
            output[count] = currentEdge;
            count++;
            parent[sourceparent] = destinationParent;
        }
        i++;
    }


    for(int i{0}; i < n-1; i++){
        if(output[i].source < output[i].dest){
        cout << output[i].source << " "<< output[i].dest << " "<< output[i].weight;
    }else{
        cout << output[i].dest << " "<< output[i].source << " "<< output[i].weight;
    }
    cout <<  endl;
}
}

int main() {
    int n,E;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>E;
    cout<<endl;

    Edge *input = new Edge[E];
    for(int i{0}; i < E; i++){
        int s,d,w;
        cout<<"Enter source: ";
        cin>>s;
        cout<<"Enter destination: ";
        cin>>d;
        cout<<"Enter weight: ";
        cin>>w;
        input[i].source = s;
        input[i].weight = w;
        input[i].dest = d;
        cout<<endl;
    }
    cout<<"MST accroding to kruskals"<<endl;
    kruskals(input,n,E);
}