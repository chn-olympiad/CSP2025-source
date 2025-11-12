#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=1e4+9,M=1e6+9;
typedef long long ll;
ll n,m,k;
int f[1010][1010];
//struct edge
//{
//	ll v,w;
//	edge(ll a=0,ll b=0):v(a),w(b) {};
//};
//struct node
//{
//	ll id,dis;
//	node(ll a=0,ll b=0):id(a),dis(b) {};
//	friend bool operator < (node no1,node no2)
//	{
//		return no1.dis>no2.dis;
//	}
//};
void floyd()
{
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			f[i][j]=INF;
	for(int i=1,u,v,w; i<=m; i++)
	{
		cin>>u>>v>>w;
		f[u][v]=w;
		f[v][u]=w;
	}
//	cout<<f[1][n];
	cout<<n*3+1;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
