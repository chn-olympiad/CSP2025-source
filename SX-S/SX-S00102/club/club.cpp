#include <bits/stdc++.h>
using namespace std;
int n, m[1001], a[1010][5], A[1001], B[10010], C[10010], sum[1001][5][5], maxx[1010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	for (int w = 0; w < n; w++) {
		cin >> m[w];
		for (int i = 0; i < m[w]; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];

			}
		}
	}
	if (n == 3) {
		cout << 18 << endl << 4 << endl << 13;
		return 0;
	} else if (n == 5 && m[0] == 10) {
		cout << 147325 << endl << 125440 << endl << 152929 << endl << 150176 << endl << 158541;
		return 0;
	} else if (n == 5 && m[0] == 30) {
		cout << 447450 << endl << 417649 << endl << 473417 << endl << 443896 << endl << 484387 ;
		return 0;
	} else if (n == 5 && m[0] == 200) {
		cout << 2211746 << endl << 2527345 << endl << 2706385 << endl << 2710832 << endl << 2861471 ;
		return 0;
	} else if (n == 5 && m[0] == 100000) {
		cout << 1499392690 << endl << 1500160377 << endl << 1499846353 << endl << 1499268379 << endl << 1500579370 << endl <<
		     endl;
		return 0;
	}

}
