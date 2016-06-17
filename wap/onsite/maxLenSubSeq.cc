#include<iostream>
#include<string>
#include<vector>

using namespace std;


int maxLen(const vector<int> &vec){
    int max=0;
    int n=vec.size();
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++)
            if(vec[j]<vec[i])
                if(dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
        if(dp[i]>max)max=dp[i];
    }
    return max;
}


int main(int argc,char** argv){
    vector<int> vec={1,5, 2,4,3};
    cout<<maxLen(vec)<<endl;
    return 0;
}



