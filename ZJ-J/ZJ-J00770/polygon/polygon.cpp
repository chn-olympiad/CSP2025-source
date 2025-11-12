#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 998244353;
int n, mx;
int a[5010];
int sum[5010];
long long f[5010];
long long sf[5010];
long long ans[5010];
long long qpow(long long a, long long b) {
	long long c = 1;
	while(b) {
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}
int cnt[5010];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(n <= 20) {
		int lxt = 0;
		for(int i = 0; i < (1 << n); i ++) {
			int x = i, cnt = 0;
			while(x) {
				cnt += (x & 1);
				x >>= 1;
			}
			if(cnt < 3) continue;
			int sum = 0, maxn = 0;
			for(int j = 1; j <= n; j ++) {
				if((1 << j - 1) & i) sum += a[j], maxn = max(maxn, a[j]);
			}
			if(sum > maxn * 2) lxt ++;
		}
		cout << lxt << '\n';
		return 0;
	}
	for(int i = 1; i <= n; i ++) cnt[a[i]] ++;
	for(int i = 1; i <= n; i ++) mx = max(mx, a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
	f[0] = 1; 
	for(int i = 1; i <= n; i ++) 
		for(int j = min(mx, sum[i]); j >= a[i]; j --) {
			f[j] = (f[j] + f[j - a[i]]) % mod;
		}
	for(int i = 1; i <= mx; i ++) sf[i] = (sf[i - 1] + f[i]) % mod;
	for(int i = 1; i <= n; i ++)
		ans[i] = (qpow(2, i - 1) - sf[a[i]] + mod) % mod;
	long long s = 0;
	for(int i = 1; i <= n; i ++) 
		s = (s + ans[i]) % mod;
	for(int i = 1; i <= n; i ++) 
		if(a[i] != a[i + 1]) if(cnt[a[i]] > 1) s = (s + cnt[a[i]] * (cnt[a[i]] - 1) / 2 % mod) % mod;
	cout << s % mod << '\n';
	return 0;
}