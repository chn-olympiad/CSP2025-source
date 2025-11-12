#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
const int M = 10 + 5;
int n, m;
int grade[N], mymap[M][M];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int f = n * m;
	for (int i = 1; i <= f; i++) {
		cin >> grade[i];
	}
	int g = grade[1];
	sort(grade + 1, grade + 1 + f, cmp);
	int r = 0;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				mymap[j][i] = grade[++r];
			}
		}
		if (i % 2 != 0) {
			for (int j = 1; j <= n; j++) {
				mymap[j][i] = grade[++r];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (mymap[i][j] == g) {
				cout << j << ' ' << i;
				break;
			}
	}

	return 0;
}

