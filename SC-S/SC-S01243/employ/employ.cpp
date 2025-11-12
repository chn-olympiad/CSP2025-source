#include<bits/stdc++.h>
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
int n,m,ans,a[506],b[506];
string s;
void dfs(int x,int y,int z)
{
	if(y>=m)
	{
		int z=1;
		for(int i=1;i<=n-x+1;i++)
		{
			z*=i;
		}
		ans+=z;
		return;
	}
	if(x>n)
	{
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			if(z>=a[i]||s[x-1]=='0')
			{
				dfs(x+1,y,z+1);
			}
			else
			{
				dfs(x+1,y+1,z);
			}
			b[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}