#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Edge{
    public:
    int src;
    int des;
    int wt = -9999;
    Edge(int s,int d)
    {
        this->src = s;
        this->des = d;
    }
    Edge(int s,int d,int w)
    {
        this->src = s;
        this->des = d;
        this->wt = w;
    }
};

class graph{
    public:

    public:
    list<Edge> *adjlist;
    int number;
    graph(int num){
        adjlist = new list<Edge>[num];
        this->number = num;
    }
    // For making 
    void addEdge(int front,int Back,bool val)
    {
        this->adjlist[front].push_back(Edge(front,Back));
        if(val)
        {
            adjlist[Back].push_back(Edge(Back,front));
        }
    }
    void addEdge(int front,int Back,int wet,bool val)
    {
        this->adjlist[front].push_back(Edge(front,Back,wet));
        if(val)
        {
            adjlist[Back].push_back(Edge(Back,front,wet));
        }

    }
    void print()
    {
        for(int i = 0;i < number; i++)
        {
            cout<<i<<"-->";
            for(auto it:adjlist[i])
            {
                cout<<"{"<<it.src<<","<<it.des<<"} ";
                if(it.wt != -9999)
                {
                    cout<<"weight"<<it.wt;
                }
            }

            cout<<endl;

        }
    }

    // Find Center 
    int findCenter(vector<vector<int>>& edges) {
        if(edges.size() != 0)
        {
        for(int i = 0 ; i < edges[0].size(); i++)
        {
            for(int j = 0 ; j < edges[1].size(); j++)
            {
                if(edges[0][i] == edges[1][j])
                {
                    return edges[0][i];
                }
            }
        }
        }
        return 0;
    }
    // Find Judge
    int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> first(N+1,0),second(N+1,0);
    for(int i = 0 ; i < trust.size(); i++)
    {
        first[trust[i][0]]++;
        second[trust[i][1]]++;
    }
    for(int j = 1 ; j <= N ; j++)
    {
        if(first[j] == 0 && second[j] == N-1)
        {
            return j;
        }
    }
    return -1;
    }

};

int main()
{
    graph g(5);
    g.addEdge(1,2,true);
    g.addEdge(4,2,true);
    g.addEdge(1,3,true);
    g.addEdge(4,3,true);
    g.addEdge(1,4,true);
    g.addEdge(1,4,12,true);

    g.print();
}