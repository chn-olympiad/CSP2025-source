#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, res;
string s;
int c[N], book[N];

void dfs(int idx, int acsum, int failsum) {
	if (idx >= n) {
		if (acsum >= m) {
			res++;
			res %= mod;
		}
		return;
	}
	//cout << idx << " " << acsum << " " << failsum << endl;
	if (n - idx + 1 + acsum < m)
		return;
	for (int i = 1; i <= n; ++i) {
		if (book[i])
			continue;
		book[i] = 1;
		if (failsum >= c[i] || s[idx] == '0')
			dfs(idx + 1, acsum, failsum + 1);
		else
			dfs(idx + 1, acsum + 1, failsum);
		book[i] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (n <= 18) {
		for (int i = 1; i <= n; i++) {
			book[i] = 1;
			if (c[i] == 0 || s[0] == '0') {
				dfs(1, 0, 1);
			} else {
				dfs(1, 1, 0);
			}
			book[i] = 0;
		}
		cout << res;
	} else {
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += (c[i] == 0);
		long long res = 1;
		for (int i = 2; i <= n - sum; i++) {
			res = (res * i) % mod;
		}
		cout << res;
	}
	return 0;
}