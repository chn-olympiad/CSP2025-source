#include <bits/stdc++.h>
using namespace std;
int p[20], s[20][20];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, k, l, f = 0;
	cin >> n >> m;
	k = n * m;
	for (int i = 1; i <= k; i++) {
		cin >> p[i];
	}
	l = p[1];
	sort(p + 1, p + k + 1, cmp);
	k = 0;
	for (int i = 1; i <= m; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= n; j++) {
				k++;
				s[i][j] = p[k];
				if (s[i][j] == l) {
					cout << i << " " << j;
					f = 1;
					break;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				k++;
				s[i][j] = p[k];
				if (s[i][j] == l) {
					cout << j << " " << i;
					f = 1;
					break;
				}
			}
		}
		if (f) {
			break;
		}
	}
	return 0;
}
