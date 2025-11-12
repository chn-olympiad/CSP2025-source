#include <bits/stdc++.h>
using namespace std;
const int N = 550, mod = 998244353;
string stg;
int a[N], c[N];
long long D[N][N], C[N][N];
long long dc (int x, int y) {
	if (y == 1) return C[x][y] = x;
	if (C[x][y] > 0) return C[x][y];
	return C[x][y] = (dc (x - 1, y - 1) * x / y) % mod;
}
long long dd (int x, int y) {
	if (y == 0) return D[x][y] = 1;
	if (x == 1) return D[x][y] = 1;
	if (D[x][y] > 0) return D[x][y];
	long long s = 0;
	for (int i = 0; i < y; i ++) {
		s += dc (x, y - i) * dd (y - i, i);
		s %= mod;
	}
	return D[x][y] = s;
}
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> stg;
	int sum = 0, csm = 0;
	for (int i = 0; i < n; i ++ ) {
		a[i] = stg[i] - '0';
		a[i] = 1 - a[i];
		sum += a[i];
	}
	for (int i = 0; i < n; i ++ ) {
		cin >> c[i];
		if (c[i] > 0) csm ++ ;
	}
	if (csm < m) {
			cout << 0;
			return 0;
		}
	if (sum == 0) {
		
		long long s = 1;
		for (int i = 1; i <= csm; i ++ ) {
			s *= i;
			s %= mod;
		}
		int nn = csm + 1, x = n - csm;
		s *= dd (nn, x);
		s %= mod;
		for (int i = 1; i <= x; i ++ ) {
			s *= i;
			s %= mod;
		}
		cout << s;
	}
	else {
		cout << 0;
	}
	return 0;
}
