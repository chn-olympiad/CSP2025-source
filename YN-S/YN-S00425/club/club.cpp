#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, cnt = 0, n, maxx = INT_MIN;

struct xinxi {
	int a, b, c;
} s[100005];

int dfs(int d, int dq, int sum, int aa, int bb, int cc) {
	if (d > n) {
		if (aa >= 0 && bb >= 0 && cc >= 0) {
			maxx = max(maxx, sum);
		}

		return 0;
	}

	if (aa < 0 || bb < 0 || cc < 0) {
		return 0;
	}

	if (dq == 1) {
		sum += s[d].a;
		aa--;
	} else if (dq == 2) {
		sum += s[d].b;
		bb--;
	} else if (dq == 3) {
		sum += s[d].c;
		cc--;
	}

	dfs(d + 1, 1, sum, aa, bb, cc);
	dfs(d + 1, 2, sum, aa, bb, cc);
	dfs(d + 1, 3, sum, aa, bb, cc);
	return 0;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		maxx = INT_MIN;
		cnt = 0;
		n = 0;
		cin >> n;
		int x = n / 2;

		for (int i = 1; i <= n; i++) {

			cin >> s[i].a >> s[i].b >> s[i].c;
		}

		dfs(1, 1, 0, x, x, x);
		dfs(1, 2, 0, x, x, x);
		dfs(1, 3, 0, x, x, x);
		cout << maxx << endl;
	}

	return 0;
}
