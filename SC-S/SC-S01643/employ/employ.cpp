//dzzfjldyqqwsxdhrdhcyxll
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 10;
const int mod = 998244353;
int n,m,a[MAXN],dp[MAXN][20],p[MAXN],cnt,b[MAXN],f[1000][1000];
int inv[MAXN],fac[MAXN],invfac[MAXN];
string s;
bool cmp(int x,int y) {
	return __builtin_popcount(x) < __builtin_popcount(y);
} 
inline int C(int n,int m) {
	if(m == 0) return 1;
	if(n < 0 || n < m) return 0;
	return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	inv[0] = fac[0] = invfac[0] = 1;
	inv[1] = fac[1] = invfac[1] = 1;
	for(int i = 2;i <= 1000;i++) {
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		fac[i] = fac[i - 1] * i % mod;
		invfac[i] = invfac[i - 1] * inv[i] % mod;
	}
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++) cin >> a[i],b[a[i]]++;
	if(n <= 18) {
		dp[0][0] = 1;
		for(int i = 0;i < (1ll << n) - 1;i++) {
			p[++cnt] = i;
		}
//		sort(p + 1,p + cnt + 1,cmp);
		for(int ag = 0;ag < (1ll << n) - 1;ag++) {
			int i = p[ag + 1];
			int g = __builtin_popcount(i);
			for(int j = 0;j <= g;j++) {
				for(int k = 1;k <= n;k++) {
					if((i >> (k - 1)) & 1) continue;
					int S = i | (1ll << (k - 1));
					dp[S][j + (s[g] == '1' && g - j < a[k])] += dp[i][j];
					dp[S][j + (s[g] == '1' && g - j < a[k])] %= mod;
				}
			}
		}
		int sum = 0;
		for(int i = m;i <= n;i++) sum = (sum + dp[(1ll << n) - 1][i]) % mod;
		cout << sum % mod;	
	} else {
		f[n + 1][0] = 1;
		int ss = 0;
		for(int i = n;i >= 1;i--) {
			for(int j = 0;j <= ss + b[i];j++) {
				for(int k = 0;k <= b[i];k++) {
					f[i][j] += f[i + 1][j - k] * C((n - j - 1),b[i] - k);
					f[i][j] %= mod;
				}
			}
			ss += b[i];
		}
		int sum = 0;
		if(m < b[0]) {
			cout << 0;
			return 0;
		}
		for(int i = m;i <= n;i++) {
			sum = (sum + f[1][m - b[0]]) % mod;
		}
		cout << sum;
	}
	return 0;
}