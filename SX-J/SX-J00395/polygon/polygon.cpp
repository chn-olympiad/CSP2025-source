#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, cnt;
int num[100005];
int vis[100005];

void dfs(int step, int start, int sum) {
	if (sum > vis[step - 1] * 2 && step - 1 >= 3) {
		cnt++;
	}
	for (int i = start; i <= n; i++) {
		vis[step] = num[i];
		dfs(step + 1, i + 1, sum + num[i]);
	}
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool f = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		if (num[i] != 1)
			f = 1;
	}
	int s = 0;
	if (f == 0) {
		for (int i = 3; i <= n; i++) {
			if (n % i == 0)
				s += n / i;
		}
		cout << s;
		return 0;
	}
	sort(num + 1, num + n + 1);
	dfs(1, 1, 0);
	cout << cnt % 998244353;
	return 0;
}
