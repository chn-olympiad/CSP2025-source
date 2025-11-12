#include <bits/stdc++.h>
using namespace std;
int _, i, j, k, l;
int t, n;
int m, ans;
int ok[100005][3];
int chooseto[100005];
bool flag;
int s[100005];


void input() {
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &ok[i][0], &ok[i][1], &ok[i][2]);
		s[i] = ok[i][0];
	}
}

void solve() {
	int maxcnt[3] = {0, 0, 0};
	for (i = 0; i < n; i++) {
		m = 0;
		for (j = 1; j < 3; j++) {
			if (ok[i][j] > ok[i][m])
				m = j;
			else if (ok[i][j] == ok[i][m]) {
				if (maxcnt[m] >= maxcnt[j])
					m = j;
			}
		}
		chooseto[i] = m;
		maxcnt[m]++;
	}
	for (i = 0; i < 3; i++)
		if (maxcnt[i] > n / 2)
			flag = 1;
	if (!flag) {
		for (i = 0; i < n; i++)
			ans += ok[i][chooseto[i]];
	} else {
		if (maxcnt[0] == n) {
			sort(s, s + n);
			for (i = 0; i < n / 2; i++)
				ans += s[n - 1 - i];
		} else {
			for (i = 0; i < n; i++)
				ans += ok[i][chooseto[i]];
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (_ = 0; _ < t; _++) {
		input();
		flag = 0;
		ans = 0;
		solve();
	}
	return 0;
}