#include <bits/stdc++.h>
using   namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int a[100];
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	sqrt(a, a + 1);

	for (int i = 1; i <= n * m; i++) {
		cout << a[i];
	}
	return 0;
}
