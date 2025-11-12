#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int val[maxn][3], n;

long long ans = 0;
struct Node {
	int v, id;
};
vector<Node> q[3];


void dfs(int u, long long sum, int cnta, int cntb, int cntc) {
	if (u > n) {
		if (cnta <= n / 2 && cntb <= n / 2 && cntc <= n / 2) {
			ans = max(ans, sum);
		}
		return;
	}
	if (!(cnta <= n / 2 && cntb <= n / 2 && cntc <= n / 2))
		return;
	dfs(u + 1, sum + val[u][0], cnta + 1, cntb, cntc);
	dfs(u + 1, sum + val[u][1], cnta, cntb + 1, cntc);
	dfs(u + 1, sum + val[u][2], cnta, cntb, cntc + 1);
}

void solve() {
	cin >> n;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		int tmp[3];
		cin >> tmp[0] >> tmp[1] >> tmp[2];
		val[i][0] = tmp[0];
		val[i][1] = tmp[1];
		val[i][2] = tmp[2];

		if (val[i][0] == tmp[2]) {
			q[0].push_back({val[i][0], i});
			sum += val[i][0];

		} else if (val[i][1] == tmp[2]) {
			q[1].push_back({val[i][1], i});
			sum += val[i][1];
		} else if (val[i][2] == tmp[2]) {
			q[2].push_back({val[i][2], i});
			sum += val[i][2];
		}
	}
	if (!(q[0].size() <= n / 2 && q[1].size() <= n / 2 && q[2].size() <= n / 2)) {
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	} else {
		cout << sum << endl;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _;
	cin >> _;
	while (_--) {
		ans = 0;
		for (int i = 0; i < 3; i++)
			q[i].clear();
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
