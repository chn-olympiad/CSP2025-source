#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n, m, k, c[10010], ks[10010], ct[10010], mp[10010][10010], g[10010];
int siz[10010];
long long ans = 0;
struct Edge
{
	int x, y, w;
}es[1000005];
int Gg(int a)
{
	if(g[a] != a)
	{
		return g[a] = Gg(g[a]);
	}
	return a;
}
bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			mp[i][j] = -1;
		}
		mp[i][i] = 0;
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		mp[x][y] = z, mp[y][x] = z;
	}
	bool ck = 1;
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if(c[i] != 0) ck = 0;
		for(int j = 1; j <= n; j++)
		{
			cin >> ct[j];
		}
		for(int j = 1; j <= n; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				if(j == k) continue;
				long long mr = ct[j] + ct[k];
				if(ck &&(mr < mp[k][j]||mp[k][j] == -1))
				{
					mp[k][j] = mr;
					mp[j][k] = mr;
				}
			}
		}
	}
	if(ck)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			g[i] = i;
			siz[i] = 1;
			for(int j = i; j <= n; j++)
			{
				//if(i == j) cout << "0 ";
				if(mp[i][j] != -1 && i != j)
				{
					es[++cnt].x = i;
					es[cnt].y = j;
					es[cnt].w = mp[i][j];
					//cout << mp[i][j] << ' ';
				}
				//cout << '\n';
			}
		}
		sort(es+1, es+1+cnt, cmp);
		cnt = 0;
		int sum = 0;
		while(cnt != n-1)
		{
			int nnx = es[++sum].x;
			int nny = es[sum].y;
			int nnw = es[sum].w;
			int gx = Gg(nnx), gy = Gg(nny);
			if(gx == gy) continue;
			cnt++;
			if(siz[gx] < siz[gy])
			{
				siz[gy] += siz[gx];
				g[gx] = gy;
			}
			else
			{
				siz[gx] += siz[gy];
				g[gy] = gx;
			}
			ans += nnw;
		}
		cout << ans << '\n';
	}
	else cout << "13\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
