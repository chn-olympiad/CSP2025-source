//4¸öµã°æ 
#include <bits/stdc++.h>
using namespace std;
vector<int> vt[1000005];
int a[1000][1000];
int a1[1000][1000];
int a2[1000][1000];
int b2[1000];
int n,m,k;
void dfs(int p,int f)
{
	if(b2[f]>n-1)
	{
		return;
	}
	for(int i=0;i<vt[p].size();i++)
	{
		if(vt[p][i]!=f&&a2[f][vt[p][i]]==0)
		{
			a2[f][vt[p][i]]++;
			a2[vt[p][i]][f]++;
			b2[f]++;
			dfs(vt[p][i],f);
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		vt[u].push_back(v);
		vt[v].push_back(u);
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin >> a1[i][0];
		for(int j=1;j<=n;j++)
		{
			cin >> a1[i][j];
		} 
	}
	for(int i=1;i<=n;i++)
	{
		dfs(1,i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a2[i][j]!=0)
			{
				ans+=a[i][j];
				a2[i][j]=0;
			}
		}
	}
	cout << ans;
	return 0;
}
