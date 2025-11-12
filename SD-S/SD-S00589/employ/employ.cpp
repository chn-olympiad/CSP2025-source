#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int N = 5e2 +10;
const ull MOD = 998244353;

char s[N];
ull n, m, c[N];
ull ans, vis[N];
vector<int> index;

void dfs(int dep) {
	if (dep == n) {
		int d = 0, cnt = 0;
		for (int i = 0; i < index.size(); i++) {
			int idx = index[i];
			if (s[i + 1] == '0') {
				d++;
			} else if (d >= c[idx]) {
				d++;
			} else {
				cnt++;
			}
		}
		if (cnt >= m) ans = (ans + 1) % MOD;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			index.push_back(i);
			dfs(dep + 1);
			vis[i] = 0;
			index.pop_back();
		}
	}
}
int main() {
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	
	dfs(0);
	
	cout << ans << endl;
	
	return 0;
} 
