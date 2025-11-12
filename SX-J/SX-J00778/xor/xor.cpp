#include <bits/stdc++.h>
using namespace std;
int a[510000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	if (k == 0) {
		int ans = 0, ant = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				ans++;
			}
		}
		for (int i = 2; i <= n; i++) {
			if (a[i] == a[i - 1] && a[i - 1] == 1) {
				ant++;
				a[i] = 0;
				a[i - 1] = 0;
			}
		}
		cout << ans + ant;
		return 0;
	} else if (k == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
