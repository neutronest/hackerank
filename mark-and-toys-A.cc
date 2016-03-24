#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() 
{
  long long n, k; cin >> n >> k;
  vector<int> prices;
  for(int i = 0; i < n; i++)
    {
      int p; cin >> p;
      prices.push_back(p);
    }
  sort(prices.begin(), prices.end());
  // Write the code for computing the final answer using n,k,prices
  int k_last = k;
  int res = 0;
  for (auto i=0; i<n; ++i) {
    if (k_last >= prices[i]) {
      k_last -= prices[i];
      res += 1;
    }
  }
  cout << res << endl;
    
  return 0;
}
