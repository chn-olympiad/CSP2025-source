#include <bits/stdc++.h>
using namespace std;
int a[10005];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int z = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	int yyy, xxx;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == z) {
			yyy = (i - 1) / m + 1;
			if (yyy % 2 == 1) {
				xxx = i % m;
				if (xxx == 0) {
					xxx = m;
				}
			} else if (yyy % 2 == 0) {
				xxx = i % m;
				if (xxx == 0) {
					xxx = m;
				}
				xxx = m - xxx + 1;
			}
			cout << yyy << " " << xxx;
			return 0;
		}
	}
	return 0;
}
