#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define mod 998244353

long long n, m, c[505], ans = 1, a[15];
string s;
bool flag[15];

void dfs(int cur) {
	if (cur == n) {
		int g = 0;
		for (int i = 1; i <= n; i++) {
			if (g >= c[a[i]]) g++;
			else if (s[i - 1] == '0') g++;
		}
		if (n - g >= m) ans++;
	} else {
		for (int i = 1; i <= n; i++) {
			if (!flag[i]) {
				a[cur + 1] = i;
				flag[i] = true;
				dfs(cur + 1);
				flag[i] = false, a[cur + 1] = 0;
			}
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (m == n) { // 4 pts
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				cout << 0;
				return 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) {
				cout << 0;
				return 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			ans = ans * i % mod;
		}
		cout << ans;
		return 0;
	}
	if (n <= 10) { // 8 pts
		dfs(0);
		cout << ans - 1;
	}
	return 0;
}

// 4 + 8 = 12 pts
