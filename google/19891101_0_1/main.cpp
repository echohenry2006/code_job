#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <set>
#include <vector>
#include <queue>

using namespace std;



const int N=105;
const int mod=1000000007;


char s[N];

int n;


int CalDiffAlpNum(std::string& S)
{
    int a[26];
    memset(a,0,sizeof(a));
    for(int i=0;i<S.size();++i)
    {
        if(S[i]>='A'&&S[i]<='Z') a[S[i]-'A']=1;
    }
    int nAns=0;
    for(int i=0;i<26;i++) nAns+=a[i];
    return nAns;
}

void Deal()
{
    std::string sAns="";
    int nNum=0;
    scanf("%d\n",&n);
    for(int i=0;i<n;++i)
    {
        gets(s);
        std::string S=s;
        int nTmp=CalDiffAlpNum(S);
        if(nTmp>nNum||nTmp==nNum&&S<sAns)
        {
            sAns=S;
            nNum=nTmp;
        }
    }
    puts(sAns.c_str());
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("ans","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        printf("Case #%d: ",i);
        Deal();
    }
}
