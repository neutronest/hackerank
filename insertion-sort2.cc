#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void printIter(vector<int> &arr) {
  int n = arr.size();
  for (auto i=0; i<n; ++i) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main() {

  int n; // size of array
  cin>>n;
  vector<int> arr(n, 0);

  // input and print the first iteration
  for(auto i=0; i<n; ++i) {
    cin>>arr[i];
  }
  //printIter(arr);
  for (auto i=1; i<n; ++i) {
    //cout<<"need sort cur: "<<arr[i]<<endl;
    int e = arr[i];
    int j = i;
    while (e < arr[j-1]) {
      arr[j] = arr[j-1];
      j = j-1;
    }
    arr[j] = e;
    printIter(arr);
    
  }
  return 0;
}
