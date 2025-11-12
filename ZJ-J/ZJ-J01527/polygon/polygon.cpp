#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,a[5005],ans,maxx=-1e9,len;
int b[5005];
int mod=998244353;

int f(int n)
{
	int ans=1;
	for(int i=2;i<=n;i++) ans*=i,ans%=mod;
	return ans;
}

int f2(int l,int r)
{
	int ans=1;
	for(int i=l;i<=r;i++) ans*=i,ans%=mod;
	return ans;
}

int C(int n,int m)
{
	return f2(n+1,m)/f(m-n)%mod;
}

void dfs(int now)
{
	if(now==len+1)
	{
		
		int sum=0,maxn=-1e9;
		for(int i=1;i<=len;i++)
		{
			sum+=a[b[i]];
			maxn=max(maxn,a[b[i]]);
		}
		if(sum>maxn*2)
		{
			ans++;
		}
		return;
	}
	for(int i=b[now-1]+1;i<=n;i++)
	{
		b[now]=i;
		dfs(now+1);
	}
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
	if(n==3)
	{
		cout<<(a[1]+a[2]+a[3]>maxx*2);
		return 0;
	}
	else
	{
		if(maxx==1)
		{
			for(int i=3;i<=n;i++)
			{
				ans+=C(i,n);
				ans%=mod;
			}
			cout<<ans%mod;
			return 0;
		}
		else
		{
			for(len=3;len<=n;len++)
			{
				dfs(1);	
			}
			cout<<ans;
			return 0;
		}
		
	}
	
	return 0;

}


