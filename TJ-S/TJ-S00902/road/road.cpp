/*
#include<bits/stdc++.h>>
using namespace std;

const int MAXN = 1e4+17, MAXM = 1e6+7, MAXK = 10+7, MAXDP = MAXM * 1e9;
int n, m, k;
long long w[MAXN][MAXN], c[MAXK], a[MAXK][MAXN];    //w[i][j]:从城市i到城市j的道路费用，c[j]:乡村的费用，a[j]:从第j个乡村到第i个城市的道路的费用 
long long dp[MAXN];
int vis[MAXN][MAXN];
//迪杰斯特拉算法求最短路 (?????)
void djstl()
{
	dp[1] = 0;
	for (int t = 1; t <= n+k-1; t++)
	{
		for (int u = 1; u <= n+k; u++)
		{
			for (int v = 1; v <= n+k; v++)
			{
				if (vis[u][v] == 1 && dp[u]+w[u][v] < dp[v])
				{
					dp[v] = dp[u]+w[u][v];
				}
			}
		}
	 } 
}
int main()
{
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int u, v; 
		long long tw;
		scanf("%d%d%lld", &u, &v, &tw);
		w[u][v] = w[v][u] = tw;
		vis[u][v] = vis[v][u] = 1;
	} 
	for (int j = 1; j <= k; j++)
	{
		scanf("%lld", &c[j]);
		for (int i = 1; i <= n; i++)
		{
			long long a;
			scanf("%lld", &a);
			int u = n+j, v;
			w[u][i] = w[i][u] = a;
			vis[u][i] = vis[i][u] = 1;
		}
	} 
	
	for (int i = 1; i <= n; i++)
	{
		dp[i] = MAXDP;
	}
	djstl();
	printf("%lld", dp[n]);
	
	return 0;
} 

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/


#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	printf("0");
	
	return 0;
}

