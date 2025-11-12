#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();
	int x = 0, f = 1;
	while(c < '0' || c > '9') {
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
bool bit_read() {
	char c = getchar();
	while(c < '0' || c > '9')c = getchar();
	return c == '1';
}
void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	} if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
}
const int N = 510, INF = 0x3f3f3f3f, MOD = 998244353;
int n, m, s[N], flag, ans = 1, c[N], cnt[N], sum = 1, dp[(1 << 18)][19];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	for(int i = 0; i < n; i++) {
		s[i] = bit_read();
		if(!s[i])flag++;
	}
	for(int i = 0; i < n; i++) {
		c[i] = read();
		cnt[c[i]]++;
	}
	sort(c, c + n);
	if(!flag) {
		if(n - cnt[0] < m)write(0);
		else {
			for(int i = 1; i <= n; i++)ans = (1ll * ans * i) % MOD;
			write(ans);
		}
	} else if(m == n)write(0);
	else if(n <= 18){
		dp[0][0] = 1;
		for(int st = 0; st < (1 << n) - 1; st++) {
			int j = 0;
			for(int i = 0; i < n; i++)if((1 << i) & st)j++;
			for(int i = 0; i <= n - m; i++) {
				if(!dp[st][i])continue;
				for(int l = 0; l < n; l++) {
					if((1 << l) & st)continue;
					int gi = (c[l] <= i || !s[j]);
					dp[st | (1 << l)][i + gi] += dp[st][i];
					if(dp[st | (1 << l)][i + gi] >= MOD)dp[st | (1 << l)][i + gi] -= MOD;
				}
			}
		}
		ans = 0;
		for(int i = 0; i <= n - m; i++) {
			ans += dp[(1 << n) - 1][i];
			if(ans >= MOD)ans -= MOD;
		}
		write(ans);
	} else {
		int cntnow = 0;
		for(int i = 0; i < n; i++) {
			cntnow += cnt[i];
			if(s[i]) {
				sum = (1ll * sum * cntnow) % MOD;
				cntnow--;
			}
		}
		for(int i = 1; i <= flag; i++)sum = (1ll * sum * i) % MOD;
		for(int i = 1; i <= n; i++)ans = (1ll * ans * i) % MOD;
		ans -= sum;
		if(ans < 0)ans += MOD;
		write(ans);
	}
	return 0;
}