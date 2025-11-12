#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 * 5;
int a[N], n, k, m, ans, c, b[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (j == i)
				m = a[j];
			else
				m = m ^ a[j];
			if (m == k) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
