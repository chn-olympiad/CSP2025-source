#include <bits/stdc++.h>
using namespace std;
int a0[105], m0[11][11];

bool tmp(int p, int q) {
	return p > q;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i ++) {
		cin >> a0[i];
	}
	int comp = a0[0];
	sort(a0, a0 + (n *m), tmp);
//	for (int i = 0; i < n * m; i ++) {
//		cout << a0[i] << " ";
//	}
//	cout << endl;
	for (int i = 1, p = 0; i <= n; i ++) {
		if (i % 2 != 0) {
			bool tmp1 = 0;
			for (int j = 1; j <= m; j ++, p ++) {
//				cout << a0[p] << " ";
				if (a0[p] == comp) {
					tmp1 = 1;
					cout << i << " " << j;
					break;
				}
			}
			if (tmp1 == true)
				break;
		} else {
			bool tmp1 = 0;
			for (int j = m; j >= 1; j --, p ++) {
//				cout << a0[p] << " ";
				if (a0[p] == comp) {
					tmp1 = 1;
					cout << i << " " << j;
					break;
				}
			}
			if (tmp1 == true)
				break;
		}
	}
	return 0;
}
