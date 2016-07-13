/**
 * @file sol4.cc
 * @brief
 * @author Yong Yang
 * @version 1.0
 * @time 20:50
 * @date 2016-07-04
 */

#include<iostream>
#include<iomanip>
#include<bitset>
#include<vector>
#include<cstring>
#include<cassert>
using namespace std;

int a[10];
double dp[1024] = {0};
char check[1024] = {'n'};
double total;

double getdp(int i) {
    bitset<10> bitvec(i);
    int n = bitvec.count();
    assert(i > 0);
    if(n == 1)
        return 0;
    else {
        if(check[i] == 'y')
            return dp[i];
        else {
            vector<int> ind;
            double sum = 0;
            for(int j = 0; j < 10; j++) {
                if(bitvec[j]) {
                    ind.push_back(j);
                    sum += a[j];
                }
            }

            for(int j = 0; j < ind.size(); j++) {
                int pick = ind[j];
                double tmp = sum - a[pick];
                dp[i] += a[pick] / sum * ( total / tmp + getdp(i ^ (1 << pick)));
            }
            check[i] = 'y';
            // forget to return, but got the right result with gcc when compile with no extra option
            // undefined behavior
            // but when compiled with -O2, got the wrhong answer
        }
    }
}


int main(int argc, char *argv[]) {
    int K;
    while(cin >> K) {
        //double sum=0;
        total = 0;
        for (int i = 0; i < K; i++) {
            cin >> a[i];
            total += a[i];
        }
        memset(dp, 0, sizeof(dp));
        memset(check, 'n', sizeof(check));
        /*
        for (int i = 3; i < (1 << K); i++ ) {
            bitset<10> bitvec(i);
            vector<int> ind;
            double sum = 0;
            for(int j = 0; j < 10; j++) {
                if(bitvec[j]) {
                    ind.push_back(j);
                    sum += a[j];
                }
            }

            for(int j = 0; j < ind.size(); j++) {
                int pick = ind[j];
                dp[i] += a[pick] / sum * ( sum / (sum - a[pick]) + dp[i ^ (1 << pick)]);
            }



        }
        */

        cout << fixed << setprecision(9) << getdp((1 << K) - 1) + 1 << endl;

    }
    return 0;
}


