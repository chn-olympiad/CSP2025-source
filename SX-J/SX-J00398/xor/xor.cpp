#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 0, p;
long long h[500010], m[500010];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> h[i];
		if (h[i] == k)
			m[i] = 0;
		else
			m[i] = m[i - 1] ^ h[i];

	}
	for (long long i = 1; i <= n; i++) {
		if (k ^ h[i] == 0 || k ^ h[i] == m[i - 1]) {
			ans++;
			i++;
		}
	}
	cout << ans;
	return 0;
}
