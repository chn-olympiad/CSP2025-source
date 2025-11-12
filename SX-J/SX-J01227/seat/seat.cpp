#include <bits/stdc++.h>
using namespace std;
int n, m, fs[105], mine, top;
int seats[15][15];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> fs[i];
	}
	mine = fs[1];
	sort(fs + 1, fs + n *m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				seats[i][j] = fs[++top];
			}
		} else {
			for (int j = m; j >= 1; j--) {
				seats[i][j] = fs[++top];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (seats[i][j] == mine) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
