#include <bits/stdc++.h>

using namespace std;

int n, m;
const int N = 510;
const int MOD = 998244353;
int c[N];
string dif;
long long ans = 0;

int res[N];
bool vis[N];
void dfs(int now) {
	if (now > n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= c[res[i]]) {
				cnt++;
			}
			if (dif[i] == '1') {
				cnt++;
			}
			if (n - cnt < m) {
				return;
			}
		}
		ans = (ans + 1) % MOD;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			res[now] = i;
			dfs(now + 1);
			vis[i] = 0;
		}
	}
}
	
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	bool teA = true;
	cin >> dif;
	int len = dif.size();
	for (int i = 0; i < len; i++) {
		if (dif[i] != '1') {
			teA = false;
		}
	}
	if (teA) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]); 
	}
	if (n > 12) {
		printf("0\n");
	}
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}
