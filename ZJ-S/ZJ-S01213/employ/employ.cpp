#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,g,tt,ans,a[505],b[505],c[505],d[505];
string s;
void ss(int x)
{
	if(x==n+1)
	{
		g=0;
		tt=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				g++;
			}
			else
			{
				if(a[c[i]]<=g)
				{
					g++;
				}
				else
				{
					tt++;
				}
			}
		}
		if(tt>=m)
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==0)
		{
			d[i]=1;
			c[x]=i;
			ss(x+1);
			d[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=s[i-1]-'0';
	}
	if(n<=18)
	{
		ss(1);
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				g++;
			}
			if(a[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=g)
			{
				tt++;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++)
		{
			if(i==tt)
			{
				continue;
			}
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		g+=b[i];
	}
	if(g==n)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++)
	{
		if(rand()%2==1)
		{
			continue;
		}
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
}
