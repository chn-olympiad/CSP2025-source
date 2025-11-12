#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, t, b, s;
	cin >> n >> m;
	int a[n * m] = {0};
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	b = a[0];
	for (int j = 1; j <= n * m - 1; j++) {
		for (int k = 0; k < n * m - 1; k++) {
			if (a[k + 1] > a[k]) {
				t = a[k + 1];
				a[k + 1] = a[k];
				a[k] = t;
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (a[i] == b)
			s = i + 1;
	}
	if (s <= n)
		cout << 1 << " " << s;
	else if ((s / n) % 2 != 0)
		cout << s / n + 1 << " " << n - (s % n) + 1;
	else if ((s / n) % 2 == 0)
		cout << s / n + 1 << " " << s % n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
