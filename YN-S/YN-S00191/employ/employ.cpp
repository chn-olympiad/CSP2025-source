#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n, m, a[N], sum;
string s;

void dfs(int dep, int p) {
	if (dep > n) {
		if (p >= m) {
			sum++;
		}
	} else {
		dfs(dep + 1, p + 1);
		dfs(dep + 1, p);
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	int sz = s.size();

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	int cnt = 0;

	for (int i = 0; i < sz; i++) {

		if (s[i] == '0') {
			cnt++;
		}
	}

	for (int i = cnt + 1; i <= n; i++) {

		dfs(cnt + 1, 0);
	}

	cout << sum;
	return 0;
}
