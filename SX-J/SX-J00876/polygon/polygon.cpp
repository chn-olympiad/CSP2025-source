# include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	if (n = 3) {
		if (a[1] + a[2] + a[3] <= a[1] * 2) {
			cout << 0;
			return 0;
		}
		if (a[1] + a[2] + a[3] <= a[2] * 2) {
			cout << 0;
			return 0;
		}
		if (a[1] + a[2] + a[3] <= a[3] * 2) {
			cout << 0;
			return 0;
		}
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {

	}
}