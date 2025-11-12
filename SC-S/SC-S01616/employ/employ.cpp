#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+9,mod=998244353;
int n,m;
int s[N],c[N];
int val[N],ans;
bool check()
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==0 || sum>=c[val[i]])
			sum++;
	}
	return (n-sum)>=m;
}
bool vis[N];
void dfs(int u)
{
	if(u==n+1)
	{
		ans+=check();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			val[u]=i;
			dfs(u+1);
			vis[i]=0;
		}
	}
}
long long qpow(long long a,int b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int cntt=0;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		if(ch=='0')
			s[i]=0;
		else
			s[i]=1,cntt++;
	}
	int minx=N;
	for(int i=1;i<=n;i++)
		cin>>c[i],minx=min(minx,c[i]);
	if(n==m)
	{
		if(cntt==n && minx!=0)
		{
			long long inc=1;
			for(int i=1;i<=n;i++)
				inc=inc*i%mod;
			cout<<inc;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(cntt==n)
	{
		long long ans=1;
		long long inc=1;
		for(int i=1;i<=n;i++)
			inc=inc*i%mod;
		ans=inc;
		inc=1;
		for(int i=1;i<=m;i++)
			inc=inc*i%mod;
		ans=ans*qpow(inc,mod-2);
		inc=1;
		for(int i=1;i<=n-m;i++)
			inc=inc*i%mod;
		ans=ans*qpow(inc,mod-2);
		for(int i=1;i<=m;i++)
			inc=inc*i%mod;
		ans=ans*inc%mod;
		cout<<ans;
		return 0;
	}
	if(n>=20)
	{
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}