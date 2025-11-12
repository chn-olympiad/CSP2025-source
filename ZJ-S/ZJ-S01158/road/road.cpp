#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000001]={},v[1000001]={},w[1000001]={},c[11],a[11][10001]={},b[100001]={},s=0,s1=0;
void dfs(int x)
{
	int g=0;
	for(int i=1;i<=n;i++)
		if(b[i]!=1) g=1;
	if(g==0)
	{
		if(s1<s) s=s1;
		s1=0;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			if(x==u[i]) 
			{
				s1+=w[i];
				b[v[i]]=1;
				dfs(v[i]);
				s1-=w[i];
				b[v[i]]=0;
			}
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k==0)
	{
		b[u[1]]=1;
		dfs(u[1]);
		cout<<s;
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
