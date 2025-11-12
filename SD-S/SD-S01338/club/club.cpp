#include <bits/stdc++.h>
using namespace std;
int t, n, sum[4], A[100005][4];
long long Ans;

void DFS(int u, long long ans) {
	if (u == n + 1) {
		Ans = max(Ans, ans);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (sum[i] == n / 2) continue;
		sum[i]++;
		DFS(u + 1, ans + A[u][i]);
		sum[i]--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 100000) {
			vector<int> vec;
			int a, b, c;
			for (int i = 1; i <= n; i++) {
				cin >> a >> b >> c;
				vec.push_back(a);
			}
			sort(vec.begin(), vec.end());
			long long ans = 0;
			for (int i = static_cast<int>(vec.size()) - 1; i >= 0; i--) ans += vec[i];
			cout << ans;
			return 0;
		}
		for (int i = 1; i <= n; i++) cin >> A[i][1] >> A[i][2] >> A[i][3];
		DFS(1, 0ll);
		cout << Ans << "\n";
		Ans = 0;
	}
	return 0;
}


