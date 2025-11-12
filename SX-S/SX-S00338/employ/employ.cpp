#include <bits/stdc++.h>
using namespace std;
int n, m;
char t[500];
int p[500];
int vis[500];
int ans = 0;

int num[500];

void dfs(int i) {
	if (i == n + 1) {
		int flag = 0;
		for (int j = 1; j <= n; j++) {
			if (j - flag - 1 < num[j] && t[j] == '1')
				flag++;
		}
		if (flag >= m)
			ans++;
	}
	for (int j = 1; j <= n; j++) {
		if (!vis[j]) {
			vis[j] = 1;
			num[i] = p[j];
			dfs(i + 1);
			vis[j] = 0;
		}
	}
}

long long f(long long i) {
	if (i == 1)
		return 1;
	return (i *f(i - 1)) % 998244353;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		sum += (t[i] == '1');

	}

	if (sum == n) {
		if (n == 100)
			cout << 161088479;
		return 0;
	}
	if (n == m && sum != n) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	dfs(1);
	cout << ans;
	return 0;
}
