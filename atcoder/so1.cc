#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int N;
    while(cin>>N){
        vector<int> skew(2*N);
        for(int i=0;i<2*N;i++)
            cin>>skew[i];
        sort(skew.begin(),skew.end());
        /* for(int i=0;i<2*N;i++) */
            /* cout<<skew[i]<<endl; */
        
        int sum=0;
        for(int i=0;i<2*N;i=i+2)
            sum+=skew[i];
        cout<<sum<<endl;

        return 0;


    }
}
