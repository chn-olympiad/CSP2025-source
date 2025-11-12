#include <bits/stdc++.h>
using namespace std;

int a[110][110], b[1100];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = 0, m = 0, rj = 0;
	cin >> n >> m;
	cin >> rj;
	b[1] = rj;
	for (int i = 2; i <= n * m; i++) {
		cin >> b[i];
	}
	sort(b + 1, b + n *m + 1, cmp);
	int cnts = 1;
	for (int i = 1; i <= m; i++) {
		int j;
		if (i % 2 != 0) { 	//上到下
			for (j = 1; j <= n; j++) {
				a[j][i] = b[cnts];
				cnts++;
			}

		} else {  	//下到上
			for (j = n; j >= 1; j--) {
				a[j][i] = b[cnts];
				cnts++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == rj) {
				cout << j << " ";
				cout << i ;
				return 0;
			}
		}
	}
	return 0;
}
