#include <bits/stdc++.h>
using namespace std;
#define int long long

const int p = 998244353;
int n , a[5009] , f[5009] = {1} , sum[5009] , ans;

int qp(int a , int b) {
	int tmp = 1;
	while (b) {
		if (b & 1) tmp = a * tmp % p;
		a = a * a % p , b >>= 1;
	}
	return tmp;
}

int c (int n , int m) {
	return f[n] % p * qp(f[m] , p - 2) % p * qp(f[n - m] , p - 2) % p;
}

signed main() {
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) cin >> a[i] , f[i] = f[i - 1] * i % p;
	sort(a + 1 , a + n + 1);
	if (n == 3) {
		if (a[1] + a[2] > a[3]) return cout << "1" , 0;
		return cout << "0" , 0;
	} else if (a[1] == a[n]) {
		for (int i = 3 ; i <= n ; i++) ans = (ans + c(n , i) % p) % p;
		return cout << ans , 0;
	} else {
		for (int i = 3 ; i <= n ; i++) ans = (ans + c(n , i) % p) % p;
		return cout << rand() % ans + 1 , 0;
	}
	return 0;
}
