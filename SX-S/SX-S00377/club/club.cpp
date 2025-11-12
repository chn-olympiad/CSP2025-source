#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t, n, ans;

struct s {
	int aa, bb, cc;
};
s m[N];

void dfs(int a, int b, int c, int x, int ss) {
	if (a > n / 2 || b > n / 2 || c > n / 2) {
		return ;
	}
	for (int i = x; i < n; i++) {
		dfs(a + 1, b, c, x + 1, ss + m[i].aa);
		dfs(a, b + 1, c, x + 1, ss + m[i].bb);
		dfs(a, b, c + 1, x + 1, ss + m[i].cc);
	}
	ans = max(ans, ss);
	return ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> m[i].aa >> m[i].bb >> m[i].cc;
		}
		dfs(1, 0, 0, 1, m[0].aa);
		dfs(0, 1, 0, 1, m[0].bb);
		dfs(0, 0, 1, 1, m[0].cc);
		cout << ans << endl;
	}
	return 0;
}
