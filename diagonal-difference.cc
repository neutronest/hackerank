#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {

  int n;
  cin>>n;
  vector<vector<int>> mat;

  // input
  for (auto i=0; i<n; ++i) {
    vector<int> temp(n, 0);
    for(auto j=0; j<n; ++j) {
      cin>>temp[j];
    }
    mat.push_back(temp);

  }

  // get two dig sums
  int dig1 = 0;
  int dig2 = 0;
  for(auto i=0; i<n; ++i) {
    dig1 += mat[i][i];
  }

  for(auto i=0; i<n; ++i) {
    dig2 += mat[i][n-1-i];
  }
  cout<<abs(dig1 - dig2);

  return 0;
}
