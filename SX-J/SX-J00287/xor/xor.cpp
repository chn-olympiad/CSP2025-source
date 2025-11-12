#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, f[500005], a[500005], s[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k ;
	for (int i = 1; i <= n ; i++) {
		cin >> a[i];

	}
	for (int i = 1; i <= n ; i++) {
		ll x = a[i], y = i;
		s[i] = 0;
		while (x != k) {
			y++;
			if (y > n) {
				break;
			}
			x = (x | a[y]) - (x &a[y]);
		}
		if (x == k) {
			s[i] = y;
		}

	}
	for (int i = n; i >= 1; i--) {
		if (s[i] == 0) {
			f[i] = f[i + 1];
		} else {
			f[i] = max(f[i + 1], f[s[i] + 1] + 1);
		}
	}
	cout << f[1];

}
