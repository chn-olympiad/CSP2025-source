#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	int mx = 0;
	for (int i = 0; i < a.size(); i ++) {
		mx += a[i];
	}
	int c = mx % 998;
	int b = mx % 244;
	int d = mx % 353;
	int ms = max(c, b);
	int md = max(ms, d);
	cout << ms << endl;
	return 0;
}
