#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n[500010];
ll x[1001][1001];
ll f[1001][1001];
ll a, b;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> a >> b;
	for (ll i = 1; i <= a; i++) {
		cin >> n[i];
	}
	for (ll i = 1; i <= a; i++) {
		x[i][i] = n[i];
		for (ll j = i + 1; j <= a; j++) {
			x[i][j] = x[i][j - 1] ^ n[j];
			if (x[i][j - 1] == b) {
				x[i][j] = b;
			}
		}
	}
	for (ll i = 1; i <= a; i++) {
		for (ll j = i; j <= a; j++) {
			if (x[i][j] == b) {
				if (i == 1) {
					f[i][j] = 1;
				}
				for (ll k = i - 1; k >= 1; k--) {
					f[i][j] = max(f[k][i - 1] + 1, f[i][j]);
				}
			}
		}
	}
	for (ll i = 1; i <= a; i++) {
		f[a][a] = max(f[i][a], f[a][a]);
	}
	cout << f[a][a];
	return 0;
}
