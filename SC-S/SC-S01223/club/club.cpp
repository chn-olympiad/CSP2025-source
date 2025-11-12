#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;
int mid(int x, int y, int z) {
	return x + y + z - max({x, y, z}) - min({x, y, z});
}
int p1 = 0, p2 = 0, p3 = 0, d1[N], d2[N], d3[N];
void solve() {
	int n, sum = 0;
	p1 = p2 = p3 = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int mx = max({a, b, c}), md = mid(a, b, c);
		int t = 0;
		if(mx == a) d1[++p1] = mx - md;
		else if(mx == b) d2[++p2] = mx - md;
		else if(mx == c) d3[++p3] = mx - md;
		sum += mx;
	}
	if(p1 > n / 2) {
		int c = p1 - n / 2;
		sort(d1+1, d1+p1+1);
		for(int i = 1; i <= c; i++) sum -= d1[i];
	}
	if(p2 > n / 2) {
		int c = p2 - n / 2;
		sort(d2+1, d2+p2+1);
		for(int i = 1; i <= c; i++) sum -= d2[i];
	}
	if(p3 > n / 2) {
		int c = p3 - n / 2;
		sort(d3+1, d3+p3+1);
		for(int i = 1; i <= c; i++) sum -= d3[i];
	}
	cout << sum << endl;
	return;
}
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
} 