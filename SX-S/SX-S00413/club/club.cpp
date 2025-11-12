#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

struct node {
	int dt;
	int zd;
	int zdn;
	int cdn;
};
node r[N];
int f[N], s[N], t[N];

pair<int, int> fnd(int a, int b, int c) {
	if (a >= b && b >= c) {
		return {1, 2};
	}
	if (a >= c && c >= b) {
		return {1, 3};
	}
	if (b >= a && a >= c) {
		return {2, 1};
	}
	if (b >= c && c >= a) {
		return {2, 3};
	}
	if (c >= a && a >= b) {
		return {3, 1};
	}
	if (c >= b && b >= a) {
		return {3, 2};
	}
}

bool cmp(node a, node b) {
	if (a.dt != b.dt) {
		if (a.dt > b.dt)
			return true;
		else
			return false;
	} else
		return a.zd > b.zd;
}
int cl[10];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	typedef pair<int, int> PII;
	int T;
	cin >> T;
	while (T--) {
		cl[1] = 0;
		cl[2] = 0;
		cl[3] = 0;
		int n;
		cin >> n;
		int hst = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> f[i] >> s[i] >> t[i];
			PII k = fnd(f[i], s[i], t[i]);
			int mx = k.first;
			int md = k.second;
			int maxn, midn;
			if (mx == 1)
				maxn = f[i];
			if (mx == 2)
				maxn = s[i];
			if (mx == 3)
				maxn = t[i];
			if (md == 1)
				midn = f[i];
			if (md == 2)
				midn = s[i];
			if (md == 3)
				midn = t[i];
			r[i].dt = maxn - midn;
			r[i].zd = maxn;
			r[i].zdn = mx;
			r[i].cdn = md;
		}
		sort(r + 1, r + n + 1, cmp);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int p = r[i].zdn;
			int l = r[i].cdn;
			if (cl[p] < hst) {
				cl[p]++;
				ans += r[i].zd;
			} else {
				cl[l]++;
				ans += (r[i].zd - r[i].dt);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
