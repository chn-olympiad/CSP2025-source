// 吴昱胤 SN-S00113 西安铁一中国际合作学校
// By 0x0F
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long
int a[100010][4];
int ch[100010], cnt[10];
priority_queue<int> pq;
void solve() { 
	int n; cin >> n;
	for (int i = 1; i <= n; i++) a[i][1] = a[i][2] = a[i][3] = 0; 
	for (int i = 1; i <= n; i++) ch[i] = 0;
	for (int i = 1; i <= n; i++) 
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	int lmt = n / 2;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int mx = 0, idx = 0;
		if (a[i][1] >= max(a[i][2], a[i][3])) mx = a[i][1], idx = 1;
		else if (a[i][2] >= max(a[i][1], a[i][3])) mx = a[i][2], idx = 2;
		else if (a[i][3] >= max(a[i][1], a[i][2])) mx = a[i][3], idx = 3;
		ans += mx; ch[i] = idx;
	}
	cnt[1] = cnt[2] = cnt[3] = 0;
	while (!pq.empty()) pq.pop();
	for (int i = 1; i <= n; i++) cnt[ch[i]]++;
	int p = 0, d = 0;
	if (cnt[1] > lmt) p = 1;
	else if (cnt[2] > lmt) p = 2;
	else if (cnt[3] > lmt) p = 3;
	d = cnt[p] - lmt;
	if (p == 0) {cout << ans << endl; return;}
	for (int i = 1; i <= n; i++) 
		if (ch[i] == p) {
			int mx = 0;
			for (int j = 1; j <= 3; j++) if (j != p) mx = max(mx, a[i][j]);
			pq.push(mx - a[i][p]);
		}
	for (int i = 1; i <= d; i++) {
		int hd = pq.top(); pq.pop();
		ans += hd;
	}
	cout << ans << endl;
}
int main() {
	ios :: sync_with_stdio(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}

