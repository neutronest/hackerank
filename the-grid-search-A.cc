#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool ifGridEqual(vector<string> &grid, vector<string> &grid_in, int row_idx, int col_idx) {

  int row_num = grid_in.size();
  int col_num = grid_in[0].length();

  // check side condition
  if (row_idx+row_num > grid.size() || col_idx+col_num > grid[0].length()) {
    return false;
  }


  for(auto i=0; i<row_num; ++i) {
    for(auto j=0; j<col_num; ++j) {
      
      int row_cur = row_idx + i;
      int col_cur = col_idx + j;

      if (grid_in[i][j] != grid[row_cur][col_cur]) {
        return false;
      }

    }
  }

  return true;

}

int main() {

  int t = 0; // number of test cases
  int r, c; // row col
  int r_in, c_in; // the inline row, inline col
  vector<string> grid;
  vector<string> grid_in;

  std::cin>>t;
  for(auto i=0; i<t; ++i) {

    // reinit
    grid.clear();
    grid_in.clear();

    // input the row and col
    std::cin>>r>>c;
    // input the grid
    for(auto j=0; j<r; ++j) {
      string s;
      std::cin>>s;
      grid.push_back(s);
    } // endfor
    std::cin>>r_in>>c_in;
    // input the grid_in
    for (auto j=0; j<r_in; ++j) {
      string s;
      std::cin>>s;
      grid_in.push_back(s);
    } // endfor
    //////////

    bool res = false;
    for (auto row=0; row<grid.size(); ++row) {
      for(auto col=0; col<grid[0].length(); ++col) {
        if (ifGridEqual(grid, grid_in, row, col)) {
          res = true;
        }
      }
    }
    // print
    if (res) std::cout<<"YES"<<endl;
    else std::cout<<"NO"<<endl;
  } // endfor each case


  return 0;
}
