#include "Test.h"
#include <iostream>
#include "Edge.h"

using namespace std;

map<int,bool> visitados;

int** _initResultGraph(int size)
{
    int **answer = new int* [size];
    for(int i=0;i<size;i++)
    {
        answer[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            answer[i][j]=-1;
        }
    }
    return answer;
}

bool hasCycle(int** graph, int size, int actual, int father)
{
    if(visitados[actual])
        return true;

    visitados[actual]=true;

    for(int i=0;i<size;i++)
        if(graph[actual][i]!=-1 && i!=father)
            if(hasCycle(graph,size,i,actual))
                return true;

    visitados[actual]=false;

    return false;
}

bool hasCycle(int** graph, int size)
{
    for(int i=0;i<size;i++)
        visitados[i]=false;

    for(int i=0;i<size;i++)
    {
        if(hasCycle(graph,size,i,0))
            return true;
    }

    return false;
}

void print(int ** result, int size)
{
       for(int i =0; i<size;i++)
    {
        for(int j=0; j<size;j++)
        {
            if(result[i][j]!=-1){
                cout<<" ";
            }
            cout<<result[i][j]<<" ";
        }
        cout<<""<<endl;
    }
}

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
    int ** result = _initResultGraph(size);
    for(int i =0; i<edges.size();i++)
    {
        result[edges[i]->source][edges[i]->destination] = edges[i]->weight;
        result[edges[i]->destination][edges[i]->source] = edges[i]->weight;
        cout<<"---------------------------"<<endl;
        print(result,size);
        if(hasCycle(result,size))
        {
           cout<<"cycle"<<endl;
           print(result,size);
           result[edges[i]->source][edges[i]->destination] = -1;
           result[edges[i]->destination][edges[i]->source] = -1;
        }
        else
        {
           cout<<"no cycle"<<endl;
           print(result,size);
        }
    }

    return result;
}

int main ()
{
    test();
    return 0;
}
