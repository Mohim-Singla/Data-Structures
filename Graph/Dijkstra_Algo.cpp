#include <bits/stdc++.h>

using namespace std;

class Graph
{
    map<int, list<pair<int, int> > > mp;
    map<int, int> status;
    map<int, int> min_dist;

public:
    void inserting(int vertex1, int vertex2, int weight)
    {
        mp[vertex1].push_back(make_pair(vertex2, weight));
        mp[vertex2].push_back(make_pair(vertex1, weight));
        min_dist[vertex1]=INT_MAX;
        min_dist[vertex2]=INT_MAX;
    }
    int min_distance()
    {
        int curr_min=INT_MAX;
        for (auto i:min_dist)
        {


            if (status[i.first]==false && i.second<=curr_min)
            {
                curr_min=i.first;
            }
        }
        return curr_min;
    }
    void dijkstra(int start)
    {
        min_dist[start]=0;
        int parent=start;
        int least=start;
        for (int i=0;i<mp.size();i++)
        {

            least=min_distance();
            parent=least;
            status[least]=true;
            for (auto it: mp[least])
            {
                if (it.first!=parent)
                {
                    int temp=min_dist[parent]+it.second;
                    min_dist[it.first]=min(temp, min_dist[it.first]);
                }
            }
        }
    }
    void print()
    {
        for (auto it:min_dist)
        {
            cout<<"Minimum distance from "<<it.first<<" to "<<it.second<<" is "<<endl;
        }
    }
};

int main()
{
    Graph g1;
    g1.inserting(0,1,1);
    g1.inserting(0,3,3);
    g1.inserting(1,3,2);
    g1.inserting(1,2,4);
    g1.inserting(1,4,5);
    g1.inserting(3,2,3);
    g1.inserting(3,4,4);
    g1.inserting(2,4,3);
    g1.inserting(2,5,2);
    g1.inserting(4,5,4);
    g1.dijkstra(0);
    g1.print();
}
