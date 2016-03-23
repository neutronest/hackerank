#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

  int n, m; // n denotes n changes, m denotes m kind of coins
  cin>>n>>m;
  vector<vector<long long>> dp;
  vector<int> coin_map(51, 0);
  for (auto ci=0; ci<m; ++ci) {
    int temp;
    cin>>temp;
    coin_map[temp] = 1;
  }
  // init dp
  for (auto i=0; i<n+1; ++i) {
    vector<long long> temp(m, 0);
    dp.push_back(temp);
  }
  int cur = 1;
  int j = 0;
  while(cur < 51) {
    if (coin_map[cur] != 0) {
      // has this kind of coin
      if (j == 0) {
        for (auto change=0; change<=n; change++) {
          if( change >= cur && change % cur == 0) {
            dp[change][j] = 1;
          }
          else dp[change][j] = -1;
        }
      }
      else {
        for (auto change=0; change<=n; ++change) {
          int max_num = change / cur;
          if (dp[change][j-1] != -1) {
            dp[change][j] =dp[change][j-1];
          }
          for(int i=1; i<=max_num; ++i) {
            if (dp[change-i*cur][j-1] != -1) {
              dp[change][j] += dp[change-i*cur][j-1];
            }
          }
          // contain itself
          if (change >= cur && change % cur == 0) {
            dp[change][j] += 1;
          }
        }
      }

      j += 1;
    }
    cur += 1;
  }
  /*
  for(auto i=0; i<n+1; i++) {
    for (auto j=0; j<m; j++) {
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  cout<<dp[n][m-1];

  return 0;
}
