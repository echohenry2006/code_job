#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cassert>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        if(prices.empty())return 0;
        int n_day = prices.size();
        vector<int> v1(n_day);
        vector<int> v2(n_day);

        v1[0]=prices[0];
        v2[n_day-1]=prices[n_day-1];
        for(int i=1;i<n_day;i++){
            v1[i]=(prices[i]<v1[i-1])?prices[i]:v1[i-1];
            v2[n_day-1-i]=(prices[n_day-1-i]>v2[n_day-i])?prices[n_day-1-i]:v2[n_day-i];
        
        }

        int max=0;
        for(int i=0;i<n_day;i++)
            if( (v2[i]-v1[i]) >max)
                max=v2[i]-v1[i];

        return max;

                

    }

    
};


int main(int argc , char** argv)
{
    int n;
    Solution sol;
    while(cin>>n){
        vector<int> prices(n);
        for(int i=0;i<n;i++)
            cin>>prices[i];
        cout<<sol.maxProfit(prices)<<endl;
        
    }

    return 0;
        
            
}

