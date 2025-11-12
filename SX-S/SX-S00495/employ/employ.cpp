#include <bits/stdc++.h>
using namespace std;
int n, m, a[505], ans = 0, myans = 0, sum = 0, aa[505];
bool vis[505];
string s;

void dfs(int step) {
	for (int i = aa[step - 1] + 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			aa[step] = i;
			if (step == n) {
				ans = 0, sum = 0;
				for (int j = 1; j <= step; j++) {
					if (s[j] == '1' && sum <= a[aa[j]]) {
						ans++;
					} else {
						sum++;
					}
				}
				if (ans == m) {
					myans += 2;
				}
			} else
				dfs(step + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << myans;
	return 0;
}