#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int z;
	cin >> z;
	for (int m = 1; m <= z; m++) {
		int a;
		cin >> a;
		int y1[a + 2], y2[a + 2], y3[a + 2];
		for (int p = 0; p < a; p++) {
			cin >> y1[p] >> y2[p] >> y3[p];
		}
		sort(y2, y2 + a );
		int lj = 0;
		for (int m = a - 1 ; m >= a - a / 2; m--) {
			lj += y2[m];
		}
		cout << lj << endl;
	}
	return 0;
}
