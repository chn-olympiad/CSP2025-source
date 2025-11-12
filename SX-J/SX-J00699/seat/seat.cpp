#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 999;

struct noed {
	ll cj, xm;
} a[N];
ll n, m, x = 1, y = 1, cnt = 1;
bool f = 0;

bool cmp(noed c, noed b) {
	return c.cj > b.cj;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++) {
		cin >> a[i].cj;
	}
	a[1].xm = 33;
	sort(a + 1, a + n *m + 1, cmp);
	for (ll i = 1; i <= n * m; i++) {
		if (a[i].xm == 33) {
			cout << y << ' ' << x;
			break;
		}
		if (x == n) {
			cnt = -1;
		}
		if (x == 1) {
			cnt = 1;
		}
		if ((y > 1 && x == 1) || x == n && !f) {
			y++;
			f = 1;
		} else {
			f = 0;
			x += cnt;
		}
	}
	return 0;
}
