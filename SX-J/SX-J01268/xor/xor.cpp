#include <bits/stdc++.h>
using namespace std;
int n, k, a[100010], b[100010], sum, ans;

void xxor(int i, int j) {
	for (i; i <= n; i++) {
		for (j; j <= n; j++) {
			if (b[j] - b[i - 1] == k) {
				sum++;
				sum %= 998244353;
				xxor(j + 1, j + 1);
			}
			ans = max(ans, sum);
			sum = 0;
		}
	}
	return;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
	}
	xxor(1, 1);
	cout << ans;
	return 0;
}
