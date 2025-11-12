#include<bits/stdc++.h> 
using namespace std;
int fac[500],  inv[502];
const int mod = 998244353;
int n, m, ans;
int yzy(int a, int b) {
	int res = 1;
	while(b) {
		if (b &1) {
			res = res*a% mod;
			a = a * a % mod;
			b>>=1;
		}
		return res;
	}	
}
int A(int n, int m) {
	return fac[n] * inv[n - m] % mod;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	fac[0] = inv[0] = 1;
	cin >> n >> m; 
	for (int i = 1;i <= n;i++){
		fac[i] = fac[i - 1] * i %mod;
		inv[i] = yzy(fac[i], mod - 2)%mod;
	}
	string s;
	cin >> s;
	for (int i = 1;i <= n;i++) {
		int a;
		cin >> a;
	}
	for (int i = m;i <= n;i++)
		ans = (ans + A(i, n) % mod) %mod;
	cout << ans % mod;
	return 0;
}
