#include <bits/stdc++.h>

using namespace std;

class Graph
{
    map<int, list<int> > mp;
    map<int, bool> status;

public:
    void inserting(int vertex1, int vertex2)
    {
        mp[vertex1].push_back(vertex2);
        mp[vertex2].push_back(vertex1);
    }
    void dfs(int start)
    {
        cout<<start<<" ";
        status[start]=true;
        for (auto i:mp[start])
        {
            if (!status[i])
            {
                dfs(i);
            }
        }
        return;
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
    g1.dfs(0);

    return 0;
}
/*
Output:
0 1 3 5 2 4

*/
