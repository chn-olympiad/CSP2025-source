#include <bits/stdc++.h>
using namespace std;
long long ans;
int n, m;
int a[20], use[20];
string s;

void dfs(int ceng, int fa) {
	if (ceng > n) {
		if (fa <= m) {
			ans++;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (use[i] == 0) {
			use[i] = 1;
			if (fa >= a[i] || s[ceng - 1] == '0') {
				dfs(ceng + 1, fa + 1);
			} else {
				dfs(ceng + 1, fa);
			}
			use[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}