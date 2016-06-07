#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cassert>
using namespace std;


//enum State{toSell,toCool,toBuy};

#define toSell 0
#define toCool 1
#define toBuy 2

class Solution{
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        vector<vector<int> > dp(prices.size(),vector<int>(3));
        dp[n-1][toBuy]=0;
        dp[n-1][toSell]=prices[n-1];
        dp[n-1][toCool]=0;
        for(int i=n-2;i>=0;--i){
            dp[i][toBuy]=max(dp[i+1][toSell]-prices[i],dp[i+1][toBuy]);
            dp[i][toCool]=dp[i+1][toBuy];
            dp[i][toSell]=max(dp[i+1][toCool]+prices[i],dp[i+1][toSell]);
        }
#ifdef DEBUG
        for(int i=0;i<3;i++){
            switch(i){
                case 0:
                    cout<<"Sell: ";
                    break;
                case 1:
                    cout<<"Cool: ";
                    break;
                case 2:
                    cout<<"Buy: ";
                    break;
            }
            for(int j=0;j<n;j++)
                cout<<dp[j][i]<<" ";
            cout<<endl;
        }            
#endif

        return dp[0][toBuy];
            


    }
};


int main(int argc , char** argv)
{
    int n;
    Solution sol;
    while(cin >>n){
        vector<int> prices(n);
        for(int i=0;i<n;i++)
            cin>>prices[i];
        cout<<sol.maxProfit(prices);
    }

    return 0;



}

