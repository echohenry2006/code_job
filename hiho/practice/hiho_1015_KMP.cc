#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pprint(vector<int> &v) {
  for (auto &s : v)
    cout << s << "-";
  cout << endl;
}

vector<int> PMT(string str) {
  int n = str.size();
  vector<int> pmt(n, 0);

  for (int i = 1; i < n; i++) {
    int k = pmt[i - 1];
    if (str[i] == str[k])
      pmt[i] = k + 1;
    else
      pmt[i] = 0;
  }
  //pprint(pmt);
  return pmt;
}



int match(string pattern, string str) {
  vector<int> ret;
  int m = pattern.size();
  int n = str.size();
  vector<int> pmt = PMT(pattern);
  int start = 0;
  while ((start + m) <= n) {
    //cout << "start is :" << start << endl;
    int i = 0;
    for (i = 0; i < m; i++)
      if (pattern[i] != str[start + i])
        break;
    if (i == m) { // match
      ret.push_back(start);
      start += (m - pmt[i - 1]);
    } else if (i == 0)
      start++;
    else
      start += (m - pmt[i - 1]);
  }
  return ret.size();
}

int main() {
  // string s = "ABCDAB";
  // vector<int> pmt = PMT(s);
  // pprint(pmt);
  int N;
  cin >> N;
  string pattern;
  string target;
  while (N--) {
    cin >> pattern >> target;
    //cout << pattern << "--" << target << endl;
    cout << match(pattern, target) << endl;
  }
  return 0;
}