#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
ll n,m,k,g[N][N],p[15][N],ans=0,f[N],fi=0;
bool st[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			g[i][j]=INT_MAX;
			g[j][i]=INT_MAX;
		}
	}
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++) cin>>p[i][j];
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int ti=g[i][j],tj;
			for(int h=1;h<=k;h++)
			{
				if(st[h]==0){
					tj=p[h][0]+p[h][i]+p[h][j];
					if(ti>=tj)
					{
						st[h]=1;
						ti=tj-p[h][0];
					}
				}else{
					tj=p[h][i]+p[h][j];
					ti=min(ti,tj);
				}
			}
			g[i][j]=ti;
			g[j][i]=ti;
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(st[i]==1) ans+=p[i][0];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			f[++fi]=g[i][j];
		}
	}
	sort(f+1,f+1+fi);
	for(int i=1;i<=n-1;i++) ans+=f[i];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}