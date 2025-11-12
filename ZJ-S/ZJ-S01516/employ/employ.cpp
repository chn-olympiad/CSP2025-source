#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505;
const int Mod = 998244353;
int n, m, c[N], ans, cnt[N], fac[N], pre[N], f[300000][20];
string s;

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> s; s = " " + s;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	
	if(m == 1){
		fac[0] = 1;
		for(int i = 1; i <= n; i++)
			fac[i] = fac[i - 1] * i % Mod;
		for(int i = 1; i <= n; i++)
			cnt[c[i]]++, pre[c[i]]++;
		for(int i = n; i >= 0; i--)
			cnt[i] = (cnt[i + 1] + cnt[i]) % Mod;
		for(int i = 1; i <= n; i++)
			pre[i] = (pre[i - 1] + pre[i]) % Mod;
		int now = n - 1, p = 1, vis = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '1'){
				ans = (ans + fac[now] * cnt[i] % Mod * p) % Mod;
				now--;
				p = p * max(0ll, pre[i - 1] - vis) % Mod;
				vis++;
			}
		}
		cout << ans << "\n";
		return 0;
	}
	if(n <= 18){
		f[0][0] = 1;
		for(int i = 0; i < (1 << n); i++){
			int len = __builtin_popcount(i);
			for(int k = 0; k <= len; k++){
				int fil = len - k;
				for(int j = 1; j <= n; j++){
					if(((i >> (j - 1)) & 1)) continue;
					if(c[j] > fil && s[len + 1] == '1'){
						f[i ^ (1 << (j - 1))][k + 1] = (f[i ^ (1 << (j - 1))][k + 1] + f[i][k]) % Mod;
					}
					else{
						f[i ^ (1 << (j - 1))][k] = (f[i ^ (1 << (j - 1))][k] + f[i][k]) % Mod;
					}
				}
			}
		}
		for(int i = m; i <= n; i++){
			ans = (ans + f[(1 << n) - 1][i]) % Mod;
		}
		cout << ans << "\n";
		return 0;
	}
	if(m == n){
		for(int i = 1; i <= n; i++) if(s[i] == '0' || c[i] == 0){
			cout << 0 << '\n';
			return 0;
		}
		int ans = 1;
		for(int i = 1; i <= n; i++)
			ans = ans * i % Mod;
		cout << ans << "\n";
		return 0;
	}
	return 0;
}