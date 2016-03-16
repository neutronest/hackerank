#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

int main() {

  int n; // the size of map
  vector<string> grid;
  cin>>n;
  
  for(auto i=0; i<n; ++i) {
    string s;
    cin>>s;
    grid.push_back(s);
  } // endfor

  // check cave
  for(auto i=1; i<n-1; ++i) {
    for(auto j=1; j<n-1; ++j) {
      if (grid[i][j] > grid[i-1][j]
          && grid[i][j] > grid[i+1][j]
          && grid[i][j] > grid[i][j-1]
          && grid[i][j] > grid[i][j+1]) {
        grid[i][j] = 'X';
      }
    }
  }
  for (auto i=0; i<n; ++i) {
    cout<<grid[i]<<endl;
  }

  return 0;
}
