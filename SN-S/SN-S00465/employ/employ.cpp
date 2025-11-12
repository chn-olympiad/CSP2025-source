#include<bits/stdc++.h>
using namespace std;
char c[510];
int a[510];
int vis[510];
int b[510];
int n,m;
int cnt;
bool f(int p)
{
	int k=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(k<b[i])
		{
			k++;
			continue;
		}
		if(c[i]=='1')
		{
			k++;
			continue;
		}
		else
		{
			ans++;
		}
	}
	if(ans>m)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void dfs(int deep)
{
	if(deep==m)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
		if(f(1)==true)
		{
			cnt++; 
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			b[deep]=a[i];
			vis[i]=1;
			dfs(deep++);
			
			vis[i]=0;
			b[deep]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<cnt;
	return 0;
}
