#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[110], xiaor, pa, jishu = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	pa = n;
	for (ll i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1)
			xiaor = a[i];
	}
	jishu = n * m + 1;
	sort(a + 1, a + (n *m) + 1);
	for (ll i = 1; i <= m; i++) {
		if (pa == n) {
			for (ll j = 1; j <= n; j++) {
				jishu--;
				if (a[jishu] == xiaor) {
					cout << i << " " << j;
					return 0;
				}
			}
			pa = 1;
		} else {
			for (ll j = n; j >= 1; j--) {
				jishu--;
				if (a[jishu] == xiaor) {
					cout << i << " " << j;
					return 0;
				}
			}
			pa = n;
		}
	}
	return 0;
}
