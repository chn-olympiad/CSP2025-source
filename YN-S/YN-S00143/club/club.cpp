#include <bits/stdc++.h>
using namespace std;
int n;
int t;
int i[100001][3];
int j[4];

int main() {
	freopen(club.in, "r", stdin);
	freopen(club.out, "w", stdout);
	cin >> t;
	for (int q = 1; q <= t; q++) {
		int m = 0;
		cin >> n;
		for (int a = 0; a < n; a++) {
			for (int z = 0; z < 3; z++) {
				cin >> i[a][z];
			}
		}
		for (int a = 0; a < n; a++) {
			for (int z = 0; z < 3; z++) {
				if (j[1] > n / 2 && j[2] > n / 2) {
					j[3] = j[3] + 1;
					m = m + i[a][3];
				} else if (j[2] > n / 2 && j[3] > n / 2) {
					j[1] = j[1] + 1;
					m = m + i[a][1];
				} else if (j[1] > n / 2 && j[3] > n / 2) {
					j[2] = j[2] + 1;
					m = m + i[a][2];
				}
				if (i[a][2] == 0 && i[a][3] == 0 && j[1] <= n / 2) {
					if (j[1] <= n / 2) {
						j[1] = j[1] + 1;
						m = m + i[a][1];
					}
					break;
				} else if (i[a][1] == 0 && i[a][3] == 0) {
					if (j[2] <= n / 2) {
						j[2] = j[2] + 1;
						m = m + i[a][2];
					}
					break;
				} else if (i[a][1] == 0 && i[a][2] == 0) {
					if (j[3] <= n / 2) {
						j[3] = j[3] + 1;
						m = m + i[a][3];
					}
					break;
				} else if (i[a][1] > i[a][2] && i[a][1] > i[a][3]) {
					if (j[1] <= n / 2) {
						j[1] = j[1] + 1;
						m = m + i[a][1];
					}
					break;
				} else if (i[a][2] > i[a][1] && i[a][2] > i[a][3]) {
					if (j[2] <= n / 2) {
						j[2] = j[2] + 1;
						m = m + i[a][2];
					}
					break;
				} else if (i[a][3] > i[a][2] && i[a][3] > i[a][1]) {
					if (j[3] <= n / 2) {
						j[3] = j[3] + 1;
						m = m + i[a][3];
					}
					break;
				}
			}
		}
		cout << m;
	}
}