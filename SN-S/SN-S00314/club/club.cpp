#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;

void solve() {
	int n;
	cin >> n;
	
	vector<array<int, 3>> a(n + 1);
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> a[i][j];
		}
	}	
	
	vector<vector<int>> club(3);
	
	for (int i = 1; i <= n; ++i) {
		int maxn = -1, maxid = -1;
		for (int j = 0; j < 3; ++j) {
			if (a[i][j] > maxn) maxn = a[i][j], maxid = j;
		}
		club[maxid].push_back(i);
	}
	
	int maxid = -1, maxsiz = 0;
	for (int i = 0; i < 3; ++i) {
		if (club[i].size() > maxsiz) maxsiz = club[i].size(), maxid = i;
	}
	
	long long ans = 0;
	for (int i = 0; i < 3; ++i) {
		for (int meb : club[i]) {
			ans += a[meb][i];
		}
	}
	
	if ((int)club[maxid].size() <= n / 2) {
		cout << ans << '\n';
		return;
	}
	
	vector<int> sor;
	for (int meb : club[maxid]) {
		int minn_c = 1e9;
		for (int i = 0; i < 3; ++i) {
			if (i == maxid) continue;
			minn_c = min(minn_c, a[meb][maxid] - a[meb][i]);
		}
		sor.push_back(minn_c);
	}	
	sort(sor.begin(), sor.end());
	
	for (int i = 0; i < (int)club[maxid].size() - n / 2; ++i) {
		ans -= sor[i];
	}
	
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
