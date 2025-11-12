#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 510;

int n, m;
int c[N];
bool st[N];
LL ans;
string dif;

void dfs(int u, int cnt) {
	if (u == n + 1 && n - cnt >= m) {
		ans++;
		return;
	}
	if (m + cnt > n)
		return;
	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			st[i] = 1;
			if (c[i] <= cnt)
				dfs(u + 1, cnt + 1);
			else
				dfs(u + 1, cnt + (dif[u - 1] == '0' ? 1 : 0));
			st[i] = 0;
		}
	}
	return;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> dif;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (n <= 10) {
		dfs(1, 0);
		cout << ans;
	} else if (n == m) {
		for (auto i : dif)
			if (i == '0') {
				cout << 0;
				return 0;
			}
		for (int i = 1; i <= n; i++)
			if (c[i] == 0) {
				cout << 0;
				return 0;
			}
	}
	return 0;
}