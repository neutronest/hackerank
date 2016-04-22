#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {

  int t;
  cin>>t;
  for(auto i=0; i<t; ++i) {
    int n;
    cin>>n;
    int r = 0;
    int rest_num = n;
    while (rest_num != 0) {
      int cur_digit = rest_num % 10;
      rest_num = rest_num / 10;
      if (cur_digit != 0 && n % cur_digit == 0) {
        r += 1;
      }
    } // end while
    cout<<r<<endl;
    
  } // end for

}
