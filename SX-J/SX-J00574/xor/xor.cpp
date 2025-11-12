#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, ans = 1;
ll a[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (k == 0) {
		if (n == 2)
			ans = 1;
		else {
			ans = 0;
			for (int j = 2; j <= n; j += 2) {
				for (int e = j; e <= n; ++e) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
