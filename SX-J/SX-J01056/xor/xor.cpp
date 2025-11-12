#include <bits/stdc++.h>
using namespace std;
int k, n, a[500005], ans, cnt;
bool f[500005];

bool check(int x, int y) {
	for (int i = x; i <= y; i++) {
		if (f[i] == 1) {
			return 0;
		}
	}
	return 1;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			if (a[i] == 1)
				cnt++;
		}
		cout << cnt;
		return 0;
	} else if (k == 0) {
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				cnt++;
			}
		}
		cout << cnt;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			ans = 0;
			for (int t = i; t <= j; t++) {
				ans = ans | a[t];
			}
			if (ans == k && check(j, i)) {
				f[j] = f[i] = 1;
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
