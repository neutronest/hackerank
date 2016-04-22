#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {

  int t;
  cin>>t;
  for(auto ti=0; ti<t; ++ti) {
    int n;
    cin>>n;
    vector<long long> prices(n, 0);
    for (auto i=0; i<n; ++i) {
      cin>>prices[i];
    } // end for input array
    long long max_price = -1;
    long long r = 0;
    for (auto i=n-1; i>=0; --i) {
      max_price = max(max_price, prices[i]);
      r += max_price - prices[i];
    }
    cout<<r<<endl;


  } // end for (t case)
  return 0;
}
