#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void printArr(vector<int> n_arr) {
  int n = n_arr.size();
  for(auto i=0; i<n; ++i) {
    cout<<n_arr[i]<<" ";
  }
  cout<<endl;
}

int main() {

  int n;
  cin>>n;
  vector<int> n_arr(n, 0);
  for(auto i=0; i<n; ++i) {
    cin>>n_arr[i];
  }

  if (n == 1) {
    printArr(n_arr);
    return 0;
  }

  int e = n_arr[n-1];
  for(int j=n-1; j>0; --j) {
    if (n_arr[j-1] > e) {
      n_arr[j] = n_arr[j-1];
      printArr(n_arr);
    }
    else {
      n_arr[j] = e;
      printArr(n_arr);
      return 0;
    }
  }
  n_arr[0] = e;
  printArr(n_arr);

  return 0;
}
