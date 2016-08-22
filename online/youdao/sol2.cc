// g++ -std=c++11 sol2.cc -o sol2.exe
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

void sol(int n) {
  vector<int> a(n, 0);
  queue<int> q;
  for (int i = 0; i < n; i++)
    q.push(i);
  int k = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    q.push(x);
    x = q.front();
    q.pop();
    // assert(a[x]==0);
    a[x] = k;
    k++;
  }

  for (int i = 0; i < n - 1; i++)
    cout << a[i] << " ";
  cout << a[n - 1] << endl;
}

int main(int argc, char **argv) {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    sol(n);
  }
  return 0;
}