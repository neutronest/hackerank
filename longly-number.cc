#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

  int n;
  cin>>n;
  int res = 0;
  vector<int> n_arr(n, 0);
  for(auto i=0; i<n; ++i) {
    cin>>n_arr[i];
    res ^= n_arr[i];
  }
  cout<<res;
}
