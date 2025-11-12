#include <bits/stdc++.h>
using namespace std;
string s;
int n, m;
int a[501];

bool vis[501] = {0};
int ans[501];
long long sum;
void dfs(int dep) {
	if (dep == n + 1) {
		int p1 = 0;
		for (int i = 1; i < dep; i++) {
			if (s[ans[i] - 1] == '0' || p1 >= a[ans[i]]) {
				p1++;
			}
		}
		if (n - p1 >= m) {
			sum++;
			sum %= 998244353;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			ans[dep] = i;
			dfs(dep + 1);
			vis[i] = 0;
		}
	}

}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	dfs(1);
	cout << sum - 1;
	return 0;
}
