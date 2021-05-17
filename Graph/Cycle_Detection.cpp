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
    bool cycle_detection(int start, int par)
    {
        if (status[start])
        {
            return true;
        }
        status[start]=true;
        bool ans=false;
        for (auto it:mp[start])
        {
            if (it!=par)
            {
                ans=cycle_detection(it, start);
                if (ans)
                {
                    return true;
                }
            }
        }

        return ans;

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
    bool ans=g1.cycle_detection(0, -1);
    if (ans)
    {
        cout<<"Cycle Detected."<<endl;
    }
    else{
            cout<<"No Cycle Detected."<<endl;
    }
    Graph g2;
    g2.inserting(0,1);
    g2.inserting(0,2);
    g2.inserting(1,3);
    g2.inserting(2,5);
    g2.inserting(1,4);
    ans=g2.cycle_detection(0, -1);
    if (ans)
    {
        cout<<"Cycle Detected."<<endl;
    }
    else{
            cout<<"No Cycle Detected."<<endl;
    }

    return 0;
}
/*
Input 1:
0 -> 1, 2
1 -> 0, 3, 4
2 -> 0, 5
3 -> 1, 4, 5
4 -> 1, 3, 5
5 -> 2, 3, 4
Output 1: Cycle Detected.

Input 2:
0 -> 1, 2
1 -> 0, 3, 4
2 -> 5
3 -> 1
4 -> 1
5 -> 2
Output 2: No Cycle Detected.

*/
