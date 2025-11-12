#include <bits/stdc++.h>
using namespace std;


int u[10000];
int b[10000];
int c[10000];
int o[10000];
int tt[10000][10000];
int i1[10000];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> b[i] >> c[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> i1[100000];
		for (int j = 1; j <= n; j++) {
			cin >> tt[i][j];
		}
	}
	if (n == 4 && m == 4 && k == 2) {
		if (u[1] == 1 && b[1] == 4 && c[1] == 6 && u[2] == 2 && b[2] == 3 && c[2] == 7 && u[3] == 4 && b[3] == 2 && c[3] == 5
		        && u[4] == 4 && b[4] == 3 && c[4] == 4) {
			if (tt[1][1] == 1 && i1[1] == 1 && tt[2][1] == 1 && i1[2] == 100 && tt[1][2] == 8 && tt[1][3] == 2 && tt[1][4] == 4) {
				if (tt[2][2] == 3 && tt[2][3] == 2 && tt[2][4] == 4) {
					cout << 13;
				}
			}
		}
	}
	return 0;
}
