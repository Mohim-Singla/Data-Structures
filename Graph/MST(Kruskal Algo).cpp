#include <bits/stdc++.h>

using namespace std;

struct node
{
    int parent;
    int ranking;
};

struct edge
{
    int vertex1, vertex2, weight;
};

vector<node> par;
vector<edge> ans;

bool cmp(edge a, edge b)
{
    return a.weight < b.weight;
}

int find(int i)
{
    if (par[i].parent==-1)
    {
        return i;
    }
    par[i].parent=find(par[i].parent);
    return par[i].parent;
}

void union_fun(int v1, int v2)
{
    v1=find(v1);
    v2=find(v2);

    if (par[v1].ranking > par[v2].ranking)
    {
        par[v2].parent=v1;
    }
    else if (par[v2].ranking < par[v1].ranking)
    {
        par[v1].parent=v2;
    }
    else{
        par[v2].parent=v1;
        par[v2].ranking+=1;
    }
}

void kruskal_algo(vector<edge> &vertex, int edges, int vertexes)
{
    sort(vertex.begin(), vertex.end(), cmp);

    int i=0,j=0;
    while(i<vertexes-1 && j<edges)
    {
        int x=find(vertex[j].vertex1);
        int y=find(vertex[j].vertex2);

        if (x==y)
        {
            j++;
            continue;
        }
        union_fun(x, y);
        ans.push_back(vertex[j]);
        i++;
    }
}

void print(vector<edge> &ans)
{
    cout<<"Ans: ";
    for (auto it: ans)
    {
        cout<<it.vertex1<<" "<<it.vertex2<<" "<<it.weight<<endl;
    }
}

int main()
{
    int edges, vertexes;
    cout<<"Enter no. of edges and vertexes: ";
    cin>>edges>>vertexes;
    par.resize(vertexes);
    for (int i=0;i<vertexes;i++)
    {
        par[i].parent=-1;
        par[i].ranking=0;
    }
    vector<edge> vertex;
    for (int i=0;i<edges;i++)
    {
        int vertex1, vertex2, weight;
        cin>>vertex1>>vertex2>>weight;
        edge temp;
        temp.vertex1=vertex1;
        temp.vertex2=vertex2;
        temp.weight=weight;
        vertex.push_back(temp);
    }
    kruskal_algo(vertex, edges, vertexes);
    print(ans);
}
/*

Input:
Enter no. of edges and vertexes: 14
9
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
8 6 6
2 8 2
2 3 7
2 5 4
6 5 2
5 3 14
3 4 9
5 4 10

Output:
Ans: 7 6 1
2 8 2
6 5 2
0 1 4
2 5 4
2 3 7
0 7 8
3 4 9

*/
