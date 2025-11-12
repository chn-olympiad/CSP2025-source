#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 18;
int f[1 << 19][N];
int lowbit(int x) {
	return x & -x;
}
int cntx(int x) {
	int res = 0;
	while (x) {
		x -= lowbit(x);
		res ++;
	}
	return res;
}
char x[21];
const int mod = 998244353;
int a[N];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int m, n; cin >> n >> m;
	cin >> x + 1;
	for (int i = 1 ; i <= n ; i ++) cin >> a[i], a[i] --;
	f[0][0] = 1;
	for (int S = 1 ; S < (1 << n) ; S ++) {
		int A = cntx(S);
		if (x[A] == '0') {
			for (int j = 1 ; j <= n ; j ++)
				if ((1 << (j - 1)) & S) {
					for (int k = 1 ; k <= A ; k ++) {
						f[S][k] += f[S - (1 << (j - 1))][k - 1];
						f[S][k] %= mod;
					}
				}
		} else {
			for (int j = 1 ; j <= n ; j ++) {
				if ((1 << (j - 1)) & S) {
					for (int k = 0 ; k <= a[j] ; k ++) {
						f[S][k] += f[S - (1 << (j - 1))][k];
						f[S][k] %= mod;
					}
					for (int k = a[j] + 1 ; k < A ; k ++) {
						f[S][k + 1] += f[S - (1 << (j - 1))][k];
						f[S][k + 1] %= mod; 
					}
				}
			}
		}
	}
//	for (int i = 0 ; i < (1 << n) ; i ++, cout << '\n')
//		for (int j = 0 ; j <= n ; j ++)
//			cout << '(' << i << ' ' << j << ' ' << f[i][j] << ')' << ' ';
	int ans = 0;
	for (int i = 0 ; i <= n - m ; i ++)
		ans += f[(1 << n) - 1][i], ans %= mod;
	cout << ans;
	return 0;
}