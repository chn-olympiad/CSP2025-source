#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[505],b[505],c[505],vis[505],sum[505];
long long t[505];
long long ans;
int n,m;
long long fact(int x)
{
	long long qq=1;
	for(int i=1;i<=x;i++)
		qq*=i,qq%=mod;
	return qq;
}
void dfs(int dep,int p,int cnt)
{
	if(cnt==m)
	{
		ans+=fact(n-dep+1);
		ans%=mod;
		return ;
	}
	if(dep>n&&cnt>=m)
	{
		//cout<<dep<<" "<<p<<" "<<cnt<<endl;
		ans++;
		ans%=mod;
		return ;
	}
	if(dep>n||cnt+sum[n]-sum[dep-1]<m)
	{
		//cout<<dep<<" "<<p<<" "<<" "<<dep<<" "<<c[n]-c[dep-1]<<endl;
		return ;
	}
	if(a[dep]==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				vis[i]=1;
				dfs(dep+1,p+1,cnt);
				vis[i]=0;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				if(b[i]>p)
				{
					vis[i]=1;
					dfs(dep+1,p,cnt+1);
					vis[i]=0;
				}
				else
				{
					vis[i]=1;
					dfs(dep+1,p+1,cnt);
					vis[i]=0;
				}
			}
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		a[i]+=c-'0';
		sum[i]=a[i]+sum[i-1];	
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		c[b[i]]++;
	}
	if(m==n)
	{
		if(c[0])
		{
			cout<<0<<endl;
			return 0;
		}
		if(sum[n]<n)
		{
			cout<<0<<endl;
			return 0;
		}
		cout<<fact(n)<<endl;
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
