#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], f[500005], ans[500005], q, ansz;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (f[i] > 0)
			continue;
		if (a[i] == k) {
			f[i] = i;
			continue;
		}
		int x = a[i], y = k ^a[i];
		for (int j = i + 1; j <= n; j++) {
			x ^= a[j];
			if (f[i + 1] == 0 && x == y)
				f[i + 1] = j;
			if (x == k) {
				f[i] = j;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] > 0) {
			ans[f[i]] = max(ans[f[i]], q + 1);
			ansz = max(ansz, ans[f[i]]);
		}
		q = max(q, ans[i]);
	}
	cout << ansz;
	return 0;
}