#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], sum[5005], s;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 3; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (sum[j] - sum[j - i] > a[j] * 2) {
				s++;
				s = s % 998244353;
			}
		}
	}
	cout << s % 998244353;

	return 0;
}
