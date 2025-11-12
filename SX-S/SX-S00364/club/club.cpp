#include <bits/stdc++.h>
using namespace std;
long long T, n, ans, amax, bmax, cmax, ai, bi, ci, sum, suma, sumb, sumc;

struct node {
	int a;
	int b;
	int c;
	int m;
	int s;
	int lm;
};
node p[100005];

bool cmp(node x, node y) {
	return x.m >= y.m;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].a >> p[i].b >> p[i].c;
			p[i].m = max(p[i].a, max(p[i].b, p[i].c));
			p[i].s = min(p[i].a, min(p[i].b, p[i].c));
		}
		sort(p + 1, p + n + 1, cmp);
		for (int i = 1; i <= n / 2; i++) {
			ans += p[i].m;
		}
		cout << ans << '\n';
	}
	return 0;
}
