#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N][50], b[50];
int q[N][50];
int f[N];
int n, k;
bool check (int l, int r) {
	for (int i = 1; i <= 30; i ++ ) {
		if (((q[r][i] - q[l - 1][i]) % 2) != b[i]) return 0;
	}
	return 1;
}
signed main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i ++ ) {
		int t; cin >> t;
		int cnt = 0;
		while (t > 0) {
			a[i][++cnt] = t & 1;
			t /= 2;
		}
	} 
	int tot = 0;
	while (k > 0) {
		b[++tot] = k & 1;
		k /= 2;
	}
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= 30; j ++ ) {
			q[i][j] = q[i - 1][j] + a[i][j];
		}
	}
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= i; j ++ ) {
			if (check(j, i)) 	f[i] = max (f[i], f[j - 1] + 1);
			else 			 	f[i] = max (f[i], f[j - 1]);
		}
	}
	cout << f[n];
} 
