#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k, c[11], a[11][10001], sum, bcj[10001], u, v, w, ans, dp[10001][1024];

struct node {
	ll q, x, y;
	bool flag = 0;
} bian[1000001], b[10001];

bool cmp(node f, node z) {
	if (f.q < z.q)
		return true;
	else
		return false;
}

ll cx(ll f) {
	if (bcj[f] == 0)
		return f;
	ll cur = cx(bcj[f]);
	bcj[f] = cur;
	return cur;
}

void hb(ll f, ll z) {
	if (bcj[f] == 0) {
		bcj[f] = z;
		return;
	}
	hb(bcj[f], z);
	return;
}

void solve(ll i, ll st) {

}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &u, &v, &w);
		bian[i].q = w;
		bian[i].x = u;
		bian[i].y = v;
	}
	sort(bian + 1, bian + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (cx(bian[i].x) != cx(bian[i].y)) {
			ans += bian[i].q;
			sum++;
			b[sum].q = bian[i].q;
			b[sum].x = bian[i].x;
			b[sum].y = bian[i].y;
			hb(bian[i].x, cx(bian[i].y));
		}
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);

		}
	}
	if (k == 0) {
		cout << ans;
		return 0;
	}

	return 0;
}