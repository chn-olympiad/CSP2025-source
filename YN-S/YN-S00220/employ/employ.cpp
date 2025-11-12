#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0, ans = 0;
char s[2000];
int a[5000];

void dfs(int dep, int wly, int r) {
	if (dep > n) {
		if (r == m) {
			cnt++;
		}
	} else {
		if (s[dep] == '0') {
			dfs(dep + 1, wly + 1, r);
		} else {
			if (a[dep] >= wly) {
				dfs(dep + 1, wly, r + 1);
			}
		}
	}

}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(1, 0, 0);
		swap(a[i], a[i + 1]);
	}
	cout << cnt - 1;
	return 0;
}