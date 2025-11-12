#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> a[(i - 1) * m + j];
	}
	int r = a[1], ans;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			ans = i;
			break;
		}
	}
	cout << (ans + n - 1) / n << " ";
	if (((ans + n - 1) / n) % 2 == 1) cout << (ans - 1) % n + 1;
	else cout << n - (ans - 1) % n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
