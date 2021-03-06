#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <iterator>
using namespace std;

typedef vector<vector<pair<int,float> > > Graph;//So that the grph can store 2 numbers connected together.
class Comparator
{
public:
 int operator() ( const pair<int,float>& p1, const pair<int,float> &p2)
 {
 return p1.second>p2.second;
 }
};

void dijkstra(const Graph &G,const int &source,const int &destination,vector<int> &path)
{
vector<float> d(G.size());
vector<int> parent(G.size());
for(unsigned int i = 0 ;i < G.size(); i++)
{
 d[i] = std::numeric_limits<float>::max();
 parent[i] = -1;
}
priority_queue<pair<int,float>, vector<pair<int,float> >, Comparator> Q;
d[source] = 0.0f;
Q.push(make_pair(source,d[source]));
while(!Q.empty())
{
 int u = Q.top().first;
 if(u==destination) break;
 Q.pop();
 for(unsigned int i=0; i < G[u].size(); i++)
 {
  int v= G[u][i].first;
  float w = G[u][i].second;
  if(d[v] > d[u]+w)
  {
   d[v] = d[u]+w;
   parent[v] = u;
   Q.push(make_pair(v,d[v]));
  }
 }
}
path.clear();
int p = destination;
path.push_back(destination);
while(p!=source)
{
 p = parent[p];
 path.push_back(p);
}
}

int main()
{
    /* Graph
GRAPH TYPE = UNDIRECTED
NUMBER OF VERTICES = 6 indexed from 0 to 5
NUMBER OF EDGES = 9
edge 0->1 weight = 7
edge 0->2 weight = 9
edge 0->5 weight = 14
edge 1->2 weight = 10
edge 1->3 weight = 15
edge 2->5 weight = 2
edge 2->3 weight = 11
edge 3->4 weight = 6
edge 4->5 weight = 9
*/
    Graph g;
    int node;
    int start;
    int end;
    cout<<"\nPlease Insert the number of nodes..\n";
    cin>>node;
    g.resize(node);
    
    for(int i=0;i<node;i++)
    { int connecting_node;
      int weight;
      int connections;

      cout<<"\nEnter details for node "<<i+1;
      cout<<"\nHow many connections does it have: ";
      cin>>connections;
      for(int j=0;j<connections;j++)
      {//0 0 insert to break out of loop, YOOO..!!
        cout<<"\nEnter details for "<<j+1<<" conection";
        cout<<"\nIt is connected to node: ";
        cin>>connecting_node;
        cout<<"\nWhat is the weight:";
        cin>>weight;

        g[i].push_back(make_pair(connecting_node-1,weight));
        g[connecting_node-1].push_back(make_pair(i,weight));

      }
    }

    /*
    g[0].push_back(make_pair(1,7));
    g[1].push_back(make_pair(0,7));

    g[0].push_back(make_pair(2,9));
    g[2].push_back(make_pair(0,9));

    g[0].push_back(make_pair(5,14));
    g[5].push_back(make_pair(0,14));

    g[1].push_back(make_pair(2,10));
    g[2].push_back(make_pair(1,10));

    g[1].push_back(make_pair(3,15));
    g[3].push_back(make_pair(1,15));

    g[2].push_back(make_pair(5,2));
    g[5].push_back(make_pair(2,2));

    g[2].push_back(make_pair(3,11));
    g[3].push_back(make_pair(2,11));

    g[3].push_back(make_pair(4,6));
    g[4].push_back(make_pair(3,6));

    g[4].push_back(make_pair(5,9));
    g[5].push_back(make_pair(4,9));
    */
    
    vector<int> path;//Matrix to store the shortest path..
    cout<<"\nPlease enter the start node : ";
    cin>>start;
    cout<<"\nPlease enter the end node : ";
    cin>>end;
    dijkstra(g,start-1,end-1,path);
    cout<<"\n Hence the shortest path is:\n";

    for(int i=path.size()-1;i>=0;i--)
        cout<<path[i]+1<<"->";
    return 0;
}

 