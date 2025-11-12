#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); ++ i)
#define per(i, r, l) for(int i = (r); i >= (l); -- i)

using namespace std;

int a[5], cnt[5];
vector<int> p[5];
void solve() {
	rep(i, 1, 3) {
		cnt[i] = 0;
		p[i].clear();
	}
	
	int ans = 0, n;
	cin >> n;
	rep(i, 1, n) {
		int t = 1;
		rep(j, 1, 3) {
			cin >> a[j];
			if(a[t] < a[j]) t = j;
		}
		sort(a + 1, a + 3 + 1);
		cnt[t] ++;
		p[t].push_back(a[3] - a[2]);
		ans += a[3];
	}
	if(max(cnt[1], max(cnt[2], cnt[3])) <= n / 2) {
		cout << ans << '\n';
		return ;
	}
	int now = 1;
	if(cnt[1] > n / 2) now = 1;
	else if(cnt[2] > n / 2) now = 2;
	else now = 3;
	sort(p[now].begin(), p[now].end());
	int k = cnt[now] - n / 2;
//	cout << "??? " << cnt[now] <<'\n';
	for(int i = 0; i <= k - 1; ++ i) {
		ans = ans - p[now][i];
	}
	cout << ans << '\n';
	
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ) solve();
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

4
3 2 1
5 3 0
4 2 1
3 3 0
*/
