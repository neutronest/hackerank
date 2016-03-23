#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

  int t;
  cin>>t;
  for(auto az=0; az<t; ++az) {

    // init
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    // input
    for(auto i=0; i<n; ++i) {
      cin>>arr[i];
    }
    // two res
    int uncon_res = arr[0];
    int con_res = arr[0];
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (auto i=1; i<n; ++i) {
      dp[i] = max(dp[i-1]+arr[i], arr[i]);
      //cout<<dp[i]<<" ";
      con_res = max(con_res, dp[i]);
      if (arr[i] >= 0) {
        if (uncon_res < 0) uncon_res = arr[i];
        else uncon_res += arr[i];
      } 
    }
    //cout<<endl;

    if (con_res < 0) uncon_res = con_res;
    cout<<con_res<<" "<<uncon_res<<endl;

  }// endfor
  

  return 0;
}
