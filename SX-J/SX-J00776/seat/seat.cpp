#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[110];
	int c = 1, r = 1;
	for (int k = 0; k < m * n; k ++) {
		cin >> a[k];
	}
	sort(a, a + m *n);
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j ++) {
			int ma = a[1];
			if (ma < a[i]) {
				r ++;
			}
			if (ma < a[j]) {
				c ++;
			}
		}
	}
	cout << c << " " << r << endl;
	return 0;
}