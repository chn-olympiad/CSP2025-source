#include <bits/stdc++.h>
#define N 1000006
using namespace std;
const int mod = 998244353;
int fac[N], ifac[N], inv[N];
int C(int n, int m) {
	int cnt = 0, sum = 1;
	for (int i = n; i >= 1; i --) {
		cnt ++;
		sum = (sum * i) % mod; 
		if (cnt == m) {
			break;
		}
	}
	for (int i = 1; i <= m; i ++) {
		if (i > sum) {
			sum += mod;
		}
		sum /= i;
	}	
	return sum;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1, c; i <= n; i ++) {
		cin >> c;
	}
	cout << C(n, m) % mod;
	return 0;
} 
//imjokerQwQ