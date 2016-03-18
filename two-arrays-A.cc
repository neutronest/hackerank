#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int t;
  long long n, k;
  long NUMLIMIT = 10000000001; 
  cin>>t;
  for(auto ct=0; ct<t; ++ct) {
    bool res = true;
    cin>>n>>k;
    vector<long long> a_arr(n, 0);
    vector<long long> b_arr(n, 0);
    for(auto i=0; i<n; ++i) {
      cin>>a_arr[i];
    }
    for(auto i=0; i<n; ++i) {
      cin>>b_arr[i];
    }

    // greedy
    for(auto i=0; i<n; ++i) {

      if (res == false) {
        break;
      }

      int last_num = k - a_arr[i];
      if (last_num <= 0) {
        // enough, just pick the mimimum last number from b_arr
        long long min_b = NUMLIMIT;
        int b_idx = 0;
        for(auto j=i; j<n; j++) {
          if(min_b > b_arr[j]) {
            min_b = b_arr[j];
            b_idx = j;
            
          } // endif
        } // endfor
        //cout<<"enough flow: "<<b_arr[b_idx]<<endl;
        swap(b_arr[i], b_arr[b_idx]);
      } // endif
      else {
        // pick the suitable and minimum one from b_arr
        long long min_b = NUMLIMIT;
        int b_idx = -1;
        for (auto j=i; j<n; j++) {
          if (min_b > b_arr[j] && b_arr[j] >= last_num) {
            min_b = b_arr[j];
            b_idx = j;
          }
        } // endfor
        if (b_idx < 0) {
          // find no suitable
          res = false;
          break;
        } else {
          swap(b_arr[i], b_arr[b_idx]);
          // cout<<"pick flow: "<<b_arr[b_idx]<<endl;
        }
      } // endelse
    } // endfor gready

    if (res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  } // endfor  t cases

  return 0;
}
