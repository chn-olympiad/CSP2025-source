#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
int mp[N][N];
struct road{
	int c;
	int pr[N];
}r[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	int p=m;
	for(int i=1;i<=k;i++)
	{
		cin >> r[i].c;
		for(int j=1;j<=n;j++)
		{
			cin >> r[i].pr[j];
			mp[++p][j]=r[i].pr[j];
			mp[j][p]=r[i].pr[j];
		}
	}
}