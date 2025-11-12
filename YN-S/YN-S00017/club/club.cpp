#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

struct c3 {
	int a;
	int b;
	int c;
} e[N];
int ans = 0, n;

void dfs(int dep, int sum, int ja, int jb, int jc, int n) {
	if (dep > n) {
		ans = max(ans, sum);
	} else {
		if (ja + 1 <= n / 2) {
			dfs(dep + 1, sum + e[dep].a, ja + 1, jb, jc, n);
		}
		if (jb + 1 <= n / 2) {
			dfs(dep + 1, sum + e[dep].b, ja, jb + 1, jc, n);
		}
		if (jc + 1 <= n / 2) {
			dfs(dep + 1, sum + e[dep].c, ja, jb, jc + 1, n);
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> e[i].a >> e[i].b >> e[i].c;
		}
		dfs(1, 0, 0, 0, 0, n);
		cout << ans << "\n";
	}
	return 0;
}