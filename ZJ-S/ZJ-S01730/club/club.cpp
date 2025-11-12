#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false); \
cin.tie(nullptr); \
cout.tie(nullptr);
void fr() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
}
ll t, n, a[100005][5], ans;
void dfs(ll w, ll sum, ll x, ll y, ll z) {
	if (w == n + 1) {
		ans = (ans > sum ? ans : sum);
		return ;
	}
	if (x + 1 <= n / 2) {
		dfs(w + 1, sum + a[w][1], x + 1, y, z);
	}
	if (y + 1 <= n / 2) {
		dfs(w + 1, sum + a[w][2], x, y + 1, z);
	}
	if (z + 1 <= n / 2) {
		dfs(w + 1, sum + a[w][3], x, y, z + 1);
	}
}
int main() {
	fr();
	IOS
	cin >> t;
	while(t--) {
		cin >> n;
		bool as = 1, bs = 1, cs = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (j == 3 && a[i][j] != 0) {
					cs = 0;
				}
				if (j == 2 && a[i][j] != 0) {
					bs = 0;
				}
				if (!(a[i][j] == 20000 || a[i][j] == 0)) {
					as = 0;
				}
			}
		}
		ans = 0;
		if (n <= 10) {
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
			continue;
		}
		if (bs && cs) {
			ll ap[100005];
			for (int i = 1; i <= n; i++) {
				ap[i] = a[i][1];
			}
			sort(ap + 1, ap + n + 1);
			for (int i = n; i > n / 2; i--) {
				ans += ap[i];
			}
			cout << ans << "\n";
			continue;
		}
		if (cs) {
			for (int i = 1; i <= n; i++) {
				ans += (a[i][1] > a[i][2] ? a[i][1] : a[i][2]);
			}
			cout << ans << "\n";
			continue;
		}
		ll ad = 0, bd = 0, cd = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i][1] > a[i][2] && a[i][1] > a[i][3]) {
				if (ad <= n / 2) {
					ad++;
					ans += a[i][1];
				} else {
					if (a[i][2] > a[i][3] && bd <= n / 2) {
						bd++;
						ans += a[i][2];
					} else if (a[i][2] <= a[i][3] && cd <= n / 2) {
						cd++;
						ans += a[i][3];
					}
				}
			} else if (a[i][2] > a[i][1] && a[i][2] > a[i][3]) {
				if (bd <= n / 2) {
					bd++;
					ans += a[i][2];
				} else {
					if (a[i][1] > a[i][3] && ad <= n / 2) {
						ad++;
						ans += a[i][1];
					} else if (a[i][1] <= a[i][3] && cd <= n / 2) {
						cd++;
						ans += a[i][3];
					}
				}
			} else {
				if (cd <= n / 2) {
					cd++;
					ans += a[i][3];
				} else {
					if (a[i][1] > a[i][2] && ad <= n / 2) {
						ad++;
						ans += a[i][1];
					} else if (a[i][1] <= a[i][2] && bd <= n / 2) {
						bd++;
						ans += a[i][3];
					}
				}
			}	
		}
		cout << ans << "\n";
	} 
	return 0;
}

