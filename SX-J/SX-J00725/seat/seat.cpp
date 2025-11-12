#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e3;
ll n, m, a[N], store, id, mx = 1, my = 1;
bool flas;

bool cmp(ll c, ll b) {
	return c > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++)
		cin >> a[i];
	store = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	ll l = 1;
	while (1) {
		if (a[l] == store) {
			id = l;
			break;
		}
		l++;
	}
	for (int i = 1; i < id; i++) {
		if ((my == m && mx % 2 == 1) || (my == 1 && mx % 2 == 0))
			mx++;
		else if (mx % 2 == 1)
			my++;
		else if (mx % 2 == 0)
			my--;
		cout << mx << ' ' << my << '\n';
	}
	cout << mx << ' ' << my;
	return 0;
}