#include <bits/stdc++.h>
#define ll long long
#define P pair<long long,long long>

using namespace std;
const int N = 1e6+10;
const ll inf = 0x3f3f3f3f3f3f;

ll n, m, k;

ll ans;

struct stu {
	ll to, nxt, val;
};
stu e[N << 1];
ll head[N], tot;

struct node {
	ll val, a, b;
} arr[N];
ll cnt;

void add(ll x, ll y, ll c) {
	e[++tot].nxt = head[x];
	e[tot].to = y;
	e[tot].val = c;
	head[x] = tot;
}

ll fa[N];

namespace e1 {
	bool dfs(ll x, ll fa, ll y) {
		for (ll i = head[x]; i; i = e[i].nxt) {
			ll v = e[i].to;
			if (v == fa)
				continue;
			if (v == y)
				return 0;
			return dfs(v, x, y);
		}
		return 1;
	}
	bool cmp(node x, node y) {
		return x.val < y.val;
	}
	void solve() {
		for (ll i = 1; i <= m; i++) {
			ll a, b, c;
			cin >> a >> b >> c;
			arr[i].a = a, arr[i].b = b, arr[i].val = c;
		}
		sort(arr + 1, arr + m + 1, cmp);
		for (ll i = 1; i <= n; i++) {
			if (dfs(arr[i].a, 0, arr[i].b) == 1) {
				add(arr[i].a, arr[i].b, arr[i].val);
				add(arr[i].b, arr[i].a, arr[i].val);
				ans += arr[i].val;
			}
		}
		cout << ans;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (k == 0) {
		e1::solve();
	} else {
		for (ll i = 1; i <= k; i++) {
			ll a;
			cin >> a;
			if (a == 0) {
				cout << 0;
				return 0;
			}
		}
		e1::solve();
	}
	return 0;
}

