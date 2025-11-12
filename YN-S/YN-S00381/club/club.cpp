#include <bits/stdc++.h>//3214
using namespace std;
#define int long long
const int N = 1e5+10;
int n;

struct node {
	int a[5];
} p[N];
bool mp[N][3];

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	for (int q = 1; q <= T; q++) {
		cin >> n;
		memset(p, 0, sizeof(p));
		memset(mp, 0, sizeof(mp));
		int len[3];
		len[1] = len[2] = len[3] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> p[i].a[j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (mp[i][1] == true) {
					if (mp[j][2] == true) {
						if (p[i].a[2] + p[j].a[1] > p[i].a[1] + p[j].a[2]) {
							mp[i][1] = mp[j][2] = false;
							mp[i][2] = mp[j][1] = true;
						}
					} else if (mp[j][3] == true) {
						if (p[i].a[3] + p[j].a[1] > p[i].a[1] + p[j].a[3]) {
							mp[i][1] = mp[j][3] = false;
							mp[i][3] = mp[j][1] = true;
						}
					}
				} else if (mp[i][2] == true) {
					if (mp[j][1] == true) {
						if (p[i].a[1] + p[j].a[2] > p[i].a[2] + p[j].a[1]) {
							mp[i][2] = mp[j][1] = false;
							mp[i][1] = mp[j][2] = true;
						}
					} else if (mp[j][3] == true) {
						if (p[i].a[3] + p[j].a[2] > p[i].a[2] + p[j].a[3]) {
							mp[i][2] = mp[j][3] = false;
							mp[i][3] = mp[j][2] = true;
						}
					}
				} else {
					if (mp[j][1] == true) {
						if (p[i].a[1] + p[j].a[3] > p[i].a[3] + p[j].a[1]) {
							mp[i][3] = mp[j][1] = false;
							mp[i][1] = mp[j][3] = true;
						}
					} else if (mp[j][2] == true) {
						if (p[i].a[2] + p[j].a[3] > p[i].a[3] + p[j].a[2]) {
							mp[i][3] = mp[j][2] = false;
							mp[i][2] = mp[j][3] = true;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (max(max(p[i].a[1], p[i].a[2]), p[i].a[3]) == p[i].a[3]) {
				mp[i][3] = true;
				len[3]++;
			} else if (max(max(p[i].a[1], p[i].a[2]), p[i].a[3]) == p[i].a[2]) {
				mp[i][2] = true;
				len[2]++;
			} else {
				mp[i][1] = true;
				len[1]++;
			}
		}
		if (len[1] > (n / 2)) {
			while (len[1] > (n / 2)) {
				int i = 1;
				while (1) {
					if (mp[i][1] == true) {
						break;
					}
					i++;
				}
				int ld12 = i, ld13 = i;
				for (; i <= n; i++) {
					if (p[i].a[2] > p[ld12].a[2] && mp[i][1]) {
						ld12 = i;
					}
					if (p[i].a[3] > p[ld13].a[3] && mp[i][1]) {
						ld13 = i;
					}
				}
				if (p[ld12].a[2] > p[ld13].a[3] && len[2] + 1 <= (n / 2)) {
					mp[ld12][1] = false;
					len[1]--;
					mp[ld12][2] = true;
					len[2]++;
				} else {
					mp[ld13][1] = false;
					len[1]--;
					mp[ld13][3] = true;
					len[3]++;
				}
			}
		}
		if (len[2] > (n / 2)) {
			while (len[2] > (n / 2)) {
				int i = 1;
				while (1) {
					if (mp[i][2] == true) {
						break;
					}
					i++;
				}
				int ld21 = i, ld23 = i;
				for (; i <= n; i++) {
					if (p[i].a[1] > p[ld21].a[1] && mp[i][2]) {
						ld21 = i;
					}
					if (p[i].a[3] > p[ld23].a[3] && mp[i][2]) {
						ld23 = i;
					}
				}
				if (p[ld21].a[1] > p[ld23].a[3] && len[1] + 1 <= (n / 2)) {
					mp[ld21][2] = false;
					len[2]--;
					mp[ld21][1] = true;
					len[1]++;
				} else {
					mp[ld23][2] = false;
					len[2]--;
					mp[ld23][3] = true;
					len[3]++;
				}
			}
		}
		if (len[3] > (n / 2)) {
			while (len[3] > (n / 2)) {
				int i = 1;
				while (1) {
					if (mp[i][3] == true) {
						break;
					}
					i++;
				}
				int ld31 = i, ld32 = i;
				for (; i <= n; i++) {
					if (p[i].a[1] > p[ld31].a[1] && mp[i][3]) {
						ld31 = i;
					}
					if (p[i].a[2] > p[ld32].a[2] && mp[i][3]) {
						ld32 = i;
					}
				}
				if (p[ld31].a[1] > p[ld32].a[2] && len[1] + 1 <= (n / 2)) {
					mp[ld31][3] = false;
					len[3]--;
					mp[ld31][1] = true;
					len[1]++;
				} else {
					mp[ld32][3] = false;
					len[3]--;
					mp[ld32][2] = true;
					len[2]++;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (mp[i][1] == true) {
				ans += p[i].a[1];
			} else if (mp[i][2] == true) {
				ans += p[i].a[2];
			} else {
				ans += p[i].a[3];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
