#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int v;
    list<int> *list1;
public:
    Graph(int v)
    {
        this->v=v;
        list1= new list<int>[v];
    }
    void inserting(int vertex1, int vertex2)
    {
        list1[vertex1].push_back(vertex2);
        list1[vertex2].push_back(vertex1);
    }
    void print()
    {
        for (int i=0;i<v;i++)
        {
            cout<<"Vertex: "<<i<<" to ";
            list<int>::iterator it;
            for (it:list1[i])
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }

    }
};

int main()
{
    Graph g1(6);
    g1.inserting(0,1);
    g1.inserting(0,2);
    g1.inserting(1,3);
    g1.inserting(2,5);
    g1.inserting(3,5);
    g1.inserting(1,4);
    g1.inserting(4,5);
    g1.inserting(4,3);
    g1.print();

    return 0;
}
