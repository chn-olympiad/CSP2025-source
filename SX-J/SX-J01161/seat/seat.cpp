#include <bits/stdc++.h>
using namespace std;
#define int long long
#define r return
int s[10001];
int u[1001][1001];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int i, j;
	cin >> i >> j;
	int n = i * j;
	for (int o = 1; o <= n; o++) {
		cin >> s[i];
	}
	int ans = s[1];
	sort(s + 1, s + n + 1);
	int jj = 0, pp = 1;
	for (int m = j; m >= 1; m--) {
		if (jj == i) {
			for (int t = 1; t <= i; t++) {
				u[t][m] = s[pp];
				if (u[t][m] == ans) {
					cout << t << ' ' << m;
					r 0;
				}
				jj--;
				pp++;
			}
		} else {
			for (int t = i; t >= 1; t--) {
				u[t][m] = s[pp];
				if (u[t][m] == ans) {
					cout << t << ' ' << m;
					r 0;
				}
				jj++;
				pp++;
			}
		}
	}
	r 0;
}
