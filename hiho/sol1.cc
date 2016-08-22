#include<iostream>
#include<bitset>
#include<vector>
#define MAXINT 999999999999999
using namespace std;

int main(){
    bitset<20> bitvec;
    long long N;
    long long X;
    while(cin>>N>>X){
        vector<long long> a(N);
        for(long long i=0;i<N;i++)
            cin>>a[i];
        long long sum=0;
        long long ret=MAXINT;
        for(long long i=0;i<(1<<N);i++){
            bitset<21> vec(i);
            sum=0;
            for(long long j=0;j<N;j++)
                if(vec[j])
                     sum+=a[j];
            if(sum>=X && sum<ret)
                ret=sum;
                    
        }
        if(ret>=X && ret != MAXINT) 
            cout<<ret<<endl;
        else
            cout<<-1<<endl;
        
    }
    return 0;
}