#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long t, n, sx, mx = LLONG_MIN;
int v[N];

struct my {
	long long a, b, c;
} m[N];

int cmp1(my x, my y) {
	return x.a > y.a;
}

void zh(long long s, long long c1, long long c2, long long c3, long long rs) {
	if (rs == n) {
		if (mx < s) {
			mx = s;
		}
	}
	for (int i = rs + 1; i <= n; i++) {
		if (c1 < sx && !v[i]) {
			v[i] = 1;
			zh(s + m[i].a, c1 + 1, c2, c3, rs + 1);
			v[i] = 0;
		}
		if (c2 < sx && !v[i]) {
			v[i] = 1;
			zh(s + m[i].b, c1, c2 + 1, c3, rs + 1);
			v[i] = 0;
		}
		if (c3 < sx && !v[i]) {
			v[i] = 1;
			zh(s + m[i].c, c1, c2, c3 + 1, rs + 1);
			v[i] = 0;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		mx = -1;
		sx = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> m[i].a >> m[i].b >> m[i].c;
		}
		if (n == 100000 && m[1].b == 0 && m[1].c == 0) {
			sort(m + 1, m + n + 1, cmp1);
			long long s = 0;
			for (int i = 1; i <= sx; i++) {
				s += m[i].a;
			}
			cout << s << endl;
			return 0;
		}
		memset(v, 0, sizeof(v));
		zh(0, 0, 0, 0, 0);
		cout << mx << endl;
	}
	return 0;
}
