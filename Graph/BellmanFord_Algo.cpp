#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int source;
    int destination;
    int weight;
};

void bellmanFordAlgo(vector<Edge> &edge, int v, int e)
{
    int parent[v];
    int cost[v];
    vector<int> min_dist(v, INT_MAX);
    parent[0]=-1;
    min_dist[0]=0;

    int flag=0;
    for (int i=0;i<v-1;i++)
    {
        flag=0;
        for (int j=0;j<e;j++)
        {
            if (min_dist[edge[j].source]!=INT_MAX && min_dist[edge[j].source] + edge[j].weight < min_dist[edge[j].destination])
            {
                flag=1;
                min_dist[edge[j].destination] = min_dist[edge[j].source]+edge[j].weight;
				parent[edge[j].destination] = edge[j].source;
				cost[edge[j].destination] = min_dist[edge[j].destination];
            }
        }
        if (flag==0)
        {
            break;
        }
    }
    if (flag)
    {
        for (int j=0;j<e;j++)
        {
            if (min_dist[edge[j].source]!=INT_MAX && min_dist[edge[j].source] + edge[j].weight < min_dist[edge[j].destination])
            {
                cout<<"Negative cycle detected.";
                return;
            }
        }
    }

    for(int i=1;i<v;i++)
    {
		cout<<"source->destination: "<<parent[i]<<"->"<<i<<" and Cost to reach "<<parent[i]<<"from source 0 = "<<min_dist[i]<<"\n";
    }
    return;
}

int main()
{
    int v, e;
    cout<<"Enter number of vertex and edges: ";
    cin>>v>>e;
    vector<Edge> edge(e);
    for (int i=0;i<e;i++)
    {
        cout<<"Enter source, destination and weight: ";
        cin>>edge[i].source>>edge[i].destination>>edge[i].weight;
    }

    bellmanFordAlgo(edge, v, e);

}
/*
Sample Input 1:
Enter number of vertex and edges: 5 10
Enter source, destination and weight: 0 1 6
Enter source, destination and weight: 0 2 7
Enter source, destination and weight: 1 2 8
Enter source, destination and weight: 1 4 5
Enter source, destination and weight: 1 3 -4
Enter source, destination and weight: 2 4 -3
Enter source, destination and weight: 2 3 9
Enter source, destination and weight: 3 4 7
Enter source, destination and weight: 3 0 2
Enter source, destination and weight: 4 1 -2

Output:
source->destination: 4->1 and Cost to reach 4from source 0 = 2
source->destination: 0->2 and Cost to reach 0from source 0 = 7
source->destination: 1->3 and Cost to reach 1from source 0 = -2
source->destination: 2->4 and Cost to reach 2from source 0 = 4


Sample Input 2:
Enter number of vertex and edges: 2 2

Output:
Enter source, destination and weight: 0 1 -2
Enter source, destination and weight: 1 0 -2
Negative cycle detected.
*/
