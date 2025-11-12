#include<bits/stdc++.h>
#define int long long
using namespace std;
const int lim = 5500;
const int N = lim + 10;
const int mod = 998244353;
int n, a[N], f[N];
inline void insert(int x) {
	for(int i = lim;i >= 0;i --){
		int to = min(lim, i + x);
		f[to] += f[i];
		f[to] = f[to] >= mod ? f[to] - mod : f[to];
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++)cin >> a[i];
	sort(a + 1, a + n + 1);
	f[0] = 1;
	int ans = 0;
	for(int i = 2;i <= n;i ++){
		insert(a[i - 1]);
		for(int j = a[i] + 1; j <= lim;j ++)ans += f[j];
		ans %= mod;
	}
	cout << ans;
	return 0;
}
