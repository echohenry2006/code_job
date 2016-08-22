#include<iostream>
#include<vector>
#include<cstdio>
#include<climits>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<int> dp(n+1,-1);
        return getdp(n,dp);
 
    }
    
    int getdp(int n, vector<int> &dp){
        if(n==1){dp[n]=0;return 0;}
        if(n==2){dp[n]=1;return 1;}
        if(n==3){dp[n]=2;return 2;}
        if(n==4){dp[n]=4;return 4;}
        if(dp[n]!=-1)return dp[n];
        dp[n]=INT_MAX;
		int minpivot;
        for(int size=3;;){
            int pivot=n-size;
				#ifdef DEBUG
					printf("pivot is: %d\n",pivot);
				#endif
            int rmax=0;
            for(int j=size>>1;j>0;j=j>>1){
				#ifdef DEBUG
					printf("j is: %d\n",j);
				#endif
                rmax+=(n-j);
            }
            int lmax=getdp(pivot-1,dp);
			if( dp[n]> pivot+max(lmax,rmax) ){
				dp[n]=pivot+max(lmax,rmax);
				minpivot=pivot;
			}
            
            if(lmax<rmax){
				#ifdef DEBUG2
				printf("lmax is: %d\n",lmax);
				printf("rmax is: %d\n",rmax);
				#endif
                break;
			}
            size=size<<1|1;
            
        }
		#ifdef DEBUG2
					printf("n is: %d\n",n);
					printf("minpivot is: %d\n",minpivot);
					printf("dp_%d-dp_%d is: %d\n",minpivot-1,minpivot-2,dp[minpivot-1]-dp[minpivot-2]);
		#endif
        return dp[n];
    }
    
    
};


int main(){
	Solution sol;
	cout<<sol.getMoneyAmount(124)<<endl;
	return 0;
}