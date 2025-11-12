#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, hhh = 0;
	cin >> n >> m;
	int a[n * m + 2];
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int O = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == O) {
			hhh = i;
			break;
		}
	}
	int kkk = n * m - hhh + 1;
	cout << kkk / m << " ";
	cout << m - kkk % m;
	return 0;
}