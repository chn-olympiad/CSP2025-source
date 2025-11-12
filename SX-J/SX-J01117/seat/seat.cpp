#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 15;
int a[N][N];
int b[105];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int o = 0;
	for (int i = 1; i <= n * m; i++) {
		cin >> b[i];
	}
	int l = b[1];
	sort(b + 1, b + n *m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= m; j++) {
				o++;
				if (b[o] == l) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		} else	if (i % 2 == 0) {
			for (int j = m; j >= 1; j--) {
				o++;
				if (b[o] == l) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}

}
