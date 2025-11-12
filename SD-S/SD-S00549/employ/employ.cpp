#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string s;
int a[510];
int p[510];
int cnt=0;
void dfs(int x)
{
	if(x==n+1)
	{
		int cf=0;
		int cr=0;
		for(int i=1;i<=n;++i)
		{
			if(cf>=a[p[i]])
			{
				cf++;
				continue;
			}
			else
			{
				if(s[i]=='0')
				{
					cf++;
				}
				else
				{
					cr++;
				}
			}
		}
		if(cr>=m)
		{
			cnt++;
			cnt%=mod;
		}
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			p[x]=i;
			dfs(x+1);
		}
	}
}
signed main()
{

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	} 
	if(n<=10)
	{
		dfs(1);
		cout<<cnt<<"\n";
		return 0;
	}
	int cf0=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=0)
		{
			cf0++;
		}
	}
	if(cf0<=m)
	{
		cout<0;
	}
	int k=n-cf0;
	int ans=1;
	for(int i=1;i<=k;++i)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}

