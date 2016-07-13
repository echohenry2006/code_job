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


struct node
{
    int A[13],C[13];
    int K,L;
};

node a[15];
node b[15];

int m,n;

pair<long long,long long> A[10005],B[10005];


int Init(pair<long long,long long> A[],node a,node b,node c,node d)
{
    int Num=0;
    long long as=0;
    for(int i=a.L;i<=a.K;as+=a.C[i++])
    {
        long long ValueA=a.A[i];
        long long bs=0;
        for(int j=b.L;j<=b.K&&as+bs<=m;bs+=b.C[j++])
        {
            long long ValueB=b.A[j];
            long long cs=0;
            for(int t=c.L;t<=c.K&&as+bs+cs<=m;cs+=c.C[t++])
            {
                long long ValueC=c.A[t];
                long long ds=0;
                for(int p=d.L;p<=d.K&&as+bs+cs+ds<=m;ds+=d.C[p++])
                {
                    long long ValueD=d.A[p];
                    if(as+bs+ds+cs<=m)
                    {
                        A[++Num]=make_pair(ValueA+ValueB+ValueC+ValueD,as+bs+cs+ds);
                    }
                }
            }
        }
    }
    return Num;
}

long long f[10005],dp[10005];

long long cal()
{
    int Num1=Init(A,b[1],b[2],b[3],b[4]);
    int Num2=Init(B,b[5],b[6],b[7],b[8]);
    for(int i=1;i<=Num1;++i) f[i]=A[i].second;


    sort(f+1,f+Num1+1);
    int M=unique(f+1,f+Num1+1)-(f+1);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=Num1;i++)
    {
        int t=lower_bound(f+1,f+M+1,A[i].second)-f;
        dp[t]=max(dp[t],A[i].first);
    }
    for(int i=2;i<=M;i++) dp[i]=max(dp[i],dp[i-1]);
    long long Ans=0;
    for(int i=1;i<=Num2;++i)
    {
        long long K=m-B[i].second;
        int t=upper_bound(f+1,f+M+1,K)-f-1;
        if(t) Ans=max(Ans,B[i].first+dp[t]);
    }
    return Ans;
}

void Deal()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&a[i].K,&a[i].L);
        for(int j=1;j<=a[i].K;++j) scanf("%d",&a[i].A[j]);
        for(int j=1;j<a[i].K;++j) scanf("%d",&a[i].C[j]);
    }
    long long Ans=0;

    for(int i=0;i<(1<<n);i++)
    {
        int Num=0;
        for(int j=0;j<n;j++) if(i&(1<<j)) ++Num;
        if(Num==8)
        {
            Num=0;
            for(int j=0;j<n;j++) if(i&(1<<j)) b[++Num]=a[j+1];
            long long Tmp=cal();
            if(Tmp>Ans) Ans=Tmp;
        }
    }
    printf("%lld\n",Ans);
}

int main()
{
   freopen("D-large.in","r",stdin);
    freopen("ans","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        printf("Case #%d: ",i);
        Deal();
    }
}
/**
3
3
10000 3000 4000 5000
5
3000 100 100 100 100 100
*/
