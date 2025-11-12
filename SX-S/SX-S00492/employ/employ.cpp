#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+10, M = 1e6+10;

int n, m, c[N], arr[N];
ll ans;
string s;
bool vis[N];

void dfs(int step) {
	if (step > n) {
		int out = 0, in = 0;
		for (int i = 1; i <= n; i++) {
			if (in >= m || out > n - m)
				break;
			if (out >= c[arr[i]]) {
				out++;
				continue;
			}
			if (s[i - 1] == '0')
				out++;
			else
				in++;
		}
		if (in >= m)
			ans++;
		ans %= 998244353;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			arr[step] = i;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	dfs(1);
	printf("%lld", ans);
	return 0;
}
