#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+5, mod = 998244353; 
int n, ans, a[N], _s[N], _mx[N];
int dfs(int i, int k, int mx, int sum){
	if (i > n) return (k >= 3 && sum > mx*2);
	if (sum+_s[i] <= _mx[i]) return 0;
	return (dfs(i+1,k,mx,sum)+dfs(i+1,k+1,max(a[i],mx),sum+a[i])) % mod;
}
signed main(){
	freopen("polygon.in", "r", stdin); freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) _s[i] = _s[i+1]+a[i+1], _mx[i] = max(_mx[i+1], a[i+1]);
	if (_mx[1] <= 1){
		int ans = 0;
		for (int i = 3; i <= n; i++){
			__int128 res_x = 1, res_y = 1;
			for (int x = n; x != i; x--)
				res_x *= x, res_y *= (n-x+1);
			(ans += res_x/res_y) %= mod;
		}
		cout << ans;
		return 0;
	}
	cout << dfs(1, 0, 0, 0);
	return 0;
}
