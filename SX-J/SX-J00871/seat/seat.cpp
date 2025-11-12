#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[1010];

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int s;
	for (int i = 1; i <= n * m; i++) {
		cin >> h[i];
		if (i == 1) {
			s = h[i];
		}
	}
	sort(h + 1, h + 1 + n *m, cmp);
	int i = 1, j = 1, p = 0, sum = 1;
	while (i <= n && j <= m) {
		if (h[sum] == s) {
			cout << j << ' ' << i;
			return 0;
		}
		sum++;
		if (p == 0) {
			i++;
		} else {
			i--;
		}
		if (p == 0 && i == n + 1) {
			j++;
			i--;
			p = 1;
		} else {
			if (p == 1 && i == 0) {
				j++;
				i++;
				p = 0;
			}
		}
	}
	return 0;
}