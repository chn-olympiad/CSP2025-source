#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, flag = 0;
pair <int, int> tmp[N];
struct Node {
	pair <int, int> a[5];
	int mx; 
	bool operator < (const Node& node) const {
		return mx > node.mx;
	}
} t[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j)
			cin >> t[i].a[j].first, t[i].a[j].second = j;
		sort(t[i].a + 1, t[i].a + 4, greater < pair <int, int> > ());
		t[i].mx = t[i].a[1].first;
	}
	sort(t + 1, t + n + 1);
	int ans = 0, cnt[4] = {};
	flag = 0;
	for (int i = 1; i <= n; ++i) {
		int id = t[i].a[1].second;
		if(cnt[id] == n / 2) {
			flag = id;
			break;
		}
		else ++ cnt[id];
	}
	if(flag) {
		int tot = 0;
		for (int i = 1; i <= n; ++i) {
			int id = t[i].a[1].second;
			if(id != flag) ans += t[i].a[1].first;
			else tmp[++ tot] = make_pair(t[i].a[1].first - t[i].a[2].first, i);
		}
		sort(tmp + 1, tmp + tot + 1, greater < pair <int, int> > ());
		int cnt = 0;
		for (int i = 1; i <= tot; ++i) {
			if(cnt >= n / 2) ans += t[tmp[i].second].a[2].first;
			else ans += t[tmp[i].second].a[1].first, ++ cnt;
		}
		
	} else {
		for (int i = 1; i <= n; ++i) ans += t[i].a[1].first;
	}
	cout << ans << '\n';
	return;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while(T --) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
