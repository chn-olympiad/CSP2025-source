#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

struct Node {
	int x, y, z;
	bool operator<(const Node &rhs) const {
		return x < rhs.x;
	}
};

int n;
Node arr[MAX_N + 1];
int ans;

void dfs(int idx, int sum, int cnt1, int cnt2, int cnt3) {
	if (max({cnt1, cnt2, cnt3}) > n / 2) return;
	if (idx == n + 1) {
		ans = max(ans, sum);
		return;
	}
	dfs(idx + 1, sum + arr[idx].x, cnt1 + 1, cnt2, cnt3);
	dfs(idx + 1, sum + arr[idx].y, cnt1, cnt2 + 1, cnt3);
	dfs(idx + 1, sum + arr[idx].z, cnt1, cnt2, cnt3 + 1);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		bool flag = true;
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i].x >> arr[i].y >> arr[i].z;
			flag = flag && !arr[i].y && !arr[i].z;
		}
		if (flag) {
			sort(arr + 1, arr + 1 + n);
			int ans = 0;
			for (int i = n; i >= n / 2 + 1; --i) {
				ans += arr[i].x;
			}
			cout << ans << "\n";
			continue;
		}
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}
