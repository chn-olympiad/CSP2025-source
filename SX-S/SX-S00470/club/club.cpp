#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int high;
int b1, c1;

struct m {
	int a, b, c;
};
m g[100005];
int ans;

bool cmp1(m x, m y) {
	return x.a > y.a;
}

void dfs(int x, int y, int z, int i, int anss) {
	if (i == n) {
		ans = max(ans, anss);
		return ;
	}
	if (x + 1 <= high) {
		dfs(x + 1, y, z, i + 1, anss + g[i].a);
	}
	if (y + 1 <= high) {
		dfs(x, y + 1, z, i + 1, anss + g[i].b);
	}
	if (z + 1 <= high) {
		dfs(x, y, z + 1, i + 1, anss + g[i].c);
	}
}

int main() {
	freopen("club1.in", "r", stdin);
	cin >> t;
	while (t--) {
		ans = 0;
		b1 = 0;
		c1 = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> g[i].a >> g[i].b >> g[i].c;
			if (g[i].b == 0) {
				b1++;
			}
			if (g[i].c == 0) {
				c1++;
			}
		}
		high = n / 2;
		if (b1 == c1 && c1 == n) {
			sort(g, g + n, cmp1);
			for (int i = 0; i < high; i++) {
				ans += g[i].a;
			}
			cout << ans;
		} else {
			dfs(0, 0, 0, 0, 0);
			cout << ans << endl;
		}
	}

	return 0;
}