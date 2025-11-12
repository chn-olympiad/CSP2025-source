/*
StarLight_Yuran_ovo
Never gonna let you down
winter cube
JROI 2023~无限
Starlight OI 2024~无限
RP++
648647291436
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int n,m,k;
int dis[N][N];
void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<N;i++)
	{
		for(int j=1;j<N;j++)
		{
			dis[i][j]=INT_MAX;
			if(i==j)
			{
				dis[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=w;
		dis[v][u]=w;
	}
	floyd();
	cout<<dis[1][n];
	return 0;
}
//某谷 1.1k 犇犇网红笑传之我是奶龙我不会写 dijkstra！
//随手乱糊 floyd，O(n^3) 的破玩意儿能拿多少是多少。
