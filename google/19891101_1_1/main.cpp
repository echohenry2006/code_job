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

int n,m;
int a[N][N];



int inq[N][N];



const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};


int check(const int x,const int y,int h)
{
    h+=a[x][y];

    queue<pair<int,int> > Q;
    Q.push(make_pair(x,y));
    memset(inq,0,sizeof(inq));

    inq[x][y]=1;
    while(!Q.empty())
    {
        const int x=Q.front().first;
        const int y=Q.front().second;
        Q.pop();
        if(x==0||x==n+1||y==0||y==m+1)
        {
            return 1;
        }
        for(int i=0;i<4;++i)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(!inq[xx][yy]&&h>a[xx][yy])
            {
                inq[xx][yy]=1;
                Q.push(make_pair(xx,yy));
            }
        }
    }

    return 0;
}

int CalAns(const int x,const int y)
{
    int low=1,high=1000,ans=0;
    while(low<=high)
    {
        int Mid=(low+high)>>1;
        if(check(x,y,Mid)) high=Mid-1;
        else ans=max(ans,Mid),low=Mid+1;
    }
    return ans;
}

void Deal()
{
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j) scanf("%d",&a[i][j]);
    }
    int ans=0;
    for(int i=2;i<=n-1;++i)
    {
        for(int j=2;j<=m-1;++j)
        {
            ans+=CalAns(i,j);
        }
    }
    printf("%d\n",ans);
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("ans","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        printf("Case #%d: ",i);
        Deal();
    }
}
