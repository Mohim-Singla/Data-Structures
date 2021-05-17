#include <bits/stdc++.h>

using namespace std;

class Graph
{
    map<int, list<int> > mp;
    map<int, int> distance;
public:
    void inserting(int vertex1, int vertex2)
    {
        mp[vertex1].push_back(vertex2);
        mp[vertex2].push_back(vertex1);
    }
    void dist_bfs(int start)
    {
        queue<int> q;
        map<int, bool> status;
        q.push(start);

        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            status[current]=true;
            for(auto it:mp[current])
            {
                if (!status[it])
                {
                    distance[it]=distance[current]+1;
                    q.push(it);
                    status[it]=true;
                }

            }
        }
        for (auto i:distance)
        {
            cout<<"Shortest distance from "<<start<<" to ";
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
};

int main()
{
    Graph g1;
    g1.inserting(0,1);
    g1.inserting(0,2);
    g1.inserting(1,3);
    g1.inserting(2,5);
    g1.inserting(3,5);
    g1.inserting(1,4);
    g1.inserting(4,5);
    g1.inserting(4,3);
    g1.dist_bfs(0);

    return 0;
}
/*
Output:
Shortest distance from 0 to 0 0
Shortest distance from 0 to 1 1
Shortest distance from 0 to 2 1
Shortest distance from 0 to 3 2
Shortest distance from 0 to 4 2
Shortest distance from 0 to 5 2
*/
