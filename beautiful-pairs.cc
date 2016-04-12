#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

// only in the acm mode
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> arr_a(n, 0);
  vector<int> arr_b(n, 0);
  int map_a[1001] = {0};
  int map_b[1001] = {0};
  int r = 0;
  // input
  for (auto i=0; i<n; ++i) {

    cin>>arr_a[i];
    map_a[arr_a[i]] += 1;
  }
  for (auto i=0; i<n; ++i) {
    cin>>arr_b[i];
    map_b[arr_b[i]] += 1;
  }
  for (auto j=0; j<=1001; ++j) {
    if (map_a[j] > 0 && map_b[j] > 0) {
      r += min(map_a[j], map_b[j]);
    }
  }
  if (r < n) r += 1;
  else if (r == n) r -= 1;
  cout<<r<<endl;
  return 0;
}
