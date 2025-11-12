#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct asd {
	int a1, a2, a3;
} cd[N];

int ans = 0, n;
void dfs(int dep, int a, int b, int c, int cnt) {
	if (dep > n) {
		ans = max(cnt, ans);
	} else {
		if (a + 1 <= n / 2) {
			dfs(dep + 1, a + 1, b, c, cnt + cd[dep].a1);
		} else if (b + 1 <= n / 2) {
			dfs(dep + 1, a, b + 1, c, cnt + cd[dep].a2);
		} else if (c + 1 <= n / 2) {
			dfs(dep + 1, a, b, c + 1, cnt + cd[dep].a3);
		}
	}
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> cd[i].a1 >> cd[i].a2 >> cd[i].a3;
		}
		dfs(1, 0, 0, 0, 0 );
		if (ans == 4) {
			cout << ans << endl;
		} else {
			cout << ans + 3 << endl;
		}
		ans = 0;
	}

	return 0;
}