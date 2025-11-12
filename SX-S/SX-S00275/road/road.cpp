#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, k;
int l[N][N];
int c[N][15];
bool q[N];
long long ac = -1;

void f(int a, long long ac1) {
	bool w = 0;
	q[a] = 1;
	for (int i = 1; i <= n; i++) {
		if (i == a || q[a] || l[a][i] == -1) {
			continue;
		}
		bool flag = 1;
		w = 1;
		for (int k1 = 1; k1 <= n; k1++) {
			if (k1 == a || k1 == i) {
				continue;
			}
			if (l[i][k1] != -1) {
				flag = 0;
			}
		}
		if (flag) {
			ac1 += l[a][i];
		} else {
			int l1 = l[a][i];
			l[a][i] = -1;
			l[i][a] = -1;
			f(i, ac1 + l[a][i]);
			l[a][i] = l1;
			l[i][a] = l1;
		}
	}
	if (w == 0) {
		if (ac != -1) {
			ac = min(ac, ac1);
		} else {
			ac = ac1;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	memset(l, -1, sizeof(l));
	for (int i = 1; i <= n; i++) {
		int l1, l2;
		cin >> l1 >> l2;
		cin >> l[l1][l2];
		l[l2][l1] = l[l1][l2];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[0][i];
		for (int j1 = 1; j1 <= n; j1++) {
			cin >> c[i][j1];
		}
	}
	f(1, 0);
	f(2, 0);
	f(3, 0);
	f(4, 0);
	cout << ac;
	return 0;
}