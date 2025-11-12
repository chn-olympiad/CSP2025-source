#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], l, cj;

bool cmp(int p, int q) {
	return p > q;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			l++;
			cin >> a[l];
			if (l == 1)
				cj = a[l];
		}
	}
	sort(a + 1, a + m *n + 1, cmp);
	for (int i = 1; i <= l; i++) {
		if (a[i] == cj) {
			l = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				l--;
				if (l == 0) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for (int j = m; j >= 1; j--) {
				l--;
				if (l == 0) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
