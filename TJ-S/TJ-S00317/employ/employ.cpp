#include<bits/stdc++.h>
using namespace std;

namespace z {
	
const int N = 5e5 + 5, mod = 998244353;
#define int long long
int c[N], n, m;
string s;
int f[1 << 19][19];
int fac[N];
void add(int &x, int y) {
	x += y;
	if(x >= mod) x-= mod;
}
void sol1() {
	
	f[0][0] = 1;
	for(int mask = 0; mask < (1 << n); mask++) {
		for(int i = 0; i < n; i++) {
			int cnt = __builtin_popcount(mask);
			if(i > cnt) continue;
			int no = cnt - i;
			for(int j = 0; j < n; j++) {
				if(!(mask >> j & 1)) {
					int x = (no < c[j] && s[cnt] == '1');
					add(f[mask ^(1 << j)][i + x], f[mask][i]);
				} 
			}
		}
	}
	int ans = 0;
	for(int i = m; i <= n; i++) add(ans, f[(1 << n) - 1][i]);
	cout << ans << '\n';
}
void main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < n; i++) cin >> c[i];
	if(n <= 18) sol1();
	else if(n == m) {
		bool flg = 1;
		for(int i = 0; i < n; i++)
			flg &= s[i] == '1';
		for(int i = 0; i < n; i++)
			flg &= c[i] > 0;
		fac[0] = 1; 
		for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
		cout << flg * fac[n] << '\n';
	}
}
	
#undef int
	
} 

int main() {
	z::main();
	return 0;
}
