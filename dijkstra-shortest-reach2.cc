#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define MAX_INT 9999

using namespace std;

class elm {
public:
  int edge;
  int dist;
  elm (int edge, int dist): edge(edge), dist(dist){}

  // reverse the operator!!!!!
  friend bool operator<(const elm e1, const elm e2) {
    if (e1.dist >= e2.dist) {
      return true;
    } else return false;

  }
}; 

/*
int get_shortest_edge(vector<vector<int>> &vgraph, vector<int> &visited, int vertex, int n) {
  int w = MAX_INT;
  int edge = -1;
  for (auto i=0; i<n; ++i) {
    if (w > vgraph[vertex][i] && vgraph[vertex][i] != -1 && visited[vertex] == 0) {
      w = vgraph[vertex][i];
      edge = i;
    }
  }
  return edge;
}
*/
int main() {
  int t;
  cin>>t;
  for (auto az=0; az<t; ++az) {
    int n, m;
    cin>>n>>m;
    // graph init
    vector<vector<int>> vgraph;
    for (auto i=0; i<n; ++i) {
      vector<int> temp_arr(n, -1);
      vgraph.push_back(temp_arr);
    }
    // graph edge input
    for (auto i=0; i<m; ++i) {
      int x,y,w;
      cin>>x>>y>>w;
      if (vgraph[x-1][y-1] == -1) {
        vgraph[x-1][y-1] = w;
        vgraph[y-1][x-1] = w;
      }
      else if (vgraph[x-1][y-1] > w) {
        vgraph[x-1][y-1] = w;
        vgraph[y-1][x-1] = w;
      }
      
    }

    // the start_pos
    int start;
    cin>>start;
    start = start-1;
    // prepare essential helper
    vector<int> dist(n, MAX_INT);
    vector<int> visited(n, 0);
    // use a priority_queue instead of a simple queue
    // to get the minimum in the queue
    priority_queue<elm> Q;
    dist[start] = 0;
    Q.push(elm(start, dist[start]));
    for (auto i=0; i<n; ++i) {
      if (i != start) {
        Q.push(elm(i, MAX_INT));
      }
    }

    while(!Q.empty()) {
      elm cur_ver = Q.top();
      Q.pop(); 
      int cur_edge = cur_ver.edge;
      int cur_dist = cur_ver.dist;
      visited[cur_edge] = 1;
      for (auto j=0; j<n; ++j) {
        if (visited[j] == 0 && vgraph[cur_edge][j] != -1) {
          // get all adj
          int adj_edge = j;
          int alt = vgraph[cur_edge][adj_edge] + dist[cur_edge];

          if (alt < dist[adj_edge]) {
            dist[adj_edge] = alt;
            Q.push(elm(adj_edge, dist[adj_edge]));
          }
        }
      }
    }
    for (auto i=0; i<n; ++i) {
      if (i != start) {
        if (dist[i] ==  MAX_INT) dist[i] = -1;
        cout<<dist[i]<<" ";
      }
    }
    cout<<endl;

  }
  return 0;
}
