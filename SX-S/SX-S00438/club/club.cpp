#include <bits/stdc++.h>
using namespace std;
int t;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int g = 1; g <= t; g++) {
		int a[10005];
		int b[10005];
		int c[10005];
		int n, z = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a + 1, a + n + 1);
		for (int i = n; i > n / 2; i--) {
			z += a[i];
		}
		cout << z;
	}
	return 0;
}
