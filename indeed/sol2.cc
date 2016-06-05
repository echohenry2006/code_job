#include<iostream>
#include<vector>
#include<cassert>
#include<cmath>
#include<bitset>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;


typedef long long ll;

int main(int argc , char** argv)
{
    string str;
    ll m;
    int num;
    char ch;

    while(cin>>str>>m){
        for(ll i =0;i<m;i++){
            ch=str[0];
            num = ch-'0';
            //cout<<num<<endl;
            str.insert(num,1,ch);
            str.erase(0,1);
            cout<<str<<endl;
        }
        cout<<endl;
        cout<<str<<endl;
    }

    return 0;
}

