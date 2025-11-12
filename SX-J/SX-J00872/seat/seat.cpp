#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int a[N];
int b[11][11];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int k = 0;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	k = a[1];
	int c = n * m;
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				b[i][j] = a[c];
				c--;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				b[i][j] = a[c];
				c--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == k) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
