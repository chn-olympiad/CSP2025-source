#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n, cnt;
int z, ma;
int a[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
//	ios::sync_with_stdin(false);
//	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 3; i--) {
		for (int j = 1; j <= i; j++) {
			z += a[j];
			ma = max(ma, a[j]);
		}
		if (z > ma * 2) {
			cnt++;
		}
		z = 0;
		ma = 0;
		for (int j = n; j >= i; j++) {
			z += a[j];
			ma = max(ma, a[j]);
		}
		if (z > ma * 2) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}