#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    int A, B, K;
    while(cin >> A >> B >> K) {

        int num = 0;
        int i=0;
        int j=0;
        string out;
        while(num < K) {
            cout<< "Taka is "<<A*(i+1.0) << "Aoki is "<< (B * (j + 1.0)+0.5)<<endl;
            if( A * (i + 1.0) < (B * (j + 1.0) + 0.5 )){
                i++;
                out = "Takahashi";
                
            }

            else{
                j++;
                out = "Aoki";
            }

            num++;
        }
        cout << out << endl;
    }
    return 0;
}


