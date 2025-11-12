#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, w[N][3], d[N];
int p[N], c[3];

void mian() {
	scanf("%d", &n); int res = 0; c[0] = c[1] = c[2] = 0;
	for (int i = 1; i <= n; i ++ ) scanf("%d%d%d", &w[i][0], &w[i][1], &w[i][2]);
	for (int i = 1; i <= n; i ++ ) {
		p[i] = 0;
		for (int j = 0; j < 3; j ++ )
			if (w[i][j] > w[i][p[i]]) p[i] = j;
		res += w[i][p[i]]; d[i] = 1e9;
		for (int j = 0; j < 3; j ++ )
			if (p[i] != j) d[i] = min(d[i], w[i][p[i]] - w[i][j]);
		c[p[i]] ++ ;
	} int pos = -1;
	for (int i = 0; i < 3; i ++ ) if (c[i] > n / 2) pos = i;
	if (~pos) {
		vector<int> cur;
		for (int i = 1; i <= n; i ++ ) if (p[i] == pos) cur.push_back(i);
		sort(cur.begin(), cur.end(), [](int x, int y) {
			return d[x] < d[y];
		});
		for (int i = 0; i < c[pos] - n / 2; i ++ )
			res -= d[cur[i]];
		printf("%d\n", res);
	} else printf("%d\n", res);
}

int main() {
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T -- ) mian();
	return 0;
}
