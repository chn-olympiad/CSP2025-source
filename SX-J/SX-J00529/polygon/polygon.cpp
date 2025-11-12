#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ans;
ll a[5010], b[5010];
bool f;

void dfs(ll xx, ll l, ll maxx, ll c, ll gezi) {
	for (ll i = xx; i <= n; i++) {
		b[gezi] = i;
		if (gezi == l) {
			if ((c + a[i]) > max(maxx, a[i]) * 2)
				ans++;
		} else {
			dfs(i + 1, l, max(maxx, a[i]), c + a[i], gezi + 1);
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 1)
			f = true;
	}
	if (f == false) {
		k = n - 2;
		cout << ((k + 1)*k / 2 + 998244353) % 998244353;
	}
	for (ll l = 3; l <= n; l++) {
		dfs(1, l, -1, 0, 1);
	}
	cout << (ans + 998244353) % 998244353;
	return 0;
}
