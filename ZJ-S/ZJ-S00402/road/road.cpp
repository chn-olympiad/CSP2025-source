#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10005][10005],s[11][10005],ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		cin>>u>>v>>c;
		a[u][v]=c;
		a[v][u]=c;
		ans+=c;
	}
	for(int i=1;i<=k;i++)
	{
		int z;
		cin>>z;
		s[i][0]=z;
		for(int j=1;j<=n;j++)
		{
			cin>>z;
			s[i][j]=z;
		}
	}
	cout<<ans;
	
	return 0;
}
