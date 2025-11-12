#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define per(i, r, l) for(int i = r; i >= l; --i)
using namespace std;
const int N = 1e5 + 5;
priority_queue<pair<int, int>,  vector<pair<int, int> >, greater<pair<int, int> > > q[3];
int n, a[N][3], ans;
void solve(){
	cin >> n, ans = 0;
	rep(i, 0, 2) while (!q[i].empty()) q[i].pop();
	rep(i, 1, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
	rep(i, 1, n){
		if(a[i][0] > a[i][1] && a[i][0] > a[i][2])
			q[0].push({a[i][0] - max(a[i][1], a[i][2]), i});
		else if(a[i][1] > a[i][0] && a[i][1] > a[i][2])
			q[1].push({a[i][1] - max(a[i][0], a[i][2]), i});
		else
			q[2].push({a[i][2] - max(a[i][0], a[i][1]), i});
		ans += max(a[i][0], max(a[i][1], a[i][2]));
	}
	int op = -1;
	if(q[0].size() > n / 2) op = 0;
	if(q[1].size() > n / 2) op = 1;
	if(q[2].size() > n / 2) op = 2;
	if(op == -1){
		cout << ans << '\n';
		return;
	}
	while(q[op].size() > n / 2){
		int x = q[op].top().first;
		q[op].pop();
		ans -= x;
	}
	cout << ans << '\n';
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}

