#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

  int n;
  cin>>n;
  vector<int> arr(n, 0);
  int r = 0;
  int cur_val = 0;
  for (auto i=0; i<n; ++i) {
    cin>>arr[i];
    /*
    if (i == 0) {
      r = 1;
      cur_val = 1;
    }
    else {
      if (arr[i-1] < arr[i]) {
        cur_val += 1;
        r += cur_val;
      }
      else if(arr[i-1] == arr[i]) {
        cur_val = 1;
        r += cur_val;
      }
      else {
        if (cur_val == 1) {
          
          r += (i-1); // all waterline upgrad 1
          r += cur_val;
        }
        else {
          cur_val = 1;
          r += cur_val;
        }
      }
    }
    */
  } // end for
  vector<int> candies(n, 1);
  // bidirectional dp
  // left to right dp
  for(auto i=1; i<n; ++i) {
    if (arr[i-1] < arr[i]) {
      candies[i] = candies[i-1] + 1;
    }
    else {
      candies[i] = 1;
    }
  }
  // right to left dp
  for(auto j=n-2; j>=0; j--) {
    if (arr[j+1] >= arr[j]) {
      continue;
    }
    else {
      candies[j] = max(candies[j], candies[j+1]+1); 
    }
  }
  for (auto i=0; i<n; ++i) {
    r += candies[i];
  }
  cout<<r<<endl;

  return 0;
}
