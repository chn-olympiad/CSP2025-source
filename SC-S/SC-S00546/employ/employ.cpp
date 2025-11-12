#include<bits/stdc++.h>
using namespace std;

const int N = 510;
const int Mod = 998244353;

int n, m, k, c[N], ans;
char s[N];
bool vis[N];
int tmp[N];

bool check() {
	int now = 0, res = 0;
	for(int i = 1; i <= k; i++) {
		if(now >= c[tmp[i]] || s[i] == '0') {
			now++;
		}
		else res++;
	}
	return res >= m;
}
void dfs(int x, int loss) {
	if(loss > n - m) return ;
	if(x == n + 1) {
		if(check()) {
			ans = (ans + 1) % Mod;
		}
		return ;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = true;
		tmp[++k] = i;
		dfs(x + 1, loss + bool(s[x] == '0' || loss >= c[tmp[x]]));
		--k;
		vis[i] = false;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	dfs(1, 0);
	cout << ans;
	return 0;
}