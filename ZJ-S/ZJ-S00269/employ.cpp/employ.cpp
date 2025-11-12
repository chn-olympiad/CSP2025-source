#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],b[510],t=0,ans;
string s;
void dfs(int x,int y)
{
	if(x==n)
	{
		if(y>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(t>=1e7)
		{
			return;
		}
		if(s[x]='1'&&b[i]==0&&a[i]>x-y)
		{
			b[i]=1;
			dfs(x+1,y+1);
			b[i]=0;
		}
		if(s[x]='0'&&b[i]==0&&a[i]>x-y)
		{
			b[i]=1;
			dfs(x+1,y);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}