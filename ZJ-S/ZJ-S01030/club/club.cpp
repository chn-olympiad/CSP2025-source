#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 4;
int n, a[N][M], ans, rec[N], cnt[M];
inline void sol() {
	memset(cnt, 0, sizeof cnt);
	ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int maxx = max({a[i][1], a[i][2], a[i][3]});
		if(maxx == a[i][1]) rec[i] = 1;
		else if(maxx == a[i][2]) rec[i] = 2;
		else rec[i] = 3;
		++cnt[rec[i]];
		ans += maxx;
	}
	int maxx = max({cnt[1], cnt[2], cnt[3]}), delid, lim = (n >> 1);
	if(maxx <= lim) {
		cout << ans << '\n';
		return;
	} else {
		if(maxx == cnt[1]) delid = 1;
		else if(maxx == cnt[2]) delid = 2;
		else delid = 3;
	}
	vector<int> delta;
	for(int i = 1; i <= n; ++i)
		if(rec[i] == delid) {
			int x;
			if(delid == 1) x = a[i][1] - max(a[i][2], a[i][3]);
			else if(delid == 2) x = a[i][2] - max(a[i][1], a[i][3]);
			else x = a[i][3] - max(a[i][1], a[i][2]);
			delta.emplace_back(x);	
		}
	sort(delta.begin(), delta.end());
	int p = 0;
	while(cnt[delid] > lim) {
		ans -= delta[p];
		--cnt[delid], ++p;
	}
	cout << ans << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) sol();
	return 0;
}