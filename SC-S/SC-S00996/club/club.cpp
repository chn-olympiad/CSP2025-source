#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read() {
	ll sum = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		ch = getchar();
	}
	while (isdigit(ch)) {
		sum = (sum << 1) + (sum << 3) + (ch ^ 48);
		ch = getchar();
	}
	return sum;
}
ll t;
ll n;
ll a[100005][5];
ll cnt[5];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq[5];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while (t--) {
		pq[1] = {};
		pq[2] = {};
		pq[3] = {};
		ll res = 0;
		n = read();
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= 3; j++) {
				a[i][j] = read();
			}
		}
		for (ll i = 1; i <= n; i++) {
			ll mx1 = 0, mx2 = 0, p = 0;
			for (ll j = 1; j <= 3; j++) {
				if (mx1 < a[i][j]) {
					mx1 = a[i][j];
					p = j;
				}
			}
			if (p == 1) mx2 = max(a[i][2], a[i][3]);
			else if (p == 2) mx2 = max(a[i][1], a[i][3]);
			else if (p == 3) mx2 = max(a[i][1], a[i][2]);
			pq[p].push(make_pair(a[i][p] - mx2, i));
			res += a[i][p];
			if ((ll)pq[p].size() > n / 2) {
				pair<ll, ll> u = pq[p].top();
				pq[p].pop();
				res -= u.first;
			}
		}
		cout << res << '\n';
	}
	return 0;
}