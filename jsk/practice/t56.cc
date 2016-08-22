#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  while (cin >> N) {
    vector<int> a(N);
    for (int i = 0; i < N; i++)
      cin >> a[i];
    char c = 'a';
    string ret;
    bool flag = true;
    for (int i = 0; i < N; i++) {
      //cout << ret << endl;
      if (a[i] == 0){ 
        if(i==0)
            ret.push_back('a');
        else
            ret.push_back('b');
        continue;
      }
        
        
      
      int k = a[i];
      if((k-a[i-1])!=1){
          flag=false;
          break;
      }

      c = ret[k - 1];
      ret.push_back(c);
      if (c > 'q') {
        flag = false;
        break;
      }
      c++;
    }
    if (flag && a[0]==0)
      cout << ret << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
