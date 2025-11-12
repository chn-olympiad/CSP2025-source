#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
int v,w,u;
int tong[10005][10005];
void panduan(int u,int v,int w)
{
	if(tong[u][v]>=0)
	{
		tong[u][v]=min(tong[u][v],w);
		return;
	}
	else
	{
		tong[u][v]=w;
		return;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	memset(tong,-1,sizeof(tong));
	for(int i=1;i<=m;i++)
	{
		cin>>u >> v >> w;
		panduan(u,v,w);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(tong[i][j]!=-1)
			{
				ans+=tong[i][j];
			}
		}
	}
	cout << ans;
	return 0;
}

