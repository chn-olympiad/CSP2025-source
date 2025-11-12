#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
int n, m, p, x, cnt = 1;
int cei(int a, int b) {
	return a / b + (a % b != 0);
}
signed main() {
	File("seat");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> p;
	for (int i = 2; i <= n * m; i ++) {
		cin >> x;
		cnt += x > p;
	}
	int c = cei(cnt, n), r, t = cnt % n;
	if (c % 2) {
		if (t == 0) r = n;
		else r = t;
	}
	else {
		if (t == 0) r = 1;
		else r = n - t + 1;
	}
	cout << c << " " << r << endl;
	return 0;
}
