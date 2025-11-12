#include<bits/stdc++.h>
using namespace std;
long long n,m,s[1005],ans,a[1005],f,u[1005],ss,cc;
char c;
int mod=998244353;
void dfs(int x,int y,int z)
{
	if(z>n-m)
		return;
	if(x>n)
	{
		if(y>=m)
			ans++;
		ans%=mod;
		return;
	}
	if(y==m)
	{
		cc=1;
		for(int i=1;i<=n-x+1;i++)
		{
			cc*=i;
			cc%=mod;
		}
		ans+=cc;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!u[i])
		{
			if(a[x])
			{
				if(s[i]>z)
				{
					u[i]=1;
					dfs(x+1,y+1,z);
					u[i]=0;
				}
				else
				{
					u[i]=1;
					dfs(x+1,y,z+1);
					u[i]=0;
				}
			}
			else
			{
				u[i]=1;
				dfs(x+1,y,z+1);
				u[i]=0;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='1')
			a[i]=1;
		if(c=='0')
			f=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	if(!f)
	{
		ss=1;
		for(int i=1;i<=n;i++)
		{
			ss*=i;
			ss%=mod;
		}
		cout<<ss;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
