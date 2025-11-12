#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 998244353;
int n, m;
string s;
int c[510], a[510], ans;
void solve1() {
	for(int i = 1; i <= n; i ++) a[i] = i;
	do {
		int cnt = 0;
		for(int i = 1; i <= n; i ++) {
			int id = a[i];
			if(cnt >= c[id] || s[i] == '0') cnt ++;
		}
		ans += ((n - cnt) >= m);
	}while(next_permutation(a + 1, a + n + 1));
	cout << ans << '\n';
}
int dp[20][1 << 18];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s; s = '?' + s;
	for(int i = 1; i <= n; i ++) cin >> c[i];
	if(n <= 10) solve1();
	else if(n <= 18) {
		dp[0][0] = 1;
		for(int i = 0; i < 1 << n; i ++) {
			int lzt = 0, x = i;
			while(x) {
				lzt += x & 1;
				x >>= 1;
			} 
			for(int j = 1; j <= n; j ++) {
				if(!(i & (1 << (j - 1)))) continue;
				for(int k = 0; k < lzt; k ++) { 
					int add = 1;
					if(lzt - 1 - k >= c[j] || s[lzt] == '0') add = 0;
					dp[k + add][i] = (dp[k + add][i] + dp[k][i ^ (1 << (j - 1))]) % mod;
				}
			}
		}
		for(int i = m; i <= n; i ++) ans = (ans + dp[i][(1 << n) - 1]);
		cout << ans << '\n';
	}
	return 0;
}
//ETOI???