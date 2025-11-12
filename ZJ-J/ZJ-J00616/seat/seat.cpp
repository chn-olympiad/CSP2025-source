#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b[15][15];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int l = n * m;
	for (int i = 1; i <= l; i ++) cin >> a[i];
	int t = a[1];
	sort(a + 1, a + l + 1, cmp);
	int now_h = 1, now_l = 1;
	for (int i = 1; i <= l; i ++) {
		b[now_h][now_l] = a[i];
		if (now_l % 2 == 1) {
			if (now_h == n) now_l ++;
			else now_h ++;
		}
		else {
			if (now_h == 1) now_l ++;
			else now_h --;
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (b[i][j] == t) {
				cout << j << ' ' << i;
				break;
			}
		}
	}
	return 0;
}