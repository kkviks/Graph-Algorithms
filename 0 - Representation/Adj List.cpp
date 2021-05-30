#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[this->V];
    }

    void addEdge(int u,int v){
        //Assuming undirected graph
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList(){
        for(int i=0;i<V;i++){
            cout << i <<" : ";
            for(int x:l[i])cout << x <<", ";
            cout << endl;
        }
    }
};

int main(){

    int n;
    cin >> n;
    
    Graph g(n);

    int e;
    cin >> e;
    
    for(int i=0,u,v;i<e;i++){
        cin >> u >> v;
        g.addEdge(u,v);
    }
    
    g.printAdjList();

    return 0;
}