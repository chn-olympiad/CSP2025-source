#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000];

bool cmp(int f, int b) {
	return f > b;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int x = 0;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	int wz = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			wz = i;
		}
//		cout << a[i] << endl;
	}
//	cout << wz << endl;
	int csp_j = wz / m + (wz % m == 0 ? 0 : 1);
	cout << csp_j << " ";
	if (csp_j % 2) {
		cout << (wz % m == 0 ? m : wz % m);
	} else {
		cout << m - (wz % m == 0 ? m : wz % m) + 1;
	}
	return 0;
}
