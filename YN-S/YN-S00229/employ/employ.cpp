#include <bits/stdc++.h>
using namespace std;
long long a[1005], b[1005], n, m, ans, c[505];
string s;

void dfs(int w) {
	if (w == n + 1) {
		int fq = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (c[a[i + 1]] <= fq || s[i] == '0') {
				fq++;
			} else {
				cnt++;
			}
		}
		if (cnt >= m) {
			ans++;
		}
		return;
	} else {
		for (int i = 1; i <= n; i++) {
			if (b[i] == 0) {
				a[w] = i;
				b[i] = 1;
				dfs(w + 1);
				b[i] = 0;
			}
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int cnt = n;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
