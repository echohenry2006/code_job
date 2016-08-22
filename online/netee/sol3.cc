#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cassert>
using namespace std;

//int dp_min[51][11];
//int dp_max[51][11];

#define MAXI 9999999
#define MINI -9999999

int main(int argc , char** argv) {
    int n,k,d;
    while(cin>>n){

        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        cin>>k;
        cin>>d;
        //memset(dp_min,0,sizeof(dp_min));
        //memset(dp_max,0,sizeof(dp_max));
        vector<vector<int> > dp_min(n,vector<int>(k,0));
        vector<vector<int> > dp_max(n,vector<int>(k,0));
        for(int i=0;i<n;i++){
            dp_min[i][0]=a[i];
            dp_max[i][0]=a[i];
            for(int j=1;j<k;j++){
                if(i>=j){
                    int tmp_min=MAXI;
                    int tmp_max=MINI;
                    for(int m=1;m<=d;m++){
                        int index=i-m;
                        if(index>=(j-1)){
                            int tmp =a[i]*dp_max[index][j-1];
                            if(tmp<tmp_min)
                                tmp_min = tmp;
                            if(tmp>tmp_max)
                                tmp_max = tmp;
                            tmp =a[i]*dp_min[index][j-1];
                            if(tmp<tmp_min)
                                tmp_min = tmp;
                            if(tmp>tmp_max)
                                tmp_max = tmp;
                        }
                    }
                    dp_min[i][j]=tmp_min;
                    dp_max[i][j]=tmp_max;

                    
                        
                }

            }
        }
        int ret=MINI;

        for(int i=k-1;i<n;i++)
            if(dp_max[i][k-1]>ret)
                ret=dp_max[i][k-1];
        cout<<ret<<endl;


    }
    return 0;
}
