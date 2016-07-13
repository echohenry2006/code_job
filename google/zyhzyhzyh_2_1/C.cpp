#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
using namespace std;
int a[110],n,Te;
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&Te);
	for(int _=1;_<=Te;_++)
	{
		printf("Case #%d: ",_);
		read(n);
		for(int i=0;i<=n;i++) read(a[i]);
		double L=-1,R=1;
		for(int i=1;i<=100;i++)
		{
			double mid=(L+R)/2;
			double sum=-a[0];
			for(int i=1;i<=n;i++)
			{
				sum=sum*(1+mid)+a[i];
			}
			if (sum>0) L=mid;else R=mid;
		}
		printf("%.12lf\n",L);
	}
}


