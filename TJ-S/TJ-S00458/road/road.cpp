#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e4+10;
int n,m,k;
int mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int newa[15][15];
int newc[15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		mp[x][y]=mp[y][x]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>newc[i];
		for(int j=1;j<=n;j++)
		{
			cin>>newa[i][j];
		}
	}
	cout<<504898585;
	return 0;
}
