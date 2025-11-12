#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,mod=998244353;
int a[N];
int n,ans;
void dfs(int x,int sum,int maxn)
{
	if(x==n+1)
	{
		if(2*maxn<sum)
		{
			ans++;
		}
		return;
	}
	dfs(x+1,sum+a[x],a[x]);
	dfs(x+1,sum,maxn);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20)
	{
		dfs(1,0,0);
		cout<<ans;
	}
	else
	{
		int sum=1;
		for(int i=1;i<=n;i++)
		{
			sum=sum*2%mod;
		}
		cout<<(sum-n-(n-1)*n/2-1+mod)%mod;
	}
	return 0;
}

