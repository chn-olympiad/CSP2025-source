#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
const int M = 1e4+5;
long long st[M][M];
long long c[M];
int fa[M];

struct node {
	int a;
	int b;
	int w;
};
node dx[N];

bool cmp(node x, node y) {
	return x.w < y.w;
}

int fnd(int a) {
	if (a != fa[a])
		fa[a] = fnd(fa[a]);
	return fa[a];
}

void un(int a, int b) {
	int x = fnd(a);
	int y = fnd(b);
	if (fa[x] != fa[y])
		fa[x] = fa[y];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m;
	long long k;
	cin >> n >> m >> k;
	const long long wqd = 1e18;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			st[i][j] = wqd;
		}
	}
	for (int i = 1; i <= m; i++) {
		int ka, kb;
		long long kc;
		cin >> ka >> kb >> kc;
		st[ka][kb] = kc;
		st[kb][ka] = kc;
	}
	for (int s = 1; s <= k; s++) {
		long long wei;
		cin >> wei;
		for (int j = 1; j <= n; j++) {
			cin >> c[j];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 1; j++) {
				if ((c[i] + c[j] + wei) < st[i][j]) {
					st[i][j] = c[i] + c[j] + wei;
					st[j][i] = c[i] + c[j] + wei;
				}
			}
		}
	}
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (st[i][j] != 0x3f) {
				dx[cnt].a = i;
				dx[cnt].b = j;
				dx[cnt].w = st[i][j];
				cnt++;
			}
		}
	}
	sort(dx + 1, dx + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		fa[i] = i;
	}
	long long ans = 0;
	for (int i = 1; i <= cnt; i++) {
		if (fnd(dx[i].a) == fnd(dx[i].b))
			continue;
		un(dx[i].a, dx[i].b);
		ans += dx[i].w;
	}
	cout << ans;
	return 0;
}
