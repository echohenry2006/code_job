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
char s[30];
string ans;
int n,T,b[30];
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	read(T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		read(n);
		int Max=0;
		for(int i=1;i<=n;i++)
		{
			gets(s);
			memset(b,0,sizeof(b));
			int l=strlen(s);
			for(int j=0;j<l;j++)
				if (s[j]>='A'&&s[j]<='Z') b[s[j]-'A']=1;
			int sum=0;
			string tmp=s;
			for(int i=0;i<26;i++) sum+=b[i];
			if (sum>Max)
			{
				Max=sum;
				ans=s;
			}
			else if (sum==Max&&tmp<ans) ans=tmp;
		}
		cout << ans << endl;
	}
	return 0;
}
