#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

  int t;
  string s;
  bool res = false;
  cin>>t;
  for(auto ao=0; ao<t; ++ao) {
    cin>>s;
    res = true;
    int s_len = s.length();

    // side condition
    if (s_len == 1) {
      cout<<"Funny"<<endl;
      continue;
    }
    int head_cur = 1;
    int tail_cur = s_len-2;
    while (head_cur <= tail_cur) {
      if(abs(s[head_cur]-s[head_cur-1]) == abs(s[tail_cur] - s[tail_cur+1]) ) {
        head_cur += 1;
        tail_cur -= 1;
      }
      else {
        res = false;
        break;
      }
    }
    if (res) cout<<"Funny"<<endl;
    else cout<<"Not Funny"<<endl;
  }
}
