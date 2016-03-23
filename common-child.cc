#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str1, str2;
    cin>>str1>>str2;
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp;
    
    for(auto i=0; i<m+1; ++i) {
      vector<int> temp(n+1, 0);
      dp.push_back(temp);
    }
    /*
    if (str1[0] == str2[0]) {
        for(auto i=1; i<m+1; ++i) {
            dp[i][0] = 1;
        }
        for (auto j=1; j<n+1; ++j) {
            dp[0][j] = 1;
        }
    }
    */
    for(auto i=1; i<m+1; ++i) {
        for (auto j=1; j<n+1; ++j) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    
    cout<<dp[m][n]<<endl;
    return 0;
}
