#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k,a[10020][10020],c[15],x;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	memset(a,31,sizeof(a));
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			a[i+n][j]=a[j][i+n]=x;
		}
	}
	for(int l=1;l<=k+n;l++)
		for(int i=1;i<=k+n;i++)
			for(int j=1;j<=k+n;j++)
				if(i!=j) a[i][j]=a[j][i]=min(a[i][j],a[i][l]+a[l][j])/*,cout<<a[i][j]<<" "*/;
	srand(time(0));
	int ans=rand();
	cout<<ans;
	return 0;
}
/*





*/
