#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5010, mod = 998244353, M =100010;
int n, a[N];
void pts40()
{
	int ans = 0;
	for(int i = 0; i < n; i ++) a[i] = a[i + 1];
	for(int s = 0; s < (1 << n); s ++)
	{
		int mv = 0, sum = 0;
		for(int i = 0; i < n; i ++)
			if((s >> i) & 1) mv = max(mv, a[i]), sum += a[i];
		if(sum > 2 * mv) ans ++;
		if(ans > mod) ans -= mod;
	}
	cout << ans << "\n";
}
int qpow(int a, int k)
{
	int ans = 1;
	while(k)
	{
		if(k & 1) ans = ans * a % mod;
		k >>= 1, a = a * a % mod;
	}
	return ans;
}
int fac[M], inv[M];
int C(int x, int y)
{
	return fac[x] /fac[y] /fac[x-y];
//	return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
void init_fac()
{
	fac[1] = 1;
	for(int i = 2; i < M ; i ++) fac[i] = fac[i - 1] * i % mod;
	inv[M - 1] = qpow(fac[M - 1], mod - 2);
	for(int i = M - 2; i >= 1; i --) inv[i] = inv[i + 1] * i % mod;
}
void pts32()
{
	init_fac();
	int ans = 0;
	for(int i = 3; i <= n; i ++)
		(ans += C(n, i)) %= mod;
	cout << ans << "\n";
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(n <= 20) pts40();
	else pts32();
	return 0;
}
