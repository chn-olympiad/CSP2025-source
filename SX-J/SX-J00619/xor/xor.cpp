#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], sum[500005], cnt, yh[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		yh[i] = yh[i - 1] ^ a[i];
		sum[i] = sum[i - 1] + yh[i];
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			if (sum[r] - sum[l - 1] == k) {
				cnt++;
				l = r + 1;
				break;
			} else if (sum[r] - sum[l - 1] > k)
				break;
		}
	}
	cout << cnt;
	return 0;
}