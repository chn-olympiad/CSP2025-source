#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],b[N],pr[N];
ll ans;
bool flag=true,f[N];
void dfs(int p)
{
	if (p==n+1)
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if (cnt<a[pr[i]]&&b[i]==1)
				sum++;
			else
				cnt++;
		}
		if (sum>=m)
			ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if (!f[i])
		{
			f[i]=true;
			pr[p]=i;
			dfs(p+1);
			f[i]=false;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		b[i]=c-'0';
		if (b[i]==0)
			flag=false;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if (n<=10)
	{
		dfs(1);
		cout<<ans<<"\n";
	}
	if (flag)
	{
		ans=1;
		for(int i=2;i<=n;i++)
			ans=ans*i%mod;
		cout<<ans<<"\n";
	}
}
