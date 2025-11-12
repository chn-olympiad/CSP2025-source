#include <bits/stdc++.h>
using namespace std;
int n , m , k , c[15] , a[15][10005] , fa[10005] , u , v , cnt , p;
long long w , ans;
struct Edge{
	int u , v;
	long long w;
}edge[1000005];
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x , int y)
{
	x = find(x) , y = find(y);
	fa[x] = y;
}
bool f = 1 , f2 , f3 = 1;
bool cmp(Edge a , Edge b)
{
	return a.w < b.w;
}
void kruskal()
{
	sort(edge + 1 , edge + 1 + m , cmp);
	for (int i = 1;i <= m;i ++)
	{
		u = edge[i].u , v = edge[i].v , w = edge[i].w;
		if  (find(u) != find(v))
		{
			merge(u , v);
			ans += w;
			++ cnt;
		}
		if  (cnt == n - 1)
		{
			cout << ans;
			exit(0);
		}
	}
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i ++) fa[i] = i;
	if  (!k) f = 1;
	for (int i = 1;i <= m;i ++)
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	for (int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		if  (c[i]) f = 0;
		f2 = 0 , p = 0;
		for (int j = 1;j <= n;j ++)
		{
			cin >> a[i][j];
			if  (!a[i][j])
			{
				f2 = 1;
				if  (!p) p = j;
				else if  (find(p) != find(j))
				{
					merge(p , j);
					++ cnt;
				}
			}
		}
		if  (!f2) f3 = 0;
	}
	for (int i = 1;i <= m;i ++)
	{
		u = edge[i].u , v = edge[i].v;
		if  (find(u) == find(v)) edge[i].w = 0;
	}
	if  (f && f3) kruskal();
	return 0;
}
