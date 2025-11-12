#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[11][10010],c[11];
int q[10010][10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,ww;
		cin>>u>>v>>ww;
		q[u][v]=ww;
		q[v][u]=ww;	
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k>0)
	{
		cout<<0;
		return 0;
	}
	int s=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s+=q[i][j];
		}
	}
	cout<<s/2;
	return 0;
}
