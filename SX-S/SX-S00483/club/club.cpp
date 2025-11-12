#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, t;
int a[5][200005];
int fac[200005];
int num[5];
int tag[200005];

int check(int x) {
	int maxn = max(a[1][x], max(a[2][x], a[3][x]));
	for (int i = 1; i <= 3; i++) {
		if (maxn == a[i][x]) {
			num[i]++;
			tag[x] = i;
			break;
		}
	}
	return maxn;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			ans += check(i);
		}
		int tar = 0;
		for (int i = 1; i <= 3; i++) {
			if (num[i] == max(num[1], max(num[2], num[3]))) {
				tar = i;
			}
		}
		int maxn = 0;
		for (int i = 1; i <= n; i++) {
			fac[i] = -1e9;
			if (tag[i] != tar)
				continue;
			for (int j = 1; j <= 3; j++) {
				if (j != tar) {
					maxn = max(maxn, a[j][i]);
				}
			}
			fac[i] = maxn - a[tar][i];
			maxn = 0;
		}
		sort(fac + 1, fac + 1 + n);
		for (int i = n; i >= 1 && num[tar] > n / 2; i--) {
			ans += fac[i];
			num[tar]--;
		}
		cout << ans << '\n';
		memset(num, 0, sizeof(num));
	}
}
