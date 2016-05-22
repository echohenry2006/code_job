#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

#define MMM 1000000007



ll dp[10][10]={0};

int main(int argc, char** argv){
	int n,m;
	dp[1][1]=1;
	while(cin>>n>>m){
		for(int i=2;i<=n;i++)
			for(int j=2;j<=m;j++){
					dp[i][j]=0;
					for(int a=1;a<i;a++)
						for(int b=1;b<j;b++){
							dp[i][j]+= (dp[a][b]) ;
						//	dp[i][j]%=1000000007;
						}
				
			}
		cout<<dp[n][m]<<endl;
	}
	
	return 0;
}