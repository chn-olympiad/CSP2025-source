#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int sum[5];
int n;

struct ll {
	int m[4];
} a[N];

struct kk {
	int su[4], ans, jj[4];
} f[N][4];

bool px1(ll a, ll b) {
	return a.m[0] > b.m[0];
}

bool px2(ll a, ll b) {
	return a.m[1] > b.m[1];
}

bool px3(ll a, ll b) {
	return a.m[2] > b.m[2];
}

bool px4(ll a, ll b) {
	return a.m[3] > b.m[3];
}

bool px5(ll a, ll b) {
	if (a.m[1] == b.m[1]) {
		if (a.m[2] == b.m[2])
			return a.m[3] > b.m[3];
		return a.m[2] > b.m[2];
	}
	return a.m[1] > b.m[1];
}

void wcis() {
	f[1][1].ans = a[1].m[1], f[1][1].su[1] = 1;
	f[1][2].ans = a[1].m[2], f[1][2].su[2] = 1;
	f[1][3].ans = a[1].m[3], f[1][3].su[3] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			f[i][j].ans = 0;
			for (int k = 1; k <= 3; k++) {
				if (f[i - 1][k].su[j] >= n / 2)
					f[i - 1][k].jj[j] = 0;
				else
					f[i - 1][k].jj[j] = 1;
			}
		}
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				f[i][j].ans = max(f[i][j].ans, f[i - 1][k].ans * f[i - 1][k].jj[j] + a[i].m[j]);
			}
			for (int k = 1; k <= 3; k++) {
				if (f[i][j].ans - a[i].m[j] == f[i - 1][k].ans * f[i - 1][k].jj[j]) {
					for (int l = 1; l <= 3; l++) {
						f[i][j].su[l] = f[i - 1][k].su[l];
					}
					f[i][j].su[j]++;
					break;
				}
			}
		}
	}
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].m[1] >> a[i].m[2] >> a[i].m[3];
			a[i].m[0] = a[i].m[1] + a[i].m[2] + a[i].m[3];
		}
		int aa = 0;
		wcis();
		aa = max(f[n][1].ans, max(f[n][2].ans, f[n][3].ans));
		sort(a + 1, a + 1 + n, px1);
		wcis();
		aa = max(aa, max(f[n][1].ans, max(f[n][2].ans, f[n][3].ans)));
		sort(a + 1, a + 1 + n, px2);
		wcis();
		aa = max(aa, max(f[n][1].ans, max(f[n][2].ans, f[n][3].ans)));
		sort(a + 1, a + 1 + n, px3);
		wcis();
		aa = max(aa, max(f[n][1].ans, max(f[n][2].ans, f[n][3].ans)));
		sort(a + 1, a + 1 + n, px4);
		wcis();
		aa = max(aa, max(f[n][1].ans, max(f[n][2].ans, f[n][3].ans)));
		sort(a + 1, a + 1 + n, px5);
		wcis();
		aa = max(aa, max(f[n][1].ans, max(f[n][2].ans, f[n][3].ans)));
		cout << aa << '\n';
//		cout << f[n][1].ans << ' ' << f[n][2].ans << ' ' << f[n][3].ans << '\n';
	}
	return 0;
}
/////// zhk ±£ÓÓÎÒAC