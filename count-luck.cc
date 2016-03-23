#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void dfs(vector<string> &maze,
         vector<vector<int>> &b_mat,
         pair<int, int> cur_pos,
         int b,
         int n,
         int m) {
  int cur_i = cur_pos.first;
  int cur_j = cur_pos.second;
  // prepare four direction
  // up, down left, right
  bool if_up = false;
  bool if_down = false;
  bool if_left = false;
  bool if_right = false;

  // update cur branch value
  b_mat[cur_i][cur_j] = b;

  // get the cur_pos branch
  int b_temp = 0;
  if (cur_i > 0 && maze[cur_i-1][cur_j] != 'X' && b_mat[cur_i-1][cur_j] == -1) {
    b_temp += 1;
    if_up = true;
  }
  if (cur_i < n-1 && maze[cur_i+1][cur_j] != 'X' && b_mat[cur_i+1][cur_j] == -1) {
    b_temp += 1;
    if_down = true;
  }
  if (cur_j > 0 && maze[cur_i][cur_j-1] != 'X' && b_mat[cur_i][cur_j-1] == -1) {
    b_temp += 1;
    if_left = true;
  }
  if (cur_j < m-1 && maze[cur_i][cur_j+1] != 'X' && b_mat[cur_i][cur_j+1] == -1) {
    b_temp += 1;
    if_right = true;
  }
  if (b_temp > 1) {
    b = b+1;
  }
  if (if_up) dfs(maze, b_mat, pair<int, int>(cur_i-1, cur_j), b, n, m);
  if (if_down) dfs(maze, b_mat, pair<int, int>(cur_i+1, cur_j), b, n, m);
  if (if_left) dfs(maze, b_mat, pair<int, int>(cur_i, cur_j-1), b, n, m);
  if (if_right) dfs(maze, b_mat, pair<int, int>(cur_i, cur_j+1), b, n, m);
}

int main() {

  int t;
  cin>>t;
  for(auto az=0; az<t; ++az) {
    int n, m, l;
    cin>>n>>m;
    vector<string> maze;
    vector<vector<int>> b_mat; // record the branch size 
    pair<int, int> start_pos, end_pos;

    for(auto i=0; i<n; ++i) {
      string s;
      cin>>s;
      maze.push_back(s);
      vector<int> temp(m, -1);
      b_mat.push_back(temp);
    }
    // input the l number
    cin>>l;

    // get the start_pos and end_pos
    for (auto i=0; i<n; ++i) {
      for(auto j=0; j<m; ++j) {
        if (maze[i][j] == 'M') {
          start_pos = pair<int, int>(i, j);
        }
        if (maze[i][j] == '*') {
          end_pos = pair<int, int>(i, j);
        }
      }
    }
    // greed recording!!
    dfs(maze, b_mat, start_pos, 0, n, m);
    int res = b_mat[end_pos.first][end_pos.second];
    if (res == l) cout<<"Impressed"<<endl;
    else cout<<"Oops!"<<endl;
  }
  return 0;
}
