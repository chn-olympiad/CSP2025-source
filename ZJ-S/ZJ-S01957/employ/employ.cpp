#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505;
const int mod = 998244353;
int n, m, c[N], pa[N];
char s[N];
bool flag[N];
ll f[N], ans;
void dfs(int dep) {
	if(dep == n + 1) {
		int fail = 0, scc = 0;
		for(int i = 1;i <= n;i++) {
			if(s[i] == '0' || fail >= c[pa[i]]) fail++;
			else scc++;
		}
		if(scc >= m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++) {
		if(!flag[i]) {
			flag[i] = true;
			pa[dep] = i;
			dfs(dep + 1);
			flag[i] = false;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	f[0] = 1;
	for(int i = 1;i <= n;i++) {
		f[i] = f[i - 1] * i % mod;
	}
	for(int i = 1;i <= n;i++) {
		scanf("%d", &c[i]);
	}
	if(n <= 18) {
		dfs(1);
		printf("%lld\n", ans);
	} else if(n == m) {
		bool b = true;
		for(int i = 1;i <= n;i++) {
			if(s[i] == '0' || c[i] == 0) b = false;
		}
		if(b) printf("%lld\n", f[n]);
		else printf("0\n");
	} else if(m == 1) {
		int pos = 0;
		for(int i = 1;i <= n;i++) {
			if(pos == 0 && s[i] == '1') pos = i;
		}
		ll pre = 1, ff = 1;
		for(int i = pos;i <= n;i++) {
			if(s[i] == '0') continue;
			int cnt = 0;
			for(int j = 1;j <= n;j++) {
				if(c[j] <= i - 1) cnt++;
			}
			ans = (ans + f[n - pre] * ff % mod * (n - cnt)) % mod;
			if(cnt >= pre) ff = ff * (cnt - pre + 1) % mod;
			else break;
			pre++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
