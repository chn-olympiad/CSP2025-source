#include"bits/stdc++.h"
#define ll long long
using namespace std;

const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int T, n, cnt[4];
struct st
{
	int a, id;
	friend bool operator < (const st &x, const st &y)
		{return x.a > y.a;}
};
struct Data
{
	st p[4];
}d[N];
struct tree
{
	int vis, ans;
	ll val;
	tree(int _v = 0, ll _va = -inf, int _a = 0): vis(_v), val(_va), ans(_a){}
};
struct Sgt
{
	tree seg[N << 2];
	void build(int x, int l, int r)
	{
		seg[x] = tree();
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
	}
	tree merge(tree l, tree r)
	{
		if (l.val > r.val) return l;
		return r;
	}
	void insert(int x, int l, int r, int v, ll k, int q)
	{
		if (l == r) return seg[x] = (q == -1 ? tree() : tree(v, k, q)), void();
		int mid = (l + r) >> 1;
		if (v <= mid) insert(x << 1, l, mid, v, k, q);
		else insert(x << 1 | 1, mid + 1, r, v, k, q);
		seg[x] = merge(seg[x << 1], seg[x << 1 | 1]);
	}
	tree query()
	{
		return seg[1];
	}
	tree ask(int x, int l, int r, int v)
	{
		if (l == r) return seg[x];
		int mid = (l + r) >> 1;
		if (v <= mid) return ask(x << 1, l, mid, v);
		else return ask(x << 1 | 1, mid + 1, r, v);
	}
	ll sum(int x, int l, int r)
	{
		if (l == r) return seg[x].val <= 0 ? 0 : seg[x].val;
		int mid = (l + r) >> 1;
		return sum(x << 1, l, mid) + sum(x << 1 | 1, mid + 1, r);
	}
}s[4], t[4];

void solve()
{
	cin >> n;
	for (int i = 1; i <= 3; i++)
	{
		s[i].build(1, 1, n);
		t[i].build(1, 1, n);
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> d[i].p[j].a;
			d[i].p[j].id = j;
		}
		sort(d[i].p + 1, d[i].p + 3 + 1);
	}
	for (int i = 1; i <= n; i++)
	{
		int x = d[i].p[1].id, y = d[i].p[2].id;
		ll a = d[i].p[1].a, b = d[i].p[2].a;
		if (cnt[x] + 1 <= n / 2)
		{
			cnt[x]++;
			s[x].insert(1, 1, n, i, a, x);
			t[x].insert(1, 1, n, i, b - a, y);
		}
		else
		{
			tree ex = t[x].query();
			if (ex.val > b - a)
			{
				tree es = s[x].ask(1, 1, n, ex.vis);
				if (ex.vis != es.vis) cout << es.vis;
				s[x].insert(1, 1, n, ex.vis, -inf, -1);
				t[x].insert(1, 1, n, ex.vis, -inf, -1);
				cnt[ex.ans]++;
				s[ex.ans].insert(1, 1, n, ex.vis, es.val + ex.val, ex.ans);
				t[ex.ans].insert(1, 1, n, ex.vis, -ex.val, es.ans);
				s[x].insert(1, 1, n, i, a, x);
				t[x].insert(1, 1, n, i, b - a, y);
			}
			else
			{
				cnt[y]++;
				s[y].insert(1, 1, n, i, b, y);
				t[y].insert(1, 1, n, i, a - b, x);
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= 3; i++)
		ans += s[i].sum(1, 1, n);
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) solve();
	return 0;
}
