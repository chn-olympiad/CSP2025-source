#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

void solve() {
	int n;
	cin >> n;
	
	vector<array<pii, 3>> a(n);
	i64 res = 0;
	vector<int> cnt(3);
	for (int i = 0; i < n; i ++) {
		for (int j : {0, 1, 2})
			cin >> a[i][j].fi, a[i][j].se = j;
		sort(a[i].begin(), a[i].end());
		res += a[i][2].fi, cnt[a[i][2].se] ++;
	}
	
	int mxcnt = *max_element(cnt.begin(), cnt.end());
	if (mxcnt > n / 2) {
		vector<int> cost;
		for (int i = 0; i < n; i ++)
			if (cnt[a[i][2].se] == mxcnt)
				cost.push_back(a[i][1].fi - a[i][2].fi);
		sort(cost.begin(), cost.end(), greater<int>());
		
		for (int i = 0; i < mxcnt - n / 2; i ++)
			res += cost[i];
			
		cout << res << '\n';
	} else cout << res << '\n';
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	
	while (T -- ) solve();
	
	return 0;
}
