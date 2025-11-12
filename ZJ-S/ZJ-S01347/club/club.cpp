#include <bits/stdc++.h>
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define D(i, a, b) for (int i = (a); i >= (b); --i)
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) ((int)s.size())
using namespace std;
const int N = 2e5 + 5;
int n, a[N][4], p[N], cnt[4];
struct V {
	int d, id;
	friend bool operator < (V u, V v) {
		return u.d > v.d;
	}
}; priority_queue<V> q[4];
bool vis[N];
V Get(int x, int y) {
	while (!q[x].empty() && vis[q[x].top().id]) q[x].pop();
	while (!q[y].empty() && vis[q[y].top().id]) q[y].pop();
	if (q[x].empty() || cnt[x]+1 > n/2) {
		V u = q[y].top(); q[y].pop();
		vis[u.id] = 1, ++cnt[y];
		return u;
	} else if (q[y].empty() || cnt[y]+1 > n/2) {
		V u = q[x].top(); q[x].pop();
		vis[u.id] = 1, ++cnt[x];
		return u;
	} else {
		V u = q[x].top(), v = q[y].top();
		if (u.d < v.d) {
			vis[u.id] = 1, ++cnt[x];
			q[x].pop();
			return u;
		} else {
			vis[v.id] = 1, ++cnt[y];
			q[y].pop();
			return v;
		}
	}
}
void GOGO() {
	cin >> n;
	int ans = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	while (!q[1].empty()) q[1].pop();
	while (!q[2].empty()) q[2].pop();
	while (!q[3].empty()) q[3].pop();
	F(i, 1, n) {
		vis[i] = 0;
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int cur = max(max(a[i][1], a[i][2]), a[i][3]);
		if (a[i][1] == cur) p[i] = 1, ++cnt[1];
		else if (a[i][2] == cur) p[i] = 2, ++cnt[2];
		else if (a[i][3] == cur) p[i] = 3, ++cnt[3];
		ans += cur;
	}
	if (cnt[1] > n/2) {
		F(i, 1, n) if (p[i] == 1) {
			q[2].push({a[i][1]-a[i][2], i}), q[3].push({a[i][1]-a[i][3], i});
		}
		while (cnt[1] > n/2) {
			V u = Get(2, 3);
			ans -= u.d, --cnt[1];
		}
	} else if (cnt[2] > n/2) {
		F(i, 1, n) if (p[i] == 2) {
			q[1].push({a[i][2]-a[i][1], i}), q[3].push({a[i][2]-a[i][3], i});
		}
		while (cnt[2] > n/2) {
			V u = Get(1, 3);
			ans -= u.d, --cnt[2];
		}
	} else if (cnt[3] > n/2) {
		F(i, 1, n) if (p[i] == 3) {
			q[1].push({a[i][3]-a[i][1], i}), q[2].push({a[i][3]-a[i][2], i});
		}
		while (cnt[3] > n/2) {
			V u = Get(1, 2);
			ans -= u.d, --cnt[3];
		}
	}
	cout << ans << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	FIO
	int T; cin >> T; F(_, 1, T) GOGO();
	return 0;
} 
