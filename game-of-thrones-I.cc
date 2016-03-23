#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {

  vector<int> char_map(26, 0);
  string s;
  cin>>s;
  int len_s = s.length();
  for(auto i=0; i<len_s; ++i) {
    char_map[s[i]-'a'] += 1;
  }

  int odd_num = 0;
  // iterate the char_map
  for (auto i=0; i<26; ++i) {
    if (char_map[i] % 2 != 0) {
      odd_num += 1;
    }
  }
  

  if (odd_num > 1) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  return 0;
}
