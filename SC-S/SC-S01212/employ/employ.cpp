#include <algorithm>
#include <iostream>
using namespace std;
const int N = 505;
const long long mod = 998244353;
int n, m, minn = 2, zer;
int c[N], cho[N], vis[N];
long long ans;
string dif;
bool check() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (dif[i] == '0' || cho[i + 1] <= cnt)
			cnt++;
		if (m == 1 && i + 1 - cnt >= 1)
			return true;
		if (m == n && cnt)
			return false;
	}
	return (n - cnt) >= m;
}
void dfs(int pos) {
	if (pos > n) {
		if (check()) ans = (ans + 1) % mod;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		cho[pos] = c[i];
		dfs(pos + 1);
		vis[i] = 0;
		cho[pos] = 0;
	}
}
void jc(int x) {
	ans = 1;
	for (int i = 1; i <= x; i++) 
		ans = ans * i % mod;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> dif;
	for (int i = 0; i < n; i++)
		minn = min(minn, dif[i] - '0');
	for (int i = 1; i <= n; i++) 
		scanf("%d", &c[i]), zer += (c[i] == 0);
	if (minn == 1) jc(n - zer);
	else dfs(1);
	printf("%lld", ans);
	return 0;
} 
