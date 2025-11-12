#include <bits/stdc++.h>
using namespace std;
int t, a, c,  m, s = 0, ma, z = 0;
int b[10005][5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> a;
		for (int j = 1; j <= a; j++) {
			for (int k = 1; k <= 3; k++) {
				cin >> b[j][k] ;
				if (b[j][2] == 0 && b[j][3] == 0) {
					c = b[j][1];
					if (b[j + 1][3] == 0 && b[j + 1][2] == 0) {
						m = max(c, b[j + 1][1]);
						cout << m;

					} else {
						int d = max(b[j + 1][1], b[j + 1][3]);
						cout << d + c;

					}
				} else
					ma = max(b[j][1], b[j][2]);
				z = max(ma, b[j][3]);
				s += z;
				cout << s ;
			}
		}
	}
	return 0;
}


