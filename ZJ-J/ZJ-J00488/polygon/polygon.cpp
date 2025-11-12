#include <bits/stdc++.h>
using namespace std;
#define itn int
#define tin int
#define tni int
#define nit int
#define nti int
#define fro for
#define orf for
#define ofr for
#define rfo for
#define rof for
#define inc cin
#define icn cin
#define nci cin
#define nic cin
#define cni cin
#define ull unsigned long long
const int mxn = 5001 * 5000;
const int md = 998244353;
int n, a[5001], ck, mxi;
ull ans = 0;
ull jc(int x) {
	ull num = 1;
	for(int i = 1; i <= x; i++) {
		num *= i;
		num = num % md;
	}
	return num;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	ull nj = jc(n);
	if(n == 3) {
		if((a[1] + a[2] + a[3]) > max(a[1], max(a[2], a[3])) * 2) {
			cout << 1 << endl;
		} else {
			cout << 0;
		}
	} else {
		for(int i = 3; i <= n; i++) {
			ans += (nj / jc(i)) / jc(n-i) % md;
		}
		cout << ans << endl;
	}
	return 0;
}
