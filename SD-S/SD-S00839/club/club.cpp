//See You, My OIer Life 

#include <bits/stdc++.h>

typedef long long ll;
const ll MAXN = 2e5 + 5;

ll read() {
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + c - '0'; c = getchar();}
	return x * f;
}

ll n, a[MAXN][5];
ll t[5];
std::priority_queue<std::pair<ll, ll> > heap;

ll max_else(int i, int j) {
	ll res = 0;
	for (int k = 1; k <= 3; k++) {
		if(j == k) continue;
		res = std::max(res, a[i][k]);
	}
	return res;
}

ll num_else (int i, int j, ll melse) {
	for (int k = 1; k <= 3; k++) {
		if(j == k) continue;
		if(melse == a[i][k]) return k;
	}
}

void solve() {
	n = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			a[i][j] = read();
	ll ans = 0;
	for (int k = 1; k <= 3; k++) {
		while(heap.size())
			heap.pop();
		ll res = 0;
		t[1] = t[2] = t[3] = 0;
		for (int i = 1; i <= n / 2; i++) {
			heap.push({max_else(i, k) - a[i][k], num_else(i, k, max_else(i, k))});
			res += a[i][k];
			t[k]++;
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			res += max_else(i, k);
			ll delta = a[i][k] - max_else(i, k);
			if(delta + heap.top().first > 0) {
				res += delta + heap.top().first;
				t[heap.top().second]++;
				heap.pop();
				heap.push({-delta, num_else(i, k, max_else(i, k))});
			}
			else {
				t[num_else(i, k, max_else(i, k))]++;
			}
		}
		while(heap.size()) {
			ll p = heap.top().first, q = heap.top().second;
			if(p <= 0) break;
			heap.pop();
			if(t[q] < n / 2) {
				t[q]++;
				res += p;
			}
		}
		ans = std::max(ans, res);
	}
	std::cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll T = read();
	while(T--)
		solve();
	return 0;
}

