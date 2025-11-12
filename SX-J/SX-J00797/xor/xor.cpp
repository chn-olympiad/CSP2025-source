#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5+5;
long long n, k, ans;
long long a[N], f[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		f[i] = f[i - 1] + a[i];
	if (k == 0) {
		int l = 1;
		for (int i = 1; i <= n; i++) {
			if ((f[i] - f[l - 1]) % 2 == 0) {
				ans++;
				l = i + 1;
			}
		}
		cout << ans;
	} else if (k == 1) {
		int l = 1;
		for (int i = 1; i <= n; i++) {
			if ((f[i] - f[l - 1]) % 2 == 1) {
				ans++;
				l = i + 1;
			}
		}
		cout << ans;
	}
	return 0;
}
