#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

  int n;
  double posf, negf, zerof;
  cin>>n;
  vector<int> arr(n, 0);
  for (auto i=0; i<n; ++i){
    cin>>arr[i];
    if (arr[i] > 0) {
      posf += 1;
    }
    else if(arr[i] == 0) {
      zerof += 1;
    }
    else {
      negf += 1;
    }
  }
  posf = posf / n;
  negf = negf / n;
  zerof = zerof / n;
  cout<<posf<<endl<<negf<<endl<<zerof<<endl;

  return 0;
}
