#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;

struct ZW {
	int bh;
	int z;
} a[N];

int cmd(ZW a1, ZW b) {
	return a1.z > b.z;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i * m + j].z;
			a[i * m + j].bh = i * m + j;
		}
	}
	sort(a + 1, a + 1 + n *m, cmd);
	int i = 1, j = 1, k = 0;
	while (1) {
		k++;
		if (a[k].bh == 1) {
			cout << j << ' ' << i;
			return 0;
		}
		if (i == n && j % 2 == 1) {
			j++;
		} else if (i == 1 && j % 2 == 0) {
			j++;
		} else if (j % 2 == 1) {
			i++;
		} else {
			i--;
		}
	}
}
