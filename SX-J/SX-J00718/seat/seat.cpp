#include <bits/stdc++.h>
using namespace std;
int n, m, b[10000], a[100][100], t, tot;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> b[i];
	}
	t = b[1];
	sort(b + 1, b + 1 + n *m, cmp);
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				a[i][j] = b[++tot];
				if (a[i][j] == t) {
					cout << j << " " << i;
					return 0;
				}
			}
		} else {
			for (int k = n; k >= 1; k--) {
				a[k][j] = b[++tot];
				if (a[k][j] == t) {
					cout << j << " " << k;
					return 0;
				}
			}
		}
	}
	return 0;
}
