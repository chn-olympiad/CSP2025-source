#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int a[500005], dp[500005];
bool b[500005];

bool pd(int i, int j) {
	for (int i; i <= j; i++) {
		if (b[i] == 1) {
			return 0;
		}
	}
	return 1;
}

void g(int i, int j) {
	for (int i; i <= j; i++) {
		b[i] == 1;
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = a[i] ^ dp[i - 1];
		if (a[i] == k && b[i] == 0) {
			ans++;
			b[i] = 1;
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		if (b[i] != 1) {
			for (int j = i + 1; j <= n; j++) {
				int k1 = dp[j] ^ dp[i - 1];
				if (pd(i, j) && k == k1) {
					ans++;
					g(i, j);
				}
			}
		}
	}
	cout << ans;
	return 0;
}//   =>     :)