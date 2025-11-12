#include <bits/stdc++.h>
#define maxn 5005
#define maxm 5005
using namespace std;
int n, m, ans, t[maxn];
int c[maxn];
bool s[maxn], vis[maxn];
string a;

void dfs(int u, int nai, int day) {
	if (c[u] <= nai)
		return;
	if (day == n) {
		ans++;
		return;
	}
	if (!s[day]) {
		dfs(u, nai + 1, day + 1);
		return;
	}
	vis[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		dfs(i, nai, day + 1);
	}
	vis[u] = 0;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '1')
			s[i + 1] = 1;
		else
			s[i + 1] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		t[c[i]]++;
	}
	for (int i = 1; i <= n; i++)
		dfs(i, 0, 1);
	cout << ans % 998244353;
	return 0;
}
