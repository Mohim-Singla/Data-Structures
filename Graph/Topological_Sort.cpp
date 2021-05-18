#include <bits/stdc++.h>

using namespace std;

class Graph
{
    map<int, list<int> > mp;
    map<int, bool> status;

public:
    void inserting(int start_idx, int end_idx)
    {
        mp[start_idx].push_back(end_idx);
        status[start_idx]=false;
        status[end_idx]=false;
    }

    void topological_sort(int current, stack<int> &topos)
    {
        status[current]=true;

        for (auto it: mp[current])
        {
            if (!status[it])
            {
                topological_sort(it, topos);
            }
        }

        topos.push(current);

    }

    void topo_call(stack<int> &topos)
    {
        for (auto it:mp)
        {
            if (!status[it.first])
            {
                topological_sort(it.first, topos);
            }

        }
    }
    void print(stack<int> &topos)
    {
        cout<<"Topological sort of the given graph is: ";
        while(!topos.empty())
        {
            int temp=topos.top();
            topos.pop();
            cout<<temp<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Graph g1;
    g1.inserting(0,1);
    g1.inserting(0, 3);
    g1.inserting(1, 2);
    g1.inserting(3,2);
    g1.inserting(3,4);
    g1.inserting(4,5);
    g1.inserting(5,2);
    stack<int> topos;
    g1.topo_call(topos);
    g1.print(topos);

}
/*
Output:
Topological sort of the given graph is: 0 3 4 5 1 2
*/
