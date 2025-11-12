#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 +5;
int a[N], b[N], c[N], o[N];
int n, m, k;
int l[N][N];
int h[N][15];
bool j[N];
long long ah = -1;

void f(int a, long long ahh) {
	bool w = 0;
	for (int i = 1; i <= n; i++) {
		if (j[i] == 0 && i != a) {
			w = 1;
		}
		if (i == a || l[a][i] == -1) {
			continue;
		}
		bool d = 1;
		w = 1;
		for (int k1 = 1; k1 <= n; k++) {
			if (k1 == a || k1 == i) {
				continue;
			}
		}
		if (d) {
			ahh += l[a][i];
		} else {
			int l1 = l[a][i];
			l[a][i] = -1;
			l[i][a] = -1;
			f(i, ahh + l[a][i]);
			l[i][a] = l1;
			l[i][a] = l1;
		}
	}
	if (w == 0) {
		if (ah != -1) {
			ah = min(ah, ahh);
		} else {
			ah = ahh;
		}
	}
}

int main() {
	freopen("rode.in", "r", stdin);
	freopen("rode.out", "w", stdout);
	memset(l, -1, sizeof(l));
	for (int i = 0; i <= n; i++) {
		int l1, l2;
		cin >> n >> m >> k;
		cin >> l1 >> l2;
		cin >> l[l1][l2];
		l[l2][l1] = l[l1][l2];
	}
	for (int i = 1; i <= n; i++) {
		cin >> h[0][i];
		for (int j1 = 1; j1 <= n; j144++) {
			cin >> h[i][j1];
		}
	}
	cout << ah;
	return 0;
}
