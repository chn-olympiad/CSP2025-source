#include <bits/stdc++.h>
using namespace std;
const int MAXX = 5E5;
int a[MAXX + 10], b[MAXX + 10], vis[MAXX + 10];

bool find(int i, int j) {
	if (vis[i] || vis[j]) {
		return 0;
	}
	return 1;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0;
	bool flag1 = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
		if (a[i] != 1) {
			flag1 = 0;
		}
	}
	if (flag1 && k == 0 ) {
		cout << n / 2;
		return 0;
	} else if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				ans++;
			}
		}
		cout << ans;
		return 0;
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (b[j]^b[i - 1] == k && find(i, j)) {
					ans++;
					vis[i] = i;
					vis[j] = j;
				}
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}
