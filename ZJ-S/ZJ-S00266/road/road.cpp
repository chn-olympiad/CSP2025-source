#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k;
LL res;
struct Edge
{
	int a, b, c;
	bool operator < (const Edge &w) const
	{
		return c < w.c;
	}
}edge[M];
int p[N];
int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
void kruskal()
{
	for(int i = 1; i <= n; i ++) p[i] = i;
	sort(edge + 1, edge + m + 1);
	for(int i = 1; i <= m; i ++)
	{
		int a = edge[i].a, b = edge[i].b, c = edge[i].c;
		a = find(a), b = find(b);
		if(a != b) p[a] = b, res += c;
	}
	printf("%d\n", res);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int a, b, c;
	for(int i = 1; i <= m; i ++)
	{
		scanf("%d%d%d", &a, &b, &c);
		edge[i] = {a, b, c};
	}
	kruskal();
	
	return 0;
}

