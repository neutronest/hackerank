#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {

  int t;
  int n,k;
  int abide_num = 0;
  cin>>t;
  for(auto a0 = 0; a0 < t; ++a0) {
    cin>>n>>k;
    vector<int> stu_arr(n, 0);
    abide_num = 0;
    for(auto i=0; i<n; ++i) {
      cin>>stu_arr[i];
      if (stu_arr[i] <= 0) {
        abide_num += 1;
      } 
    } //endfor input stu_arr
    if (abide_num >= k) {
      cout<< "NO"<<endl;
    }
    else cout<<"YES"<<endl;
    


  } // endfor each case

  return 0;
}
