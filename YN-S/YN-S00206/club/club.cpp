#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;


int T, a[N][3], n, z[N][3], b[3][N] = {}, bb[3] = {}, zz = 0;

void px(int x) {
	z[x][0] = 0;
	z[x][1] = 1;
	z[x][2] = 2;
	if (a[x][0] >= a[x][1] && a[x][1] >= a[x][2]) {
		return ;
	}
	while (1) {
		if (a[x][0] >= a[x][1] && a[x][1] >= a[x][2]) {
			return ;
		} else {
			if (a[x][0] < a[x][1]) {
				swap(a[x][0], a[x][1]);
				swap(z[x][0], z[x][1]);
			}
			if (a[x][1] < a[x][2]) {
				swap(a[x][1], a[x][2]);
				swap(z[x][1], z[x][2]);
			}
		}
	}
}

int main() {
	freopen("club.out", "r", stdin);
	freopen("employ.in", "w", stdout);
	cin >> T;
	while (T--) {
		zz = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			b[0][i] = 0, bb[i] = 0, b[1][i] = 0, b[2][i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			px(i);
		}
		for (int i = 1; i <= n; i++) {
			bb[z[i][0]]++;
			b[z[i][0]][bb[z[i][0]]] = a[i][0];
		}
		sort(b[0], b[0] + bb[0]);
		sort(b[1], b[1] + bb[1]);
		sort(b[2], b[2] + bb[2]);
		for (int i = 0; i < 3; i++) {
			for (int j = bb[i]; !(j < 1 || j < bb[i] - n / 2 + 1) ; j--) {
				zz += b[i][j];
			}
		}
		cout << zz << endl;
	}
	return 0;
}