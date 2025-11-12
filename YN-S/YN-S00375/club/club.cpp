#include <bits/stdc++.h>
using namespace std;

int t, n,  cna, cnb;
struct node {
	int a, b, c;
} va[100005];
long long ans;

bool  cmp(node e, node f) {
	if (e.a == f.a) {
		if (e.b == f.b) {
			return e.c > f.c;
		} else {
			return e.b > f.b;
		}
	} else {
		return e.a > f.a;
	}
}

void shuru() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> va[i].a >> va[i].b >> va[i].c;
		if (va[i].c == 0) {
			cnb++;
			if (va[i].b == 0) {
				cna++;
			}
		}
	}
	sort(va + 1, va + n + 1, cmp);
}

void dfs(int dep, long long sum, int na, int nb, int nc) {
	if (na > n / 2 || nb > n / 2 || nc > n / 2) {
		return;
	}
	if (dep > n) {
		ans = max(sum, ans);
		return;
	}
	dfs(dep + 1, sum + va[dep].a, na + 1, nb, nc);
	dfs(dep + 1, sum + va[dep].b, na, nb + 1, nc);
	dfs(dep + 1, sum + va[dep].c, na, nb, nc + 1);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t ;
	for (int i = 1; i <= t; i++) {
		shuru();
		if (cna == n) {
			for (int i = 1; i <= n / 2; i++) {
				ans += va[i].a;
			}
			cout << ans << '\n';
			return 0;
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << '\n';
		memset(va, 0, sizeof(va));
		cna = 0, cnb = 0, ans = 0;
	}
	return 0;
}
