#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include <algorithm>

double Taka[100000];
double Aoki[100000];
using namespace std;

int main(int argc, char *argv[]) {
    int A, B, K;
    while(cin >> A >> B >> K) {
        Taka[0] = A + 0.0;
        Aoki[0] = B + 0.5;
        for(int i = 1; i < K; i++) {
            Taka[i] = Taka[i - 1] + A;
            Aoki[i] = Aoki[i - 1] + B;

        }

        int num = 0;
        int i = 0;
        int j = 0;
        string out;
        while(num < K) {
            // cout << "Taka is " << A*(i + 1.0) << "Aoki is " << (B * (j + 1.0) + 0.5) << endl;
            // cout << "TT is " << Taka[i] << "Ao is " << Aoki[i] << endl;
            //
            //
            if( (A * (i + 1.0) < (B * (j + 1.0) + 0.5)) ^ (Taka[i] < Aoki[j])) {
                cout.precision(1);
                cout.setf(ios::fixed);
                cout<< "num is "<<num << endl;
                cout << "Taka is " << A*(i + 1.0) << "Aoki is " << (B * (j + 1.0) + 0.5) << endl;
                cout << "TT is " << Taka[i] << "Ao is " << Aoki[i] << endl;
                break;
            }

            if(Taka[i] < Aoki[j]) {
                out = "Takahashi";
                i++;
                num++;
            } else {
                out = "Aoki";
                j++;
                num++;
            }
        }
        cout << out << endl;
    }
    return 0;
}



