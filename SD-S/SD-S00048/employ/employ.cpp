#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=500+10;
const int mod=998244353;
char s[M];
int a[M],vis[M],b[M];
ll ans=0;
int n,m;
ll f[M];
void dfs(int x)
{
	if(x==n)
	{
		int res=0;
		for(int i=1;i<=n;i++)
		{
			//printf("%d\n",b[i]);
			if(a[b[i]]<=res) res++;
			else if(s[i-1]=='0')  res++;
		}
		if(n-res>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			b[x+1]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
//	int flag=0;
//	for(int i=0;i<=n-1;i++)
//	{
//		if(s[i]=='0') flag=1;
//	}
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}

