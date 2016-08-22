// g++ -std=c++11 sol1.cc -o sol1.exe
#include <iostream>
#include <queue>
#include <string>
#include <vector>

//#include<priority_queue>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

vector<int> shuffl(vector<int> &a) {
  int n = a.size();
  vector<int> ret(n);
  for (int i = 0; i < n / 2; i++) {
    ret[2 * i] = a[i];
    ret[2 * i + 1] = a[n / 2 + i];
  }

  return ret;
}

void sol() {
  int n, k;
  cin >> n >> k;
  // cout<<"n is "<<n<<endl;
  // cout<<"k is "<<k<<endl;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++)
    cin >> a[i];

  for (int i = 0; i < k; i++)
    a = shuffl(a);
  for (int i = 0; i < 2 * n - 1; i++)
    cout << a[i] << " ";
  cout << a[2 * n - 1] << endl;
}

int main(int argc, char **argv) {
  int N;
  cin >> N;
  for (int t = 0; t < N; t++)
    sol();

  return 0;
}