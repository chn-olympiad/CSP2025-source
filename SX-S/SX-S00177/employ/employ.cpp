#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

long long n, m;

struct xxx {
	int x, y;
} c[510];

bool cmp(xxx io, xxx oi) {
	return io.y < oi.y;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	string s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		c[i].x = i;
		cin >> c[i].y;
	}
	sort(c + 1, c + n + 1, cmp);
	if (m == 1) {
		int sm = 1;
		while (c[sm].y == 0) {
			sm++;
		}
		cout << n - sm;
		return 0;
	}

	return 0;
}
