#include<bits/stdc++.h>
using namespace std;

int n, m, s, a[1100], mp[110][110], xR, x, y, now, d;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	s = n * m;
	for (int i=1; i<=s; i++) {
		scanf("%d", &a[i]);
	}
	xR = a[1];
	sort(a+1, a+s+1);
	x = 1; y = 1; mp[1][1] = a[s];
	now = s; d = 0; 
	while (now > 1) {
		now --;
		if (d == 0 && x == n || d == 1 && x == 1) {
			y++;
			d = 1-d;
		} else {
			if (d == 0) x++;
			else x--;
		}
		mp[x][y] = a[now];
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (mp[i][j] == xR) {
				printf("%d %d", j, i);
			}
		}
	}
	return 0;
}
