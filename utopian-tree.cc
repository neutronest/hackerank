#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
  int t;
  cin >> t;
  for(int a0 = 0; a0 < t; a0++){
    int n;
    int res = 1;
    cin >> n;
    if (n == 0) {
      cout<<res<<endl;
      continue;
    }

    if (n % 2 == 0) {
      // a_n = pow(2, n+1) - 1
      int y = n/2;
      res = pow(2, y+1) -1;
    } else {
      int y = (n-1)/2;
      res = pow(2, y+1) - 1;
      res *= 2;
    }
    cout<<res<<endl;
  }
  return 0;
}
