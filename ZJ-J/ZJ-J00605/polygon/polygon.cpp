#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n, s[5005], p[5005], ans = 0;
void bn() {
	for (int i = 0; i <= n; i++) {
		if (s[i] == 0) {
			s[i] = 1;
			return;
		} else {
			s[i] = 0;
		}
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	while (1 + 1 == 2) {
		bn();
		if (s[n] == 1) break;
		ll sum = 0, big = -114514;
		for (int i = 0; i < n; i++) {
			if (s[i] == 1) {
				sum += p[i];
				big = max(big, p[i]);
			}
		}
		if (sum > 2 * big) ans++;
		ans %= mod;
	}
	cout << ans;
	return 0;
}
