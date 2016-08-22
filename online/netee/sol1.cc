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




int main(int argc , char** argv) {
    int n;
    while(cin>>n){
        vector<int> a(n,0);
        vector<int> diff(n,0);
        int total=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            total+=a[i];
        }
        if(total%n!=0){
            cout<<-1<<endl;
            break;
        }
        int ave=total/n;
        int flag=0;
        int sum=0;
        for(int i=0;i<n;i++){
            diff[i]=ave-a[i];
            if(diff[i]%2!=0)
                flag=1;
            if(diff[i]>0)
                sum+=diff[i]/2;
        }
        if(flag==1){
            cout<<-1<<endl;
            break;
        }
        
        cout<<sum<<endl;
        

    }
}
