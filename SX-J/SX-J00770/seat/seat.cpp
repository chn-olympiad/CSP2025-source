#include <bits/stdc++.h>
using namespace std;
int n, m, x, y = 1, nx, ny, xx;
int kc[15][15];
int cj[225];

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	cin >> n >> m;
	int rs = n * m;
	for (int i = 1; i <= rs; i++) {
		cin >> cj[i];
	}
	xx = cj[1];
	for (int i = 1; i <= rs ; i++) {
		for (int j = 1; j <= rs; j++) {
			if (cj[j] < cj[j + 1]) {
				swap(cj[j], cj[j + 1]);
			}
		}
	}
	for (int i = 1; i <= rs; i++) {
		if (y % 2 == 1) {
			nx = x + 1;
			if (nx > n) {
				y += 1;
				x = nx;
				kc[x][y] = cj[i];
				if (cj[i] == xx) {
					cout << y << " " << x;
				}
			} else {
				kc[nx][y] = cj[i];
				if (cj[i] == xx) {
					cout << y << " " << nx ;
				}
				x = nx;
			}
		} else if (y % 2 == 0) {
			nx = x - 1;
			if (nx < 1) {
				y += 1;
				x = 1;
				kc[x][y] = cj[i];
				if (cj[i] == xx) {
					cout << y << " " << x;
				}
			} else {
				kc[nx][y] = cj[i];
				if (cj[i] == xx) {
					cout << y << " " << nx;
				}
				x = nx;
			}
		}
	}
	cout << endl;
	return 0;
}
