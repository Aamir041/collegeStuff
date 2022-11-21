#include <iostream>
using namespace std;

#define V 10

int minKey(int key[], bool mstSet[],int numVertex)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < numVertex; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[V][V],int numVertex)
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < numVertex; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V],int numVertex)
{
	int parent[numVertex];

	int key[numVertex];

	bool mstSet[numVertex];

	for (int i = 0; i < numVertex; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1; 

	for (int count = 0; count < numVertex - 1; count++) {
		int u = minKey(key, mstSet,numVertex);

		mstSet[u] = true;

		for (int v = 0; v < numVertex; v++)

			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	
	printMST(parent, graph,numVertex);
}

void adjMatrix(int graph[V][V],int numVertex, int numEdge){

    for(int i=0; i<numVertex; i++){
        for(int j=0; j<numVertex; j++){
            graph[i][j] = 0;
        }
    }
    int src,dst,wght;
    for(int i=0; i<numEdge; i++){
        cout<<"Enter source: ";
        cin>>src;
        cout<<"Enter Destination: ";
        cin>>dst;
        cout<<"Enter Weight: ";
        cin>>wght;
        graph[src][dst] = wght;
        graph[dst][src] = wght;
        cout<<endl;
    }
}


int main()
{
    int numVertex;
    int numEdge;
    cout<<"Enter number of vertices: ";
    cin>>numVertex;

    cout<<"Enter number of edges: ";
    cin>>numEdge;

	int graph[V][V];
    
    cout<<endl;

    adjMatrix(graph,numVertex,numEdge);

	
	primMST(graph,numVertex);

	return 0;
}

