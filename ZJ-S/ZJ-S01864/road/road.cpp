#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5 ;
int n,m,k,ans=0x3f3f3f3f; 
int c[15],a[15][maxn];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=k;i++)
	{
		int res=c[i];
		for(int j=1;j<=n;j++)
			res+=a[i][j];
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
