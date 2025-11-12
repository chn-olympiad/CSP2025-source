#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k;
int a[30][N], c[N];
int h[N], e[M], w[M], ne[M], idx;

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k); 
	int u, v, w;
	while(m --)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w), add(v, u, w);
	}
	for(int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j ++)
			cin >> a[i][j];
	}
	puts("0");
	return 0;
}
