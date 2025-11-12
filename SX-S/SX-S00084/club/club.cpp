#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, a[200005][3], sum[3];

struct node {
	ll maxx, next;
} f[200005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq[3];

node ansa(ll x) {
	node y;
	ll maxn = max(a[x][0], max(a[x][1], a[x][2]));
	if (a[x][0] == maxn) {
		y.maxx = 0;
		maxn = max(a[x][1], a[x][2]);
		if (a[x][1] == maxn)
			y.next = 1;
		else
			y.next = 2;
	} else if (a[x][1] == maxn) {
		y.maxx = 1;
		maxn = max(a[x][2], a[x][0]);
		if (a[x][0] == maxn)
			y.next = 0;
		else
			y.next = 2;
	} else {
		y.maxx = 2;
		maxn = max(a[x][1], a[x][0]);
		if (a[x][1] == maxn)
			y.next = 1;
		else
			y.next = 0;
	}
	return y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		memset(sum, 0, sizeof(sum));
		for (ll i = 0; i < 3; i++) {
			while (pq[i].size())
				pq[i].pop();
		}
		cin >> n;
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			f[i] = ansa(i);
		}
		for (ll i = 1; i <= n; i++) {
			sum[f[i].maxx]++;
			ans += a[i][f[i].maxx];
			pq[f[i].maxx].push(make_pair(a[i][f[i].maxx] - a[i][f[i].next], f[i].next));
			if (sum[f[i].maxx] > n / 2) {
				ll u = pq[f[i].maxx].top().first, v = pq[f[i].maxx].top().second;
				pq[f[i].maxx].pop();
				sum[v]++;
				ans -= u;
			}
		}
		cout << ans << endl;
	}
	/*
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2
	10 9 8
	4 0 0
	*/
}
