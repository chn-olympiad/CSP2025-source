#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=510,M=998244353;
int n,m,ans=0,all;
bool s[N],st[N];
int a[N],c[N];
void dfs(int u)
{
	if(u>n)
	{
		int go=0,in=0;
		for(int i=1;i<=n;++i)
		{
			int x=c[i];
			if(s[i]==0)go++;
			else
			{
				if(go>=a[x])go++;
				else in++;
			}
		}
		if(in>=m)
		{
//			for(int i=1;i<=n;++i)
//				cout<<c[i]<<' ';
//			cout<<"\n";
			ans=(ans+1)%M;
		}
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!st[i])
		{
			st[i]=1;
			c[u]=i;
			dfs(u+1);
			st[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		char c;
		cin>>c;
		s[i]=c-'0';
		all+=s[i];
	}
	int a0=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)a0++;
	}
	if(max(n-all,a0)>m)
	{
		cout<<0;
		return 0;
	}
	if(m==n)
	{
		if(!(all!=n || a0))
		{
			ans=1;
			for(int i=n;i>=1;--i)
				ans=(LL)ans*i%M;
		}
	}
	else if(n<=11)dfs(1);
	cout<<ans;
	return 0;
}
//5 5
//11111
//1 2 3 4 5
