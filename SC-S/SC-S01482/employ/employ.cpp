#include <bits/stdc++.h>
#define int long long
#define ls p * 2
#define rs p * 2 + 1
#define mid ((l + r) / 2)
#define lson ls, l, mid
#define rson rs mid + 1, r
using namespace std;
const int N = 500 + 10, mod = 998244353;
int n, m, ans, vis[N];
int c[N], frac[N], cnt;
string s;

void dfs(int pos, int gp, int tot) {
	if(pos > n) {
		if(tot >= m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		dfs(pos + 1, gp + (c[i] <= gp || s[pos] == '0'), tot + (c[i] > gp and s[pos] == '1'));
		vis[i] = 0;
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	frac[0] = 1;
	for(int i= 1;i <= n;i++) {
		frac[i] = frac[i - 1] * i % mod;
	}
	cin >> s;
	s = ' ' + s;
	for(int i = 1;i <= n;i++) cin >> c[i];
	sort(c + 1, c + n + 1);
	int flag = 0;
	for(int i = 1;i <= n;i++) {
		if(s[i] == '0') {
			flag = 1;
			break;
		}
	}
	if(m == n) {
		if(flag) {
			cout << 0;
			return 0;
		} else {
			cout << 1;
			return 0;
		}
	}
	
	return 0;
}