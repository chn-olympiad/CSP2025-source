#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a[5005];
int ans;
ll f[505][50005];
ll g[505][50005];
void dfs(int x,int high,int sum)
{
	if(x>n)
	{
		if(sum>high*2)
		{
			ans++;
		}
		return;
	}
	dfs(x+1,high,sum);
	dfs(x+1,a[x],sum+a[x]);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=20)
	{
		dfs(1,0,0);
		cout<<ans;
	}
	else if(maxx==1)
	{
		ll p=1;
		for(int i=1;i<=n;i++)
		{
			p=(p*2)%998244353;
		}
		ll mn=1ll+n+n*(n-1)/2;
		p=(p+998244353-mn)%998244353;
		cout<<p;
	}
	else
	{
		//f[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				g[j][a[i]+a[j]]++;
				//f[j][a[i]+a[j]]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=50000;j++)
			{
				f[i][j]=(f[i][j]+f[i-1][j])%998244353;
				g[i][j]=(g[i][j]+g[i-1][j])%998244353;
				if(j-a[i]>=0)
				{
					if(j>2*a[i])
					{
						f[i][j]=(f[i][j]+f[i-1][j-a[i]]+g[i-1][j-a[i]])%998244353;
					}
					else
					{
						g[i][j]=(g[i][j]+g[i-1][j-a[i]]+f[i-1][j-a[i]])%998244353;
					}
				}
			}
		}
		ll summ=0;
		for(int i=2;i<=50000;i++)
		{
			summ=(summ+f[n][i])%998244353;
		}
		//cout<<(summ+998244353-n*(n-1)/2)%998244353;
		cout<<summ;
	}
	return 0;
}
