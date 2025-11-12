#include <bits/stdc++.h>
using namespace std;

int t, p, r, m;
int ant, sum;
int a[10000][4][6], x[4];

int main() {
	freopen("club1.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int n = 0; n <= t; n++) {
		cin >> p;
		for (int i = 1; i <= p; i++) {
			m = 0;
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j][n];
				if ((a[i][j][n] > m) && (x[j] > p / 2)) {
					m = a[i][j][n];
					ant = j;
				}
			}
//			m=max(a[i][1][n],max(a[i][2][n],a[i][3][n]))
			x[ant] += 1;
			sum += m;
		}
	}
//	for (int n = 0; n <= t; n++) {
//		for (int i = 1; i <= p; i++) {
//			for (int j = 1; j <= 3; j++) {
//			}
//		}
//	}
	for (int i = 1; i <= t; i++) {
		cout << sum << endl;
	}
}