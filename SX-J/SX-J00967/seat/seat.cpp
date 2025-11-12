#include <bits/stdc++.h>
using namespace std;
int n, m, s[1005], c, v;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >>  n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
	}
	v = s[1];
	sort(s + 1, s + 1 + (n *m));
	c = n * m ;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				if (s[c] == v) {
					cout << i << " " << j;
					return 0;
				}
				c--;
			}
		}
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				if (s[c] == v) {
					cout << i << " " << j;
					return 0;
				}
				c--;
			}
		}
	}
	return 0;
}
//3 3 94 95 96 97 98 99 100 93 92
