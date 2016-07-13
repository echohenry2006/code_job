#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include <algorithm>


using namespace std;

int main(int argc, char *argv[]) {
    string s;
    string t;
    while(cin >> s >> t) {
        int n = s.size();
        char a, b;
        if(s == t)  {
            cout << "Possible" << endl;
            continue;
        }
        for(int i = 0; i < n; i++)
            if(s[i] != t[i]) {
                a = s[i];
                b = t[i];
                break;
            }

        string s1 = s;
        string t1 = t;
        replace(s1.begin(), s1.end(), a, b);
        replace(t1.begin(), t1.end(), a, b);
        if(s1 == t1) {
            cout << "Possible" << endl;
            continue;
        }
        s1 = s;
        t1 = t;
        replace(t1.begin(), t1.end(), b, a);
        replace(s1.begin(), s1.end(), b, a);
        if(s1 == t1) {
            cout << "Possible" << endl;
            continue;
        }

        cout << "Impossible" << endl;
        


    }

    return 0;
}

