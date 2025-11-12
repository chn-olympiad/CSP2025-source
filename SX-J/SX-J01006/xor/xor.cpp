#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], sum[500005], num, b, e;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			b = sum[i - 1] ^ sum[j];
			if (b == k and i > e) {
				num++;
				e = j;
			}
		}
	}
	cout << num;

	return 0;
}
