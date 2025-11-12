#include <bits/stdc++.h>
using namespace std;
long long n, k, ans, p;
long long h[500010], m[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> h[i];
		if (h[i] == k)
			m[i] = 0;
		else {
			m[i] = m[i - 1] ^ h[i];
		}
	}
	for (long long i = 1; i <= n; i++) {
		if ((k ^ h[i]) == 0 || (k ^ h[i]) == m[i - 1]) {
			ans++;
			i++;
		}
	}
	cout << ans;
	return 0;
}