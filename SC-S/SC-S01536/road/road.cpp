#include "bits/stdc++.h"
using namespace std;

#define int long long
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);
const int N = 1e4 + 15, M = 1e6 + 1e4 * 15 + 5, inf = 1e18;
int n, m, k, res;

struct Edge
{
	int u, v, w;
	int id = 0;
} e[M];
int idx, w[15];

int p[N], siz[N];

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

bool merge(int x, int y)
{
	int fax = find(x), fay = find(y);
	if (fax == fay) return true;
	if (siz[fax] < siz[fay]) swap(fax, fay);
	siz[fax] += siz[fay], p[fay] = fax;
	return false;
} 

void kc(int u, int pad)
{
	for (int i = 1; i <= n; ++ i) p[i] = i, siz[i] = 1;
	res = 0;
	for (int i = 1; i <= idx; ++ i)
	{
		if (e[i].id && !(e[i].id & pad)) continue;
		if (merge(e[i].u, e[i].v)) continue;
		
		res += e[i].w;
	}
}

int maxw = 0, maxc = 0, minw = inf;

signed main()
{
	file(road);
	cin >> n >> m >> k;
	n += k;
	
	for (int i = 1; i <= m; ++ i) 
	{
		idx ++;
		cin >> e[idx].u >> e[idx].v >> e[idx].w;
	}
	for (int i = 1; i <= k; ++ i)
	{
		cin >> w[i];
		maxw = max(maxw, w[i]);
		minw = min(minw, w[i]);
		for (int j = 1; j <= n - k; ++ j)
		{
			idx ++;
			e[idx].u = n - k + i;
			e[idx].v = j;
			e[idx].id = 1 << (j - 1);
			cin >> e[idx].w;
			maxc = max(maxc, e[idx].w);
		}
	}
	
	sort(e + 1, e + 1 + idx, [](const Edge &a, const Edge &b){
		return a.w < b.w;
	});
	
	if (maxc == 0 && maxw == 0)
	{
		cout << 0 << '\n';
		return 0;
	}
	if (maxc == 0)
	{
		kc(1, 0);
		cout << min(minw, res) << '\n';
		return 0;
	}
	
	int ans = inf, debt;
	for (int i = 0; i < (1 << k); ++ i)
	{
		kc(1, i);
		debt = 0;
		for (int j = 1; j <= k; ++ j) debt += (i & (1 << (j - 1))) ? w[j] : 0;
//		cerr << debt << ' ' << res << '\n';
		ans = min(ans, res + debt);
	}
	
	cout << ans << '\n';
	
	return 0;
}