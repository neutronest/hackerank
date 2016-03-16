#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;
int main() {

  vector<int> n_map(10001, 0);
  vector<int> m_map(10001, 0);
  //vector<int> n_arr;
  //vector<int> m_arr;
  //vector<int> res;
  int n, m;

  cin>>n;
  for (auto i=0; i<n; ++i) {
    int num = 0;
    cin>>num;
    //n_arr.push_back(num);
    n_map[num] += 1;
  }
  cin>>m;
  for(auto i=0; i<m; ++i) {
    int num = 0;
    cin>>num;
    //m_arr.push_back(num);
    m_map[num] += 1;
  }

  for(auto i=0; i<10001; ++i) {
    if (n_map[i] != m_map[i]) {
      //res.push_back(i);
      cout<<i<<" ";
    }
  }



  return 0;
}
