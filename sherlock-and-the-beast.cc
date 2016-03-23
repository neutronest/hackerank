#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int t;
  int n;
  cin>>t;
  bool if_ans = false;
  for(auto az=0; az<t; ++az) {
    cin>>n;
    if_ans = false;
    vector<int> res(n, 0);
    // gready thinking
    // first calculate the cnt of 5 
    // then get the cnt of 3
    for (auto n_five=n; n_five >=0; --n_five) {
      int n_three = n - n_five;
      //cout<<"cur state: "<<n_five<<" "<<n_three<<endl;
      if (n_five % 3 == 0 && n_three % 5 == 0) {
        //cout<<"suitable state! "<<n_five<<" "<<n_three<<endl;
        if_ans = true;
        int cur = 0;
        while (cur < n_five) {
          res[cur] = 5;
          cur += 1;
        }
        while( cur < n) {
          res[cur] = 3;
          cur += 1;
        }
        // print res
        for(auto i=0; i<n; ++i) {
          cout<<res[i];
        }
        cout<<endl;
        break;
      }
      else {
        // not suitable situation
        continue;
      }
    }
    if (!if_ans) cout<<"-1"<<endl;
  }
  return 0;
}
