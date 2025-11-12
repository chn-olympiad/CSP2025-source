#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, cnt[4];
pair<int, int> a[N][4];


void solve() {
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> que;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j].first;
			a[i][j].second = j;
		}
		sort(a[i] + 1, a[i] + 4);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[i][3].first;
		cnt[a[i][3].second]++;
	}
	int now = -1;
	for (int i = 1; i <= 3; i++) if (cnt[i] > n / 2) now = i;
	if (now == -1) {
		cout << ans << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i][3].second == now) {
			que.push(a[i][3].first - a[i][2].first);
		}
	}
	int c = cnt[now] - n / 2;
	for (int i = 1; i <= c; i++) {
		int val = que.top();
		que.pop();
		ans -= val;
	}
	cout << ans << '\n';
}


signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
	return 0;
}

/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/

