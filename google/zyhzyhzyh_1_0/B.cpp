#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
using namespace std;
int n,m,T,a[51][51],xx[4]={1,-1,0,0},yy[4]={0,0,1,-1};
PII H[2510];
vector<PII> V[2510];
bool vis[51][51],go[51][51];
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
int bfs(int he,int sx,int sy)
{
	int t,w;
	H[t=w=1]=MP(sx,sy);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) go[i][j]=0;
	go[sx][sy]=1;
	while (t<=w)
	{
		int x=H[t].fi,y=H[t].se;
		t++;
		for(int i=0;i<4;i++)
		{
			int x1=x+xx[i],y1=y+yy[i];
			if (x1>0&&y1>0&&x1<=n&&y1<=m)
			{
				if (!vis[x1][y1]&&!go[x1][y1]) H[++w]=MP(x1,y1),go[x1][y1]=1;
			}
			else return 0;
		}
	}
	int ans=0;
	for(int i=1;i<=w;i++)
	{
		vis[H[i].fi][H[i].se]=1;
		ans+=he-a[H[i].fi][H[i].se];
	}
	return ans;
}
int Solve()
{
	int Max=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) vis[i][j]=0,Max=max(Max,a[i][j]);
	for(int i=0;i<=Max;i++) V[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) V[a[i][j]].PB(MP(i,j));
	int ans=0;
	for(int i=Max;i;i--)
	{
		for(int j=0;j<(int)V[i].size();j++)
		{
			vis[V[i][j].fi][V[i][j].se]=1;
		}
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++)
				if (!vis[x][y]) ans+=bfs(i,x,y);
	}
	return ans;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	read(T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		read(n);read(m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) read(a[i][j]);
		printf("%d\n",Solve());
	}
	return 0;
}

