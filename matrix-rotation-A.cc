#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long longt;
typedef pair<int, int> cood;
//typedef pair(int, int) cood;


struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) {
    this->val = x;
    this->next = nullptr;
  }
};

void rotate_helper(vector<vector<longt>> &mat, cood lu, cood ld, cood ru, cood rd, int r) {

  int mat_len = (ld.first-lu.first+1) * 2 +  (ru.second-lu.second+1) * 2 -4;
  int offset = r % mat_len;

  // side check
  if (offset == 0) return;

  //cout<<"mat_len: "<<mat_len<<endl;
  // generate an inner linklist
  ListNode* root = nullptr;
  ListNode* curNode = root;
  // from left_up to right_up
  for(auto j=lu.second; j<ru.second; ++j) {
    int temp_val = mat[lu.first][j];
    if (curNode == nullptr) {
      curNode = new ListNode(temp_val);
      root = curNode;
    }
    else {
      ListNode* nextNode = new ListNode(temp_val);
      curNode->next = nextNode;
      curNode = nextNode;
      //cout<<curNode->val<<endl;
    }
  }
  
  // from right_up to right_down
  for(auto i=ru.first; i<rd.first; ++i) {
    int temp_val = mat[i][ru.second];
    ListNode* nextNode = new ListNode(temp_val);
    curNode->next = nextNode;
    curNode = nextNode;
    //cout<<curNode->val<<endl;
  }

  // from right_down to left_down
  for(auto j=rd.second; j>ld.second; --j) {
    int temp_val = mat[rd.first][j];
    ListNode* nextNode = new ListNode(temp_val);
    curNode->next = nextNode;
    curNode = nextNode;
    //cout<<curNode->val<<endl;
  }

  // from left_down to left_up
  for(auto i=ld.first; i>lu.first; --i) {
    int temp_val = mat[i][ld.second];
    ListNode* nextNode = new ListNode(temp_val);
    curNode->next = nextNode;
    curNode = nextNode;
    //cout<<curNode->val<<endl;
  }
  
  // get a root as head, mat_len linkedlist
  // we need change the head
   ListNode* endNode = curNode;
  curNode = root;
  //cout<<"offset: "<<offset<<endl;
  //cout<<"endNode: "<<endNode->val<<endl;
  //cout<<"rooNode: "<<endNode->val<<endl;
  for(auto i=0; i<offset; i++) {
    //cout<<"curNode: "<<curNode->val<<" "<<endl;
    curNode = curNode->next;
  }
  endNode->next = root; // circle
  //cout<<"offset: "<<offset<<endl;
  //cout<<"endNode: "<<endNode->val<<endl;
  //cout<<"rooNode: "<<endNode->val<<endl;
  ListNode* offsetHead = curNode;
  // change the value
  for(auto j=lu.second; j<ru.second; ++j) {
    mat[lu.first][j] = curNode->val;
    curNode = curNode->next;
  }
  // from right_up to right_down
  for(auto i=ru.first; i<rd.first; ++i) {
    mat[i][ru.second] = curNode->val;
    curNode = curNode->next;
  }

  // from right_down to left_down
  for(auto j=rd.second; j>ld.second; --j) {
    mat[rd.first][j] = curNode->val;
    curNode = curNode->next;
  }
  // from left_down to left_up
  for(auto i=ld.first; i>lu.first; --i) {
    mat[i][ld.second] = curNode->val;
    curNode = curNode->next;
  }
}

vector<vector<longt>> rotate(vector<vector<longt>> mat, int ro) {
  int r = mat.size();
  int c = mat[0].size();
  //cout<<r<<" "<<c<<endl;
  // four side
  cood lu = cood(0, 0);
  cood ld = cood(r-1, 0);
  cood ru = cood(0, c-1);
  cood rd = cood(r-1, c-1);
  while(lu.second < ru.second && lu.first < ld.first) {
    //cout<<"=="<<endl;
    //cout<<lu.first<<" "<<lu.second<<endl;
    //cout<<ld.first<<" "<<ld.second<<endl;
    //cout<<ru.first<<" "<<ru.second<<endl;
    //cout<<rd.first<<" "<<rd.second<<endl;
    rotate_helper(mat, lu, ld, ru, rd, ro);
    lu = cood(lu.first+1, lu.second+1);
    ld = cood(ld.first-1, ld.second+1);
    ru = cood(ru.first+1, ru.second-1);
    rd = cood(rd.first-1, rd.second-1);
  }
  //cout<<"OK!"<<endl;
  return mat;
} // end func



int main() {

  int m,n;
  longt r;
  vector<vector<longt> > mat;
  cin>>m>>n>>r;
  for(auto i=0; i<m; ++i) {
    vector<longt> temp(n, 0);
    for(auto j=0; j<n; ++j) {
      cin>>temp[j];
    }
    mat.push_back(temp);
  }

  auto mat_update = rotate(mat, r);
  for(auto i=0; i<m; ++i) {
    for(auto j=0; j<n; ++j) {
      cout<<mat_update[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}


