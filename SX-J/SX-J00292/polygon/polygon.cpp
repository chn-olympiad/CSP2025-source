#include <bits/stdc++.h>
using namespace std;
int n, a[5005], cnt, x, y;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n - 2; i++) {
		x = a[i] + a[i + 1] + a[i + 2];
		if ( x > max(a[i], max(a[i + 1], a[i + 2])) * 2) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}