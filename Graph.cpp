#include<iostream>
#include<list>
using namespace std;

class graph{
    public:
    list<int> *adjlist;
    int number;
    graph(int num){
        adjlist = new list<int>[num];
        this->number = num;
    }
    void addEdge(int front,int Back,bool val)
    {
        this->adjlist[front].push_back(Back);
        if(val)
        {
            adjlist[Back].push_back(front);
        }
    }
    void print()
    {
        for(int i = 0;i < number; i++)
        {
            cout<<i<<"-->";
            for(auto it:adjlist[i])
            {
                cout<<it<<" ";
            }
            cout<<endl;

        }
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

    g.print();
}