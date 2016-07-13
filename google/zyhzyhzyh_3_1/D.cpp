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
typedef long long LL;
#define PII pair<LL,LL>
using namespace std;
int T,n,K[20],L[20],a[20][20],c[20][20],m,cnt,cnt1,id[20];
LL ans,Max[10010];
PII H[10010],H1[10010];
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
void dfs(int l,int r,PII*H,int&cnt,PII now)
{
	if (now.fi>m) return;
	if (l==r+1)
	{
		H[++cnt]=now;return;
	}
	int u=id[l];
	dfs(l+1,r,H,cnt,MP(now.fi,now.se+a[u][L[u]]));
	for(int i=L[u];i<K[u];i++)
		if (now.fi+c[u][i]<=m)
		{
			now.fi+=c[u][i];
			dfs(l+1,r,H,cnt,MP(now.fi,now.se+a[u][i+1]));
		}
		else break;
}
LL Solve()
{
	cnt=cnt1=0;
	dfs(1,4,H,cnt,MP(0,0));
	dfs(5,8,H1,cnt1,MP(0,0));
	LL ans=0;
	sort(H+1,H+cnt+1);
	sort(H1+1,H1+cnt1+1);
	Max[0]=0;
	for(int i=1;i<=cnt1;i++) Max[i]=max(Max[i-1],H1[i].se);
	int now=cnt1;
	for(int i=1;i<=cnt;i++)
	{
		for(;now>0&&H1[now].fi+H[i].fi>m;now--);
		ans=max(ans,H[i].se+Max[now]);
	}
	return ans;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		read(m);read(n);
		for(int i=1;i<=n;i++)
		{
			read(K[i]);read(L[i]);
			for(int j=1;j<=K[i];j++) read(a[i][j]);
			for(int j=1;j<K[i];j++) read(c[i][j]);
		}
		ans=0;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0;
			for(int j=0;j<n;j++) 
				if ((i>>j)&1)
				{
					id[++cnt]=j+1;
				}
			if (cnt==8) ans=max(ans,Solve());
		}
		printf("%lld\n",ans);
	}
}


