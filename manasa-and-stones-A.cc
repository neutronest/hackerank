#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int t;
  int n, a, b;
  cin>>t;
  vector<int> num_vec;
  for(auto c=0; c<t; ++c) {
    cin>>n;
    cin>>a;
    cin>>b;

    num_vec = vector<int>(10000001, 0);
    for(auto i=0; i<n; ++i) {
      int pick = i * a + (n-1-i) * b;
      if(num_vec[pick] != 1) {
        num_vec[pick] += 1;
      }
    }
    // print out
    for(auto i=0; i<10000001; ++i) {
      if (num_vec[i] != 0) cout<<i<<" ";
    }
    cout<<endl;
  } //endfor

  return 0;
}
