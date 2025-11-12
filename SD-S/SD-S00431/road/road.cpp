#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e4 + 10;

typedef long long LL;
 
int n, m, k;
struct Edge{
	int u, v;
	LL w;
};
vector<Edge> e;

int c[15];
int p[N + 10];
int find(int x)
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}
bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for(int i = 1; i <= n + k; i++)
	{
		p[i] = i;
		e.push_back((Edge){0, n, 0});
	} 
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back((Edge){u, v, w});
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			LL w;
			cin >> w;
			e.push_back((Edge){n + i, j, w});
		}
	}
	sort(e.begin(), e.end(), cmp); 
	LL res = 0;
	for(int i = 0; i < e.size(); i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if(fu != fv)
		{
			p[fu] = fv;
			res = res + w;
		} 
	}
	cout << res << endl;
	return 0;
}

