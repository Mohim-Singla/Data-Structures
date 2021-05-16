#include <bits/stdc++.h>

using namespace std;

class Graph
{
    map<int, list<int> > mp;
public:
    void inserting(int vertex1, int vertex2)
    {
        mp[vertex1].push_back(vertex2);
        mp[vertex2].push_back(vertex1);
    }
    void bfs(int start)
    {
        queue<int> q;
        map<int, bool> status;
        q.push(start);

        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            status[current]=true;
            cout<<current<<" ";
            for(auto it:mp[current])
            {
                if (!status[it])
                {
                    q.push(it);
                    status[it]=true;
                }

            }
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
    g1.bfs(0);

    return 0;
}
/*
Output:
0 1 2 3 4 5

*/
