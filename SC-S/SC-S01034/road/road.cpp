#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define V vector
#define x first
#define y second
using namespace std;

struct node
{
	int go, to, len;
};

const int maxn = 1e4;

int fa[maxn + 5];
int find(int x)
{return x == fa[x] ? x : fa[x] = find(fa[x]);}

ll get(const V<node>& nE, int n, int N)
{
	for(int i = 1; i <= N; ++i)
		fa[i] = i;
	ll ans = 0;
	int cnt = n;
	for(int i = 0; i < nE.size() && cnt > 1; ++i)
	{
		int x = nE[i].go;
		int y = nE[i].to;
		int len = nE[i].len;
		int fx = find(x), fy = find(y);
		if(fx == fy) continue;
//		cout << ' ' << x << ' ' << y << ' ' << len << '\n';
		ans += len;
		fa[fx] = fy;
		--cnt;
	}
	return ans;
}

bool operator < (const node& a, const node& b)
{return a.len < b.len;}

V<node> merge(const V<node>& a, const V<node>& b)
{
	int i, j;
	i = j = 0;
	V<node> c;
	while(i < a.size() && j < b.size())
		if(a[i].len < b[j].len) c.push_back(a[i]), ++i;
		else c.push_back(b[j]), ++j;
	while(i < a.size())
		c.push_back(a[i]), ++i;
	while(j < b.size())
		c.push_back(b[j]), ++j;
	return c;
}

V<V<node>> mp;

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	V<node> E;
	for(int i = 1; i <= m; ++i)
	{
		int go, to, len;
		cin >> go >> to >> len;
		E.push_back({go, to, len});
	}
	bool isA = 1;
	V<int> c(k + 1);
	V<V<node>> a(k + 1, V<node>(n));
	for(int i = 1; i <= k; ++i)
	{
		cin >> c[i];
		if(c[i]) isA = 0;
		bool tmp = 0;
		for(int j = 1; j <= n; ++j)
		{
			int len; cin >> len;
			if(!len) tmp = 1;
			a[i][j-1] = {n+i, j, len};
		}
		if(!tmp) isA = 0;
		sort(a[i].begin(), a[i].end());
	}
	ll final = 0x7fffFFFFffffFFFFll;
	sort(E.begin(), E.end());
	mp.resize(1<<k);
	if(isA)
	{
		V<node> nE = E;
		for(int j = 1; j <= k; ++j)
			nE = merge(nE, a[j]);
		cout << get(nE, n + k, n + k) << '\n';
		return 0;
	}
	for(int i = 0; i < (1 << k); ++i)
	{
		ll ans = 0;
		int cnt = 0;
		int t = 0;
		for(int j = 1; j <= k; ++j)
			if((i >> (j-1)) & 1)
			{
				if(!t)
					mp[i] = merge(a[j], mp[i ^ (1<<j-1)]),
					t = 1;
				ans += c[j];
				++cnt;
			}
		ans += get(merge(E, mp[i]), n + cnt, n + k);
		final = min(final, ans);
	}
	cout << final << '\n';

	return 0;
}
