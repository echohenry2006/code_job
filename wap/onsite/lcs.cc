#include<string>
#include<iostream>
#include<vector>
using namespace std;


int lcs(string s1, string s2){
    int n1=s1.size();
    int n2=s2.size();
    int max=0;
    vector<vector<int> > dp(n1,vector<int>(n2,0));
    for(int i=0;i<n1;i++)
        for(int j=0;j<n2;j++){
            if(i==0 ||j==0){
                if(s1[i]==s2[j])
                    dp[i][j]=1;
                else{
                    if(i==0 && j==0)
                        dp[i][j]=0;
                    else if(i==0 && j!=0)
                        dp[i][j]=dp[i][j-1];
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
            else{
                if(s1[i]==s2[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
            }

            if(dp[i][j]>max)
                max = dp[i][j];
        }
    return max;
                    
}



int main(int argc, char** argv){
    string s1("abcd");
    string s2("bdsafs");
    cout<<lcs(s1,s2)<<endl;
    return 0;
}
