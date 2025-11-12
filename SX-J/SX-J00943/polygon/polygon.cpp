#include <bits/stdc++.h>
using namespace std;
long long n, maxn = -9999;
long long a[5005], cnt = 0, sum = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	maxn *= 2;
	for (int i = 1; i <= n; i++) {
		cnt = a[i];
		for (int j = n; j >= i; j--) {
			if (cnt + a[j] > maxn / 2) {
				cnt += a[j];
			}
			if (cnt > maxn) {
				sum++;
			}
		}
		cnt = 0;
	}
	cout << sum % 998244353;
	return 0;
}
