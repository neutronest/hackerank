#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int dfs(vector<vector<int> > &grid, vector<string> &flag_grid, int row, int col, int m, int n) {
  
  if(flag_grid[row][col] == '1' || grid[row][col] == 0) return 0;
  // current point
  int val = 1;
  flag_grid[row][col] = '1';
  if(row > 0) val += dfs(grid, flag_grid, row-1, col, m, n);
  if(row < m-1) val += dfs(grid, flag_grid, row+1, col, m, n);
  if(col > 0) val += dfs(grid, flag_grid, row, col-1, m, n);
  if(col < n-1) val += dfs(grid, flag_grid, row, col+1, m, n);
  if(row > 0 && col > 0) val += dfs(grid, flag_grid, row-1, col-1, m, n);
  if(row > 0 && col < n-1) val += dfs(grid, flag_grid, row-1, col+1, m, n);
  if(row < m-1 && col > 0) val += dfs(grid, flag_grid, row+1, col-1, m, n);
  if(row < m-1 && col < n-1) val += dfs(grid, flag_grid, row+1, col+1, m, n);
  return val;

}

int main() {

  int m, n;
  cin>>m;
  cin>>n;
  vector<vector<int> > grid;
  vector<string> flag_grid(m, string(n, '0'));
  int res = 0;
  //cout<<"input grid"<<endl;
  for(auto i=0; i<m; ++i) {
    vector<int> temp_arr(n, 0);
    grid.push_back(temp_arr);
    for(auto j=0; j<n; ++j) {
      cin>>grid[i][j];
    }
  } // endfor

  for(auto i=0; i<m; ++i) {
    for(auto j=0; j<n; ++j) {
      if (flag_grid[i][j] != '1') {
        int val = dfs(grid, flag_grid, i, j, m, n);
        if (res < val) res = val;
      }
    }
  }

  cout<<res;

  return 0;
}
