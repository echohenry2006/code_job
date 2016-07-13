#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<bitset>
#include<utility>
#include<cmath>
#include<ctime>

using namespace std;

int main(int argc, char *argv[])
{
    int cnt[26]={0};
    
    int T,N;
    while(cin>>T){
        for(int n_case=0;n_case<T;n_case++){
            cin>>N;
            vector<string> strs;
            vector<string> ties;
            vector<int> lens;
            int maxn=0;
            string str;
            getline(cin,str);
            for(int i=0;i<N;i++){
                getline(cin,str);
                //cout<<"***"<<str<<endl;
                //cin>>str;
                strs.push_back(str);
            }
            /* for(int i=0;i<N;i++) */
                /* cout<<strs[i]<<endl; */
            for(int i=0;i<N;i++){
                memset(cnt,0,26);
                int namelen=0;
                string str=strs[i];
                for(int j=0;j<str.size();j++)
                    if(str[j]!=' ')
                        cnt[str[j]-'A']++;
                for(int j=0;j<26;j++)
                    if(cnt[j]!=0)
                        namelen++;
                if(namelen>maxn)
                    maxn=namelen;
                lens.push_back(namelen);

            }
            for(int i=0;i<N;i++)
                if(lens[i]==maxn)
                    ties.push_back(strs[i]);
            string bigname=ties[0];
            for(int i=1;i<ties.size();i++)
                if(ties[i]<bigname)
                    bigname=ties[i];
            cout<<"Case #"<<n_case+1<<": "<<bigname<<endl;
                
                

        }
    }
    return 0;
}
