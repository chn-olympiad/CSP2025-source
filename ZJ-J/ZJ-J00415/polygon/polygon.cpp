#include <bits/stdc++.h>
using namespace std; 
long long n, f[6000], ans, g[6000]; 
int a[6600]; 
const long long mod = 998244353; 
int main () {
	ios :: sync_with_stdio(0); 
	cin.tie (0); cout.tie(0); 
	freopen("polygon.in", "r", stdin); 
	freopen("polygon.out", "w", stdout); 
	cin >> n; 
	for(int i = 1; i <= n; ++ i) cin >> a[i]; 
	sort(a + 1, a + n + 1); 
	f[0] = 1;
	for(int i = 1; i <= n; ++ i) {
		for(int j = a[i] + 1; j <= 5500; ++ j) ans += f[j], ans %= mod;
		for(int j = 0; j <= 5500; ++ j) {
			g[min(5500, j + a[i])] = f[min(5500, j + a[i])] + f[j], g[min(5500, j + a[i])] %= mod; 
		}
		for(int j = 0; j <= 5500; ++ j) {
			f[min(5500, j + a[i])] = g[min(5500, j + a[i])]; 	
		} 
	}
	cout << ans % mod; 
	return 0; 
}
