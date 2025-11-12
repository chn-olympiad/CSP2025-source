#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int h[100010][5];
int o = 0;
int jp[100010];
int s[5];

void dfs(int c, int m) {
	if (c == n + 1) {
		o = max(o, m);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n; j++) {
			if (jp[j] == 0 && s[i] + 1 <= n / 2) {
				jp[j] = 1;
				s[i]++;
				dfs(c + 1, m + h[j][i]);
				jp[j] = 0;
				s[i]--;
			}
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			for (int l = 1; l <= 3; l++) {
				cin >> h[j][l];
			}
		}
		o = 0;
		dfs(1, 0);
		cout << o << endl;
	}
}