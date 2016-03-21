#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main() {
  int t;
  int n, m;
  cin>>t;
  for(auto az=0; az<t; ++az) {
    cin>>n>>m;
    // n denotes the nodes, m denotes the edges
    // generate graph from 0 to n (n+1 numbers) for deal easily
    vector<vector<int>> vgraph;
    vector<int> flag_graph(n+1, 0); // if has accessed
    vector<int> res_graph(n+1, -1);

    int depth = 0;
    for(auto i=0; i<=n; ++i) {
      vector<int> node_list;
      node_list.push_back(i);
      vgraph.push_back(node_list);
    }

    // input graph
    for(auto i=1; i<=m; ++i) {
      int x, y;
      cin>>x>>y;
      vgraph[x].push_back(y);
      vgraph[y].push_back(x);
    }
    // input s
    int start_pos;
    cin>>start_pos;
    // begin bfs
    queue<int> Q;
    queue<int> Q_depth;
    Q.emplace(start_pos);
    Q_depth.emplace(0);
    flag_graph[start_pos] = Q_depth.front();
    while (!Q.empty()) {
      int curnode = Q.front();
      int curdepth = Q_depth.front();
      res_graph[curnode] = curdepth;
      int edge_num = vgraph[curnode].size();
      for (auto edge_iter=0; edge_iter<edge_num; ++edge_iter) {
        int node = vgraph[curnode][edge_iter];
        if (flag_graph[node] != 1) {
          // never access
          Q.emplace(node);
          Q_depth.emplace(curdepth+6);
          flag_graph[node] = 1;
        }
      }
      Q.pop();
      Q_depth.pop();
    }

    // print result
    for(auto i=1; i<=n; ++i) {
      if(i == start_pos) continue;
      cout<<res_graph[i]<<" ";
    }
    cout<<endl;

  }

}
