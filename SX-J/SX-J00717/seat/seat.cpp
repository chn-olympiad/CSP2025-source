#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long m, n;
	cin >> n >> m;
	int a[m * n];
	int r;
	cin >> a[0];
	r = a[0];
	for (int i = 1; i < m * n; i++) {
		cin >> a[i];
	}
	sort(a, a + m *n);
	if (r == a[0]) {
		cout << 1 << " " << 1;
		return 0;
	}
	for (int i = 1; i < m * n; i++) {
		if (r == a[i]) {
			if (((i / n) % 2 == 0 && n % 2 == 1 ) || ((i / n) % 2 == 1 && n % 2 == 0)) {
				cout << i % n + 1 << " " << i / n + 1;
			} else {
				cout << n - i / n   << " " << i / n + 2;
			}
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
