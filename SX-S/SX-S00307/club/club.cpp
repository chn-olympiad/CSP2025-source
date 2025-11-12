#include <bits/stdc++.h>
using namespace std;
int n, b, a[100010][4], g[5];

int dfs(int c, int sum, int f, int s, int t) {
	//cout << sum << " " << f << " " << s << " " << t << endl;
	if (c > n) {
		return sum;
	}
	if (a[c][1] == 0 && a[c][2] != 0 && a[c][3] != 0) {
		if (f == n / 2) {
			return max(dfs(c + 1, sum + a[c][2], f, s + 1, t), dfs(c + 1, sum + a[c][3], f, s, t + 1));
		} else if (s == n / 2) {
			return dfs(c + 1, sum + a[c][3], f, s, t + 1);
		} else if (t == n / 2) {
			return dfs(c + 1, sum + a[c][2], f, s + 1, t);
		} else {
			return max(dfs(c + 1, sum + a[c][2], f, s + 1, t), dfs(c + 1, sum + a[c][3], f, s, t + 1));
		}
	}
	if (a[c][2] == 0 && a[c][1] != 0 && a[c][3] != 0) {
		if (f == n / 2) {
			return dfs(c + 1, sum + a[c][3], f, s, t + 1);
		} else if (s == n / 2) {
			return max(dfs(c + 1, sum + a[c][1], f + 1, s, t), dfs(c + 1, sum + a[c][3], f, s, t + 1));
		} else if (t == n / 2) {
			return dfs(c + 1, sum + a[c][1], f + 1, s, t);
		} else {
			return max(dfs(c + 1, sum + a[c][1], f + 1, s, t), dfs(c + 1, sum + a[c][3], f, s, t + 1));
		}
	}
	if (a[c][3] == 0 && a[c][2] != 0 && a[c][1] != 0) {
		if (f == n / 2) {
			return dfs(c + 1, sum + a[c][2], f, s + 1, t);
		} else if (s == n / 2) {
			return dfs(c + 1, sum + a[c][1], f + 1, s, t);
		} else if (t == n / 2) {
			return max(dfs(c + 1, sum + a[c][1], f + 1, s, t), dfs(c + 1, sum + a[c][2], f, s + 1, t));
		} else {
			return max(dfs(c + 1, sum + a[c][1], f + 1, s, t), dfs(c + 1, sum + a[c][2], f, s + 1, t));
		}
	}
	if (f == n / 2) {
		return max(dfs(c + 1, sum + a[c][2], f, s + 1, t), dfs(c + 1, sum + a[c][3], f, s, t + 1));
	} else if (s == n / 2) {
		return max(dfs(c + 1, sum + a[c][1], f + 1, s, t), dfs(c + 1, sum + a[c][3], f, s, t + 1));
	} else if (t == n / 2) {
		return max(dfs(c + 1, sum + a[c][1], f + 1, s, t), dfs(c + 1, sum + a[c][2], f, s + 1, t));
	} else {
		return max(max(dfs(c + 1, sum + a[c][1], f + 1, s, t), dfs(c + 1, sum + a[c][2], f, s + 1, t)), dfs(c + 1,
		           sum + a[c][3], f, s, t + 1));
	}
	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> b;
	for (int z = 0; z < b; z++) {
		cin >> n;
		for (int k = 0; k < n; k++) {
			a[k][0] = 0;
			cin >> a[k][1];
			cin >> a[k][2];
			cin >> a[k][3];
			if (a[k][1] < a[k][2] && a[k][1] < a[k][3]) {
				a[k][1] = 0;
			} else if (a[k][2] < a[k][1] && a[k][2] < a[k][3]) {
				a[k][2] = 0;
			} else if (a[k][3] < a[k][1] && a[k][3] < a[k][2]) {
				a[k][3] = 0;
			}
		}
		g[z] = dfs(0, 0, 0, 0, 0);
		for (int i = 0; i <= 100000; i++) {
			a[i][1] = 0;
			a[i][2] = 0;
			a[i][3] = 0;
		}
	}
	for (int i = 0; i < b; i++) {
		cout << g[i] << endl;
	}
	return 0;
}