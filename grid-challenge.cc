#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


bool check_col(vector<string> &grid, int n) {
  bool flag = true;
  for(auto i=0; i<n-1; ++i) {
    for (auto j=0; j<n; ++j) {
      if(grid[i][j] > grid[i+1][j]) {
        flag = false;
      }
    }
  }
  return flag;
}

int main() {
  int t;
  cin>>t;
  for(auto az=0; az<t; ++az) {
    int n;
    cin>>n;
    vector<string> grid;
    for(auto i=0; i<n; ++i) {
      string s;
      cin>>s;
      // sort by each row
      sort(s.begin(), s.end());
      grid.push_back(s);
    }
    bool res = check_col(grid, n);
    if (res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
