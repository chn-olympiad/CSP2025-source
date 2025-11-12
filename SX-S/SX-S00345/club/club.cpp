#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll t, n, ans;

struct node {
	ll x, y, z;
} a[N];

bool cmp(node x, node y) {
	if (x.x == y.x) {
		if (x.y == y.y) {
			return x.z > y.z;
		}
		return x.y > y.y;
	}
	return x.x > y.x;
}

void dfs(ll id, ll x, ll y, ll z, ll cnt) {
	if (id == n) {
		ans = max(ans, cnt);
		return;
	}
	if (x + 1 > n / 2) {
		dfs(id + 1, x, y + 1, z, cnt + a[id].y);
		dfs(id + 1, x, y, z + 1, cnt + a[id].z);
	} else if (y + 1 > n / 2) {
		dfs(id + 1, x + 1, y, z, cnt + a[id].x);
		dfs(id + 1, x, y, z + 1, cnt + a[id].z);
	} else if (z + 1 > n / 2) {
		dfs(id + 1, x + 1, y, z, cnt + a[id].x);
		dfs(id + 1, x, y + 1, z, cnt + a[id].y);
	} else {
		dfs(id + 1, x + 1, y, z, cnt + a[id].x);
		dfs(id + 1, x, y + 1, z, cnt + a[id].y);
		dfs(id + 1, x, y, z + 1, cnt + a[id].z);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort(a + 1, a + n + 1, cmp);
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}
