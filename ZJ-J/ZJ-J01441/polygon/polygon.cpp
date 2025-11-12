#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[100005],ans,shu[10005],he,t;
bool flag[100005];
void dfs(long long x,long long k,long long maxx,long long shang)
{
	if(x==k+1)
	{
		he=0;
		for(int i=1;i<=k;i++)
		{
			he+=shu[i];
		}
		if(he>maxx*2)
		{
			ans++;
			ans%=mod;
		}
	}
	else
	{
		for(int i=shang+1;i<=n;i++)
		{
			if(flag[i]==false)
			{
				flag[i]=true;
				shu[x]=a[i];
				dfs(x+1,k,max(maxx,a[i]),i);
				shu[x]=0;
				flag[i]=false;
			}
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=100LL)
	{
		for(long long i=3;i<=n;i++)
		{
			dfs(1LL,i,0LL,0LL);
		}
		cout<<ans;
	}
	else
	{
		for(long long k=3;k<=n;k++)
		{
			t=1;
			for(long long i=1;i<=k;i++)
			{
				t*=(n-i+1);
				t%=mod;
			}
			for(long long i=1;i<=k;i++)
			{
				t/=i;
				t%=mod;
			}
			ans+=t;
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}