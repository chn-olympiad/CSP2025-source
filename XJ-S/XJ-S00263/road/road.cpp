#include <iostream>
using namespace std;
int G[10010][10010][2];
int n,m,k,cnt=0;
long long int V[11],vw[11][10010];
int vis[10010]; 
bool dfs(int a, int b)
{
	if (a == b)
	{
		return 1;
	}
	for (int i=0;i<sizeof(G[a])/sizeof(G[a][0]);i++)
	{
		if (G[a][i][0] == 1)
		{
			vis[i] = 1;
			int get = dfs(i,b);
			if (get)
			{
				return 1;
			} 
			vis[i] = 0;
		}
	}
	return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int A=-1;
	int sum=0;
	cin >> n >> m >> k;
	for (int i=0;i<m;i++)
	{
		int x,y,w;
		cin >> x,y,w;
		G[x][y][0] = 0;
		G[x][y][1] = w;
		G[y][x][0] = 0;
		G[y][x][1] = w;
		sum += G[x][y][1];
//		G[cnt++].y = y;
//		G[cnt++].w = w;
	}
	for (int i=0;i<k;i++)
	{
		cin >> V[i];
		if (V[i] == 0)
		{
			A=i;
		}
		for (int j=0;j<=n;j++)
		{
			int w;
			cin >> w;
			vw[i][j] = w;
		}
	}
	cout << sum;
	return 0;
} 

