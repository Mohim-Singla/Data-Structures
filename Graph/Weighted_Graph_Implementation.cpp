#include <bits/stdc++.h>
#include <cstring>
#include<unordered_map>

using namespace std;

class Graph
{
    unordered_map <string, list<pair<string, int> > > ump;

public:
    void inserting(string vertex1, string vertex2, bool dir, int weight)
    {
        ump[vertex1].push_back(make_pair(vertex2, weight));

        if (dir==true)
        {
            ump[vertex2].push_back(make_pair(vertex1, weight));
        }
    }
    void print()
    {
        for (auto it: ump)
        {
            string vertex1=it.first;
            cout<<"Start: "<<vertex1<<" to ";
            list<pair<string, int> > temp=it.second;
            for (auto i:temp)
            {
                string vertex2=i.first;
                int weight=i.second;
                cout<<"("<<vertex2<<", "<<weight<<") ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g1;
    g1.inserting("A", "B", true, 10);
    g1.inserting("B", "E", false, 20);
    g1.inserting("E", "D", true, 30);
    g1.inserting("D", "B", false, 10);
    g1.inserting("C", "D", true, 25);
    g1.inserting("A", "C", true, 50);
    g1.print();

    return 0;
}
/*

Output:

Start: C to (D, 25) (A, 50)
Start: D to (E, 30) (B, 10) (C, 25)
Start: A to (B, 10) (C, 50)
Start: B to (A, 10) (E, 20)
Start: E to (D, 30)

*/
