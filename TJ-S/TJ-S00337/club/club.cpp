#include <bits/stdc++.h>
using namespace std;

namespace p1
{
	const int MAXN = 35;
	const int MAXL = 20;
	int n, mx, t;
	int hasmem[MAXN][MAXL][MAXL][MAXL];
	struct student
	{
		int a1, a2, a3;
	}stu[MAXN];
	
	int dfs(int p, int d1, int d2, int d3)
	{
		if(p > n) return 0;
		if(hasmem[p][d1][d2][d3] != -1) return hasmem[p][d1][d2][d3];
		int ans = 0;
		if(d1 < mx)
			ans = dfs(p + 1, d1 + 1, d2, d3) + stu[p].a1;
		if(d2 < mx)
			ans = max(ans, dfs(p + 1, d1, d2 + 1, d3) + stu[p].a2);
		if(d3 < mx)
			ans = max(ans, dfs(p + 1, d1, d2, d3 + 1) + stu[p].a3);
		return hasmem[p][d1][d2][d3] = ans;
	}
	
	void solve()
	{
		scanf("%d", &t);
		while(t--)
		{
			scanf("%d", &n);
			mx = n >> 1;
			for(int i = 1; i <= n; i++) scanf("%d%d%d", &stu[i].a1, &stu[i].a2, &stu[i].a3);
			for(int i = 0; i <= n; i++)
			{
				for(int j = 0; j <= mx; j++)
				{
					for(int k = 0; k <= mx; k++)
					{
						for(int b = 0; b <= mx; b++) hasmem[i][j][k][b] = -1;
					}
				}
			}
			printf("%d\n", dfs(1, 0, 0, 0));
		}
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	p1::solve();
	return 0;
}
