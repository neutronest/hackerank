#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

  int t;
  cin>>t;
  for(auto i=0; i<t; ++i) {
    int r = 0;
    string s;
    cin>>s;
    int len_s = s.length();
    if (len_s % 2 != 0) {
      cout<<-1<<endl;
      continue;
    } // end if
    string sa = s.substr(0, (len_s/2));
    string sb = s.substr((len_s/2), (len_s/2));
    vector<int> sa_map(26, 0);
    vector<int> sb_map(26, 0);
    for(auto i=0; i<sa.length(); ++i) {
      char a = sa[i];
      char b = sb[i];
      sa_map[a-'a'] += 1;
      sb_map[b-'a'] += 1;
    } // end for
    for (auto i=0; i<26; ++i) {
      if (sa_map[i] != sb_map[i]) {
        r += abs(sa_map[i] - sb_map[i]);
      } // end if
    } // end for
    cout<<(r/2)<<endl;
  } // end for
  return 0;
}
