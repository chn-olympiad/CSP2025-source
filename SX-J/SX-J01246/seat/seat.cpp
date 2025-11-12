#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m], ans = 0, h = 1, l = 1;
	cin >> a[0];
	for (int i = 1; i < n * m; i++) {
		cin >> a[i];
		if (a[i] > a[0])
			ans++;
	}
	for (; ans >= m; ans -= m) {
		h++;
	}
	if (h % 2 == 0) {
		l += m - ans - 1;
	} else {
		l += ans;
	}
	cout << h << " " << l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
